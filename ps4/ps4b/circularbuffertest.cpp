// (C) Copyright Erik van Tilborg, 2022
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test

#include "CircularBuffer.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(enqueueAndDequeueTest) {
    CircularBuffer buf(8);
    BOOST_REQUIRE(buf.isEmpty());

    buf.enqueue(1);
    buf.enqueue(2);
    buf.enqueue(3);
    buf.enqueue(4);
    buf.enqueue(5);
    buf.enqueue(6);
    buf.enqueue(7);
    buf.enqueue(8);

    BOOST_REQUIRE(buf.isFull());
    BOOST_REQUIRE_EQUAL(buf.dequeue(), 1);
    BOOST_REQUIRE_EQUAL(buf.dequeue(), 2);
    BOOST_REQUIRE_EQUAL(buf.dequeue(), 3);
    BOOST_REQUIRE_EQUAL(buf.dequeue(), 4);

    buf.enqueue(9);
    buf.enqueue(10);
    buf.enqueue(11);

    BOOST_REQUIRE(!buf.isEmpty());
    BOOST_REQUIRE(!buf.isFull());
}

BOOST_AUTO_TEST_CASE(checkFrontAfterEnqueueAndDequeue) {
    CircularBuffer buf(4);
    buf.enqueue(4);
    buf.enqueue(3);
    buf.enqueue(2);
    buf.enqueue(1);
    BOOST_REQUIRE(buf.peek() == 4);

    buf.dequeue();
    buf.dequeue();
    BOOST_REQUIRE(buf.peek() == 2);
}

BOOST_AUTO_TEST_CASE(testForOverflowError) {
    CircularBuffer buf(6);
    for (int i = 0; i < 5; i++) {
        buf.enqueue(i);
    }
    BOOST_REQUIRE_NO_THROW(buf.enqueue(5));
    BOOST_REQUIRE(buf.isFull());
    BOOST_REQUIRE_THROW(buf.enqueue(6), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(dequeueOnEmptyBuffer) {
    CircularBuffer buf(10);
    BOOST_REQUIRE_THROW(buf.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testForCapacityEqualTo0) {
    BOOST_REQUIRE_THROW(CircularBuffer buf(0), std::invalid_argument);
}
