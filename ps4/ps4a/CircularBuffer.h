// (C) Copyright Erik van Tilborg, 2022
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#pragma once

#include <stdint.h>
#include <iostream>
#include <memory>


class CircularBuffer {
 public:
  explicit CircularBuffer(int capacity);

  ~CircularBuffer() = default;

  size_t size() {
    return capacity;
  }

  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();

 private:
  std::unique_ptr<int16_t[]> ringBuffer;
  size_t capacity;
  size_t bufferFront;
  size_t bufferBack;
  size_t spacedUsed;

  constexpr static double DECAY = 0.996;
};
