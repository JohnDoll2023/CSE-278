// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <vector>
#include <string>

int main() {
  // Define vector of 5 empty strings
  std::vector<std::string> fiveWords(5);

  // Read five strings from standard input
  for (auto & word : fiveWords) {
    std::cin >> word;
  }

  // Write the five words back to standard output
  for (auto word : fiveWords) {
    std::cout << word << std::endl;
  }
  
  return 0;
}
