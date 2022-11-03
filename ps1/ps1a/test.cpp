// Initial tests provided by:
// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

//beginning of added tests:

BOOST_AUTO_TEST_CASE(caseNot16BitString){
/**test to see if the constructor properly throws an
 * invalid_argument if the seed given is longer or 
 * shorter than 16 bits 
 **/

	BOOST_REQUIRE_THROW(FibLFSR Test2a("10001011011010100");, std::invalid_argument); //testing with 17 bit string
	BOOST_REQUIRE_THROW(FibLFSR Test2b("101001111001100");, std::invalid_argument); //testing with 15 bit string

}

BOOST_AUTO_TEST_CASE(unnamedTest){
/**test to make sure the constructor is properly 
 * converting the information from the initial 
 * bit string into the correct position in the
 * private vector object
 **/

	FibLFSR Test3("0011100010101100");
	BOOST_REQUIRE(Test3.getBitAtIndex(0) == 0);
	BOOST_REQUIRE(Test3.getBitAtIndex(1) == 0);
	BOOST_REQUIRE(Test3.getBitAtIndex(2) == 1);
	BOOST_REQUIRE(Test3.getBitAtIndex(3) == 1);
	BOOST_REQUIRE(Test3.getBitAtIndex(4) == 1);
	BOOST_REQUIRE(Test3.getBitAtIndex(5) == 0);
	BOOST_REQUIRE(Test3.getBitAtIndex(6) == 0);
	BOOST_REQUIRE(Test3.getBitAtIndex(7) == 0);
	BOOST_REQUIRE(Test3.getBitAtIndex(8) == 1);
	BOOST_REQUIRE(Test3.getBitAtIndex(9) == 0);
	BOOST_REQUIRE(Test3.getBitAtIndex(10) == 1);
	BOOST_REQUIRE(Test3.getBitAtIndex(11) == 0);
	BOOST_REQUIRE(Test3.getBitAtIndex(12) == 1);
	BOOST_REQUIRE(Test3.getBitAtIndex(13) == 1);
	BOOST_REQUIRE(Test3.getBitAtIndex(14) == 0);
	BOOST_REQUIRE(Test3.getBitAtIndex(15) == 0);

}
