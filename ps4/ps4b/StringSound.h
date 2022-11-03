// (C) Copyright Erik van Tilborg, 2022
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#pragma once

#include "CircularBuffer.h"

#include <vector>
#include <cstdint>
#include <cmath>
#include <climits>
#include <iostream>
#include <ctime>
#include <random>

#include <SFML/Graphics.hpp>

static const auto CONCERT_A = 220.0;
static const auto SAMPLING_RATE = 44100;
static const auto size_of_keyboard = 37;
static const char keyboard_keys[] = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

class StringSound {
 public:
  explicit StringSound(double frequency);
  explicit StringSound(std::vector<sf::Int16> init);

  StringSound(const StringSound &obj) = delete;
  ~StringSound();

  void pluck();
  void tic();

  sf::Int16 sample();

  int time();

 private:
  CircularBuffer * _cb;
  int _time;
};
