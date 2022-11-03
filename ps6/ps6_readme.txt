/**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name: Erik van Tilborg

Hours to complete assignment: 7~8 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

assignment was to create a program that followed the markov model for
essentially "encoding" text. it would take in a string and an order of
length for the "kGram" then take that and generate pseudo random text
based off of the kgrams and the order that was supplied. the final result
would be of length L also supplied by the user.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

in my implementation, i used a struct to help manage most of the information
that needed to be housed for this assignment. my main object was a map of strings
and a struct object called kGramInfo, that housed the frequencies of the kGrams,
another map of chars and ints, that help the next chars and their frequencies based
on the kgram strings in the first map. having the struct made it a bit easier to
access some of the information i needed to compute various elements of the assignment

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

my main object:

std::map <std::string, kGramInfo> kGramMap;

this is the main object that gets referenced in the code files. everything 
stems from one object which makes it easier to operate on as oppsoed to having
two map objects. i put the second on in a struct that also houses more useful
information and is easier to access things that are needed to know more often
more quickly.

my struct:

struct kGramInfo {
    int freq;
    std::map <char, int> charFreq;
};

this houses the frequencies of the kgrams stored in the map located in the 
private variable section of the RandWriter class. it allows for easier access
to the majority of useful information in the map object.

my cout (<<) overload:

std::ostream &operator<<(std::ostream &out, RandWriter &obj) {
    out << "Order: " << obj.orderK() << std::endl;
    out << "Alphabet: " << obj.Alphabet << std::endl;
    std::map<std::string, kGramInfo>::iterator KIter;
    std::map<char, int>::iterator CFIter;
    for (KIter = obj.kGramMap.begin(); KIter != obj.kGramMap.end(); KIter++) {
        for (CFIter = KIter->second.charFreq.begin();
             CFIter != KIter->second.charFreq.end(); CFIter++) {
            out << "KGram: " << KIter->first << " Frequency: "
            << KIter->second.freq << " Next Char: " << CFIter->first
            << " Frequency: " << CFIter->second << std::endl;
        }
    }
    return out;
}
this allows for easy access to see the various kGrams and their frequencies
also to see their possible next characters and those frequencies without having to 
deal with a lot of extra functions to print out everything.

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

i completed the whole assignment. i believe it to be fully working. in my
testing with the input17.txt file, based off of the test line in the PDF,
my program resulted with the all of the possible kgrams, the correct 
frequencies of the kgrams, the next characters of the kgrams, and the 
frequencies of those next characters.

/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

yes my implementation passes all of the unit tests that i have in test.cpp
i know this because after running the executable ./BoostTest, it tells me 
that there are no errors

 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
exceptions used in RandWriter.cpp only:
(ones in test.cpp are required by a throw from the functions in RandWriter.cpp)

ALL IN RandWriter.cpp:
line 53: throw std::runtime_error("ERROR: kGram not of length k");
line 66: throw std::runtime_error("ERROR: kGram not of length k");
line 79: throw std::runtime_error("ERROR: kgram is not of length k");
line 88: throw std::runtime_error("Inputted kGram does not exist");
line 106: throw std::runtime_error("ERROR: kgram is not of length k");
line 110: throw std::runtime_error("ERROR: L must be greater >= to k");

 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/
4-12-22
made the a function that converts the user input from const char* argv[] from
a const char * to an int, that takes a lambda as an argument. i is used on both
argv[1] and argv[2], the order and the rand generated string length.

it is defined in the top of TextWriter.cpp as a template function. it was one
of the only things i could manage to get to work. initially i had tried to get 
it to work by printing out the map contents, but i got errors with symbols in the 
linker. this was essentially my last resort to have a lambda in the program.

4-11-22
i currently do not have a lambda expression with in my code. at the moment
i am still deciding where my code can most benefit from having one given 
that per the assignment spec, it needs to be passed as an argument. and 
because i have to keep all the functions required by th eassignment to 
the letter of the pdf, it takes more time and effort to figure out where
to use one

/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/

no i didnt attempt the extra credit

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
