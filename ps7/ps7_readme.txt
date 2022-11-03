/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/
Name: Erik van Tilborg
Hours to complete assignment (optional): ~3-4
/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

i completed the whole assignment. i know that i successfully completed the
assignment because i am getting correct outputs based off the examples 
provided in the assignment pdf and on blackboard. this leads me to believe 
that all aspects of my program are working as intended. the time stamps 
match those in the log files as well as the line numbers for boot on and 
boot off.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/

the regex's that i used were as follows:
if (boost::regex_search(currline, bootStart))...
and:
if (boost::regex_search(currline, bootEnd))...

the first one checks to see if there is a bootStart condition in the current
line of the log file. if there is, that is set to true and it goes about 
the necessary steps to add elements to the report file if it is not already in
a boot sequence. the second one is does the same thing as the first initially, 
checking for a bootEnd string instead of start. after this it will get the 
elapsed time of how long it took increment success count and add the bootEnd
elements to the report file.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/

the overall approach to solving the problem was finding the places in the 
log files where the boot sequence started and where it finished. once those
were found, i could then find the time elapsed based on the time stamps at 
the beginning of the lines for each start and stop and find the elapsed time.
with this information we can add the timestamps, filepath and headers to the 
report file. when dealing with the fact that it may be in a boot sequence, if
it is, it adds an incomplete boot to the output report file, increments the fail
counter and continues on

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

indirect help from the class discord

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

no serious problems

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
no other comments