/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Erik van Tilborg

(Partnering is optional. See the guidelines on the assignments page.)
Partner's name: no partner

Hours to complete assignment: 10ish

Which partner is submitting the program files?
Me, i worked alone

/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
 i believe my implementation is based off of the Needleman-Wunsch method
 although not entire;y using a matrix, but mimicing the memory of a matrix
 with a vector<vector<int>>.

 before the alignment of the strings, to find the Edit distance i mimiced 
 a matrix in memory by using a vector<vector<int>>. this was used to
 calculate the edit distance and help with the alignment of the strings later
 on.

to find the actual alignment of the strings i had a method of comparing 
what the current value was with what ever the next value would be plus a
penalty vaue or a gap. whichever case that satisfied the initial value,
is what ended up being used. given different cases, it would push back 
the appropiate character into the position of the final string that would
get returned after the whole strings were parsed.

/**********************************************************************
 * You are required to create one additional test case by hand. 
 * It should be constructed in such a way that you know the correct 
 * output before running your program on it, and it should be a 
 * "corner case" that helps check if your program handles all special 
 * situations correctly. Please list:
 * - a copy of the test case input
 * - the expected test case output
 * - whether your program ran correctly on it or not
 * - optionally, any other remarks
 **********************************************************************/
Input: endgaps7.txt
atattat
tattata

Expected output:
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

What happened:
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0

the bottom row was cut off from the test, however in other tests, this doesnt seem
to be an issue. running another test: example10.txt, it matches the output just fine.
i think there may be an issue with having a gap at the end in the first string however
i cannot find that issue. 

/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2GB and 4GB. If your machine has 512MB or less, use a cluster
 *  machine for this readme (see the checklist for instructions).
 **********************************************************************/

 Runtime Tests:

 Apple MacBook Air 2020: Apple M1 @ 3.2 GHz
 8 core cpu 
 7 core gpu
 8GB unified memory (shared ram and video memory)

 -----------------------------------------------------------------------

 Valgrind tests: (macOS doesnt have valgrind support)

 Ubuntu 20.04 LTS Linux VM: running off my windows machine 
 Dedicated hardware:
 Intel i7-11800H @ 2.3 GHz (base clock):
 2 cores, 4 threads (of 8 cores 16 threads) 
 4 GB ram

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 1GB (billion bytes) of memory?
 **********************************************************************/

given that my system "techinically" has 8 GB of ram, this means i have 
8,000,000,000 bytes to store upto.
so if we do the math:
8 billion >= 4 * N^2
8 billion / 4 >= N^2
√(8e+09 / 4) = N 
44,721 ~= N (when rounded to the nearest whole number)

with this my system should not have been able to run the ecoli50000.txt file
but it did. this is due to the way that appl ehas designed their unified 
architecture, that once the ram is used up, it starts to write in a swap/ssd 
partition and treates it like pseudo ram.

-------------------------------------------------------------------------------

a = 4 (the byte size of an int)
b = 4 (N^4 bases off of the amount allocated by an NxN matrix (int, int))
largest N = 125

given that we are limited to 1GB this dratically shrinks the largest N value.
so if we do the math:
1 billion >= 4 * N^4
1 billion / 4 >= N^4
4√(1e+09 / 4) = N 
125 ~= N (when rounded down to the nearest whole number)

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *  For help on how to do timing, see the checklist (e.g. -Xprof).
 *  If you get an OutOfMemoryError, see the checklist about -Xmx.
 *  If you get "Could not reserve enough space for object heap" or the timing
 *  of these tests takes too long for the last few test cases (N=20000 or higher), 
 *   note this, and skip filling out those rows of the table.
 **********************************************************************/

 done without using compiler optimization

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118              0.203 
ecoli5000.txt          160              0.707
ecoli10000.txt         223              2.717
ecoli20000.txt         3135             10.929
ecoli50000.txt         19485            71.704
ecoli100000.txt        24166            323.777


/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 4 (int size)
b = some integer
largest N =

with a limit of 1 day and unlimited ram, we can change how we do the math.
1 day = 86400 seconds
theoretically the maximum N value can vary based off of what the value for b is
say we have an N of 15000 if we plug in the values such:
86400 = 4 * 10000^b
it would give us a b value of about 1.08133
the smaller the b value is, the larger then N value can be. 

/**********************************************************************
 *  If you worked with a partner, do you have any remarks on the pair
 *  programming method? E.g., how many times did you switch, what are
 *  the tradeoffs of driving vs. navigating, etc.
 **********************************************************************/

i worked alone

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

indirect help from the class discord server and class note materials

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

no serious problems

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

