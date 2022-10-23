// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

std::string& longer(std::string& s1, std::string& s2) {
  return (s1.size() < s2.size() ? s2 : s1);  
}

int main() {
  std::string firstString = "abcdefg";
  std::string secondString = "abcdefgh";
  std::cout << longer(firstString, secondString) << std::endl;

  return 0;
}
