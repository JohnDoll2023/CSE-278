// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

int getNum() {
  int i = 10;
  return i;
}

std::string getStr() {
  std::string s = "testing";
  return s;
}

int main() {
  std::cout << getNum() << std::endl;
  std::cout << getStr() << std::endl;

  return 0;
}
