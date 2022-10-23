// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

/*
 * A simple string operation program
 */

int main(int argc, char** argv) {
  std::cout << "Enter a line of text: ";
  std::string line;
  std::getline(std::cin, line);
  // Print information about the line
  std::cout << "Length of line : " << line.size() << std::endl;
  std::cout << "First character: " << line.front() << "\n";
  std::cout << "Last character : " << line.back() << "\n";
  std::cout << "First word     : " << line.substr(0, line.find(' ')) << "\n";
  size_t lastSpcPos = line.rfind(' ') + 1;
  if (lastSpcPos == std::string::npos) {
    lastSpcPos = 0;
  }
  std::cout << "Last word      : " << line.substr(lastSpcPos) << "\n";

  return 0;
}
