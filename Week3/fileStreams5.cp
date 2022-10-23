// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Incorrect number of command line arguments\n";
    return 1;  // non-zero return from main to signal error
  }
  std::ifstream inFile(argv[1]);  // Open input file
  std::ofstream outFile(argv[2]);  // Create/overwrite output file
  if (!inFile.good() || !outFile.good()) {
    std::cerr << "Unable to open one of the files\n";
    return 2;  // non-zero return from main to signal error
  }

    //  Now do something with the files...
  return 0;
}
