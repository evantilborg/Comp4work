// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE unit_testing
#include <boost/test/unit_test.hpp>
#include "RandWriter.h"

BOOST_AUTO_TEST_CASE(order2TestBasedOnStringFromPDF) {
    BOOST_REQUIRE_NO_THROW(RandWriter("gagggagaggcgagaaa", 2));

    RandWriter rw("gagggagaggcgagaaa", 2);

    BOOST_REQUIRE(rw.orderK() == 2);

    // throws error, kgram doesnt exist
    BOOST_REQUIRE_THROW(rw.freq(""), std::runtime_error);
    BOOST_REQUIRE_THROW(rw.freq("a"), std::runtime_error);

    // throws error, kgram is not of length k
    BOOST_REQUIRE_THROW(rw.freq("", 'g'), std::runtime_error);
    BOOST_REQUIRE_THROW(rw.freq("a", 'g'), std::runtime_error);
    BOOST_REQUIRE_THROW(rw.freq("aaa", 'g'), std::runtime_error);

    // no throw, kgram exists in the map
    BOOST_REQUIRE_NO_THROW(rw.freq("aa"));

    // aa kGram tests
    BOOST_REQUIRE(rw.freq("aa") == 2);
    BOOST_REQUIRE(rw.freq("aa", 'a') == 1);
    BOOST_REQUIRE(rw.freq("aa", 'g') == 1);

    // ag kGram tests
    BOOST_REQUIRE(rw.freq("ag") == 5);
    BOOST_REQUIRE(rw.freq("ag", 'a') == 3);
    BOOST_REQUIRE(rw.freq("ag", 'g') == 2);

    // cg kGram tests
    BOOST_REQUIRE(rw.freq("cg") == 1);
    BOOST_REQUIRE(rw.freq("cg", 'a') == 1);

    // ga kGram tests
    BOOST_REQUIRE(rw.freq("ga") == 5);
    BOOST_REQUIRE(rw.freq("ga", 'a') == 1);
    BOOST_REQUIRE(rw.freq("ga", 'g') == 4);

    // gc kGram tests
    BOOST_REQUIRE(rw.freq("gc") == 1);
    BOOST_REQUIRE(rw.freq("gc", 'g') == 1);

    // gg kGram tests
    BOOST_REQUIRE(rw.freq("gg") == 3);
    BOOST_REQUIRE(rw.freq("gg", 'a') == 1);
    BOOST_REQUIRE(rw.freq("gg", 'c') == 1);
    BOOST_REQUIRE(rw.freq("gg", 'g') == 1);

    // kRand tests
    BOOST_REQUIRE_NO_THROW(rw.kRand("aa"));

    BOOST_REQUIRE_THROW(rw.kRand("aaa"), std::runtime_error);

    // supplied kgram is not of length k
    BOOST_REQUIRE_THROW(rw.kRand("aaa"), std::runtime_error);

    BOOST_REQUIRE_NO_THROW(rw.generate("aa", 11));

    BOOST_REQUIRE_THROW(rw.generate("aa", 1), std::runtime_error);
}
