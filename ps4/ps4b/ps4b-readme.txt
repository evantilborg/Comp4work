/**********************************************************************                              
 *  PS4b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Erik van Tilborg

Hours to complete assignment : 7-8 hours

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

 i was successfully able to get the project to work. through utilizing
 boost unit tests on both the circularbuffer class and the StringSound
 class, i was able to verify that the inner workings of my code were
 working as intended. when running the main driver ./KSGuitarSim the 
 keyboard implementation seems to be working as intended. i tested all
 of the keyboard inputs based on the assignment pdf and they all seem
 to play the correct sound based off of the equation given in the pdf 
 of assignment ps4a and PS4b

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/

i did not attempt the extra credit described in the assignment pdf

/**********************************************************************
 *  Did you implement exceptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

yes i did, within the 2 constructors for the StringSound class, i 
incorperated checks that would throw an std::invalid_argument exception if
the conditions for failure were met. both constructors have the same premise
of error checking, but their checks are different because each one is used
with a different parameter.

/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

my lambda expression was used in the KSGuitarSim.cpp file and was used to 
get the calculation of the frequency for the notes and return that value.
the function gets used in another function that stores the frequencies 

/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

yes, my code passed cpplint. in my makefile i added a target that would
lint all my files whenever i ran the make command. if any errors showed
up, i could go fix them based off of what it said in the terminal for 
errors

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/

indirect help from class discord server

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

no serious problems encountered

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

 since the test.cpp file was used for testing the circularbuffer class
 it has been removed from the submission and replaced with a test file 
 for the StringSound class
 
 to run the boost test cases on StringSound, run ./ssboosttest
