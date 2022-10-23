// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
  std::ifstream inFile("numbers.txt");
  if (!inFile.good()) {
    std::cerr << "Unable to read numbers.txt\n";
    return 1;
  }
  int sum = 0, num;
  // Read numbers from input file until end of file (EOF)
  while ((inFile >> num)) {
    sum += num;
  }
  std::cout << "sum: " << sum << std::endl;
  return 0;
}
