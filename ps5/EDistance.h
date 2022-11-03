// (C) Copyright Erik van Tilborg, 2022.
// Distributed under MIT license, available at
// https://opensource.org/licenses/MIT.
#pragma once

#include <iostream>
#include <vector>
#include <string>

class EDistance {
 public:
  EDistance(std::string str_a, std::string str_b);
  static int penalty(char a, char b);
  static int min(int a, int b, int c);  //NOLINT
  int optDistance();
  std::string alignment();
  void printMatrix();

 private:
  std::string A_str;
  std::string B_str;
  std::vector< std::vector<int> > mtx;
};
