// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

int main() {
  std::string s1("Testing");
  s1[3] = '*';
  const char* cString = s1.c_str();

  return 0;
}
