// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

// Declaration of main
int main();

// Definition of main
int main() {
  int i = 10;
  // Convert i to a string
  std::string s = std::to_string(i);
  std::cout << "i as a string is " << s << "\n";
  // Convert s to an integer and add 10, storing the result in i
  i = std::stoi(s) + 15;
  std::cout << "i now equals " << i << "\n";
  return 0;
}
