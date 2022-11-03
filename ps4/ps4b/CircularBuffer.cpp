// (C) Copyright Erik van Tilborg, 2022
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int cap) {
  capacity = cap;
  bufferFront = 0;
  bufferBack = 0;
  spacedUsed = 0;
  if (capacity < 1) {
    throw std::invalid_argument
    ("The capacity of the Buffer must be greater than 0!");
  }
  ringBuffer = std::make_unique<int16_t[]>(capacity);
}

bool CircularBuffer::isEmpty() {
  if (spacedUsed != 0) {
    _full = false;
    return false;
  } else {
    _full = true;
    return true;
  }
}

bool CircularBuffer::isFull() {
  if (spacedUsed == capacity) {
    _full = true;
    return true;
  } else {
    _full = false;
    return false;
  }
}

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

int16_t CircularBuffer::peek() {
  return ringBuffer[bufferFront];
}

void CircularBuffer::empty() {
  bufferFront = 0;
  bufferBack = 0;
  spacedUsed = 0;
  _full = false;
}
