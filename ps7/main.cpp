// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <boost/regex.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(int argc, const char* argv[]) {
    // const values for start of server and end of server within the log files
    // "\\" included in the string b/c it couldnt find it as (log.c.166).
    const boost::regex bootStart("\\(log\\.c\\.166\\) server started");
    const boost::regex bootEnd
                   ("oejs\\.AbstractConnector:Started SelectChannelConnector");

    // if only the executable is put in the command line
    if (argc <= 1) {
        std::cout << "ERROR: No file was passed into the program" << std::endl;
        return -1;
    }

    // if more than the executable and a file are passed in
    if (argc > 2) {
        std::cout << "ERROR: Too many arguments in command line" << std::endl;
        return -1;
    }

    std::string filePath(argv[1]);  // string for name of filePath
    std::ifstream logPath(filePath);  // file in from the filepath
    std::ofstream outputFile(filePath + ".rpt");  // output file
    std::stringstream rpt;

    // check to see the file status
    if (logPath.is_open() == false) {
        std::cout << "ERROR: The requested file cannot be opened: "
                  << filePath << std::endl;
        return -1;
    }

    bool bootSeq = false;
    std::string currline;
    int lineNum = 1;
    int bootSuccessCount = 0;
    int bootFailCount = 0;

    /****************************************************************
    convienent lambda function that will be usefull later to get the
    timestamps of the date and time accessed in kronos since they
    show up in the same position, i.e. at the beginning of a line
    ****************************************************************/
    auto extractTimeStamp = [](std::string str) {
        return str.substr(0, 19);
    };

    boost::posix_time::ptime start, end;

    while (std::getline(logPath, currline)) {  // while getline...
        // if it finds the conditions for a boot start in the current line...
        if (boost::regex_search(currline, bootStart)) {
            start = boost::posix_time::time_from_string
                    (extractTimeStamp(currline));  // get timestamp from lambda
            // if the system is in a boot sequence, result is an incomplete boot
            if (bootSeq == true) {
                rpt << "**** INCOMPLETE BOOT ****\n\n";
                ++bootFailCount;  // inc bootFail
            }
            bootSeq = true;  // sets boot sequence flag to in boot
            // otherwise: record boot sequence in the log report
            rpt << "=== DEVICE BOOT ===\n"
                << lineNum << "(" << filePath << ")"
                << start << " BOOT START\n";
        }

        // if it finds the conditions for a boot end in the current line...
        if (boost::regex_search(currline, bootEnd)) {
            end = boost::posix_time::time_from_string
                  (extractTimeStamp(currline));  // get timestamp from lambda
            bootSeq = false;  // sets bootSeq flag to not in boot
            // gets total elapsed time by taking end - start
            boost::posix_time::time_duration elapsedTime = end - start;
            ++bootSuccessCount;  // inc bootSuccess
            // record everything in the report log
            rpt << lineNum << "(" << filePath << ")"
                << end << " BOOT COMPLETE\n\tBOOT TIME: "
                << elapsedTime.total_milliseconds() << "ms\n\n";
        }
        lineNum++;  // inc lineNum
    }

    // variable for total amount of boot sequences
    int totalBoots = (bootSuccessCount + bootFailCount);

    // finally record everything to the output file along with the report data
    outputFile << "DEVICE BOOT REPORT\n\n" << "InTouch log file: " << filePath
               << "\n" << "LINE SCANNED: " << lineNum << "\n\n"
               << "DEVICE BOOT COUNT: INITIATED = " << totalBoots
               << ", COMPLETED = " << bootSuccessCount << "\n\n\n"
               << rpt.rdbuf();

    // closing the files
    outputFile.close();
    logPath.close();

    return 0;
}
