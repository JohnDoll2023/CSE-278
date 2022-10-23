// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {
  std::ifstream inFile(argv[1]);
  std::ofstream outFile(argv[2]);
  // Add check to ensure streams are good
  std::string line;
  while (getline(inFile, line)) {
    outFile << line << std::endl;
  }
  inFile.close();  // Optional as files are automatically
  outFile.close();  // closed when they go out of scope
  return 0;
}
