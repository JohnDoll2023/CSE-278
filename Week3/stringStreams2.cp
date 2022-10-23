// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

// Prototype for some method
void copy(std::istream& in, std::ostream& out);

int main() {
  // Copy from a file onto the console
  std::ifstream inFile("input.txt");
  copy(inFile, std::cout);

  // Copy words typed by the user to a file
  std::ofstream outFile("~/public_html/words.txt");
  copy(std::cin, outFile);

  // Copy words from a to a file
  std::ofstream data("~/data_file.txt");
  std::istringstream is("  testing **   123 123");
  copy(is, data);
  
  return 0;
}
