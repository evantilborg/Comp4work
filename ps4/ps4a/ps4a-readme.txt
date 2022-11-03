/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Erik van Tilborg

Hours to complete assignment: 3-4 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

the assignment was to create an implementation of a CircularBuffer class
along with functions to enqueue and dequeue elements from the buffer, as 
well as others that can check to see of the buffer is full or empty. the 
final part was to implement boost test cases to test the aspects of the
CircularBuffer class and verify they are working as intended.

/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

the key parts that were essential to the assignment were the "accessor" 
functions that essentially control the entire buffer. this being the
enqueue and dequeue functions. they are the ones responsible for adding
and subtracting things from the "queue" (my implementation was based off
an array of unique pointers of int16_t). without the enqueue and dequeue
functions, it would have been harder to get a desired result for the
buffer class.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

the features that i have implemented are primarily one that were given 
as starters from the starting pdf file. the enqueue and dequeue functions
were arguably the most important to the ones added to the class.
this was my implementation of both of them, enqueue then dequeue respectivley:

void CircularBuffer::enqueue(int16_t x) {
  if (isFull()) {
    throw std::runtime_error
    ("The buffer is full... Cannot enqueue on a full buffer!");
  }
  ringBuffer[bufferBack] = x;
  bufferBack = (bufferBack + 1) % capacity;
  spacedUsed += 1;
}

int16_t CircularBuffer::dequeue() {
  if (isEmpty()) {
    throw std::runtime_error
    ("The buffer is empty... Cannot dequeue from an empty buffer!");
  }
  int16_t front = ringBuffer[bufferFront];
  bufferFront = (bufferFront + 1) % capacity;
  spacedUsed -= 1;
  return front;
}

to a lesser extent, but still important were the isFull and isEmpty functions 
to help in seeing the state of the buffer. these combined with the implementation
that i had for the object variable: 

std::unique_ptr<int16_t[]> buf; 

made it easy to implement the necessary functions to make the buffer 
class work as intended and to pass the boost unit tests.

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

all parts of the assignment have been completed, i believe Successfully,
given that the program passes all of the boost tests in test.cpp. with this
i am lead to believe that all parts of the class are working as intended. 

/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
 
yes, the implementation of my CircularBuffer passes the boost unit tests.
the boost unit tests have tested all aspects of my CircularBuffer. 
in running the compliled test program with the boost unit tests, no errors
are observed coming out from the tests. when run, it passes all 5 tests that 
are in test.cpp. within most of the 5 tests, they contain more than just
one test. one tests the abilities of enqueue and dequeue, as well as the 
functions isFull and isEmpty. another is the same but tests the peek function
on various occasions after an enqueue and after a dequeue.

/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/

with my buffer class, the time it should take to operate on is constant 
time given that there are no loops slowing the operations down. almost
everything is done using unique pointers, that help save time and memory
such that they can just read from a stored location. given this, my 
CircularBuffer class should run very efficently and not chew through
resources.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

indirect help from class discord

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

no serious problems

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
