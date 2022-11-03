/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Erik van Tilborg
Hours to complete assignment: ~5 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

the assignment was to create a Linear feedback shift register based off
of the Fibonacci sequence. in the assignment i was able to successfully 
complete a FibLFSR and have it run many tests, some of my own creation
and some that were provided

/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/

for the register bits, i used a vector to handle and manipulate them. I 
chose a vector because they are easy to deal with and access different
specific components. The way that my vector FibLFSR is set up is that it
reads in the seed string and stores the value of the characters in the
string into the corresponding position in the vector. To access the
required bit positions for the taps, it was as easy as reversing the bit 
order (MSB is in bit 15, vector[0], and LSB at bit 0, vector[15]) and 
going from there. to get the step function, i XORed the 15(0) and 13(2) 
bits and stored the result in a varibale that will get updated. then XORed 
the result with bit 12(3) then that with bit 10(5). that final number is
the return value of the function. to shift the vector, i made it so that 
it looped for the size of the vector and set whatever the position is to
the value of the position 1 up from it ex: vec[i] = vec[i + 1]. then pushed
a holding 0 onto the end if the value of i+1 was greater than the vectors
size, indicating that all the bits had been shifted. then outside the loop,
the value from the XORs is pushed back on the vector giving the complete step
i also added some getter functions that aided in getting some information 
from the vector that couldnt be accessed directly within some functions. All 
in all, my choice for using a vector in this project boiled down to ease of 
use and my familiarity with the object type.
 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/

in my BOOST tests that i made, i have one that tests the constructors
ability to take in a string seed and correctly place the corresponding
information inside of a vector of ints 1-to-1 of that of the initial seed.
if the constructor for whatever reason failed to do so, BOOST would fail
the test. The other test i made is to check that my exception handling is 
working as intended, also within the constructor. This is because, in the 
assignment it was stated that this partucular LFSR was to work on 16 bit
input strings. To verify that my constructor would throw an error if it 
received a string that was larger or smaller than the stated 16, i set up
a case that tested it if it would throw an error at 17 bits and 15 bits,
both one larger and one smaller than 16. Both instances should throw an
std::invalid_argument and be caught by BOOST during these tests

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
class notes

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
No serious problems encountered

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
