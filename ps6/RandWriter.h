// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.

#pragma once

#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>
#include <iostream>
#include <functional>

struct kGramInfo {
    int freq;
    std::map <char, int> charFreq;
};

class RandWriter {
 public:
  RandWriter(std::string text, int k);
  int orderK() const;
  int freq(std::string kgram) const;
  int freq(std::string kgram, char c) const;
  char kRand(std::string kgram);
  std::string generate(std::string kgram, int L);
  friend std::ostream& operator<<(std::ostream &out, RandWriter &obj);
 private:
  int _order;
  std::string Alphabet;
  std::map <std::string, kGramInfo> kGramMap;
};
