// (C) Copyright Erik van Tilborg, 2022
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test

#include "StringSound.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(ExceptionHandling) {
    // first tests if a negative value is passed in as an argument
    BOOST_REQUIRE_THROW(StringSound t1(-1), std::invalid_argument);
    // second tests the other constructor for an empty vector.
    BOOST_REQUIRE_THROW(StringSound t2({}), std::invalid_argument);
    /* given the nature of the random number generator that is used
    in the StringSound.cpp file and used in the pluck function, i 
    could not think of clear test that would produce the same result
    everytime it would be tested. */
}
