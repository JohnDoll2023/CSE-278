// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <sstream>
#include <string>

int main() {
  const std::string inputStr = "1 2 3";

  std::istringstream reader(inputStr);
  int i, j;
  reader >> i >> j;

  std::ostringstream writer;
  writer << "i = " << i << " and j = " << j;
  std::string outputStr = writer.str();
  std::cout << outputStr << std::endl;
  
  return 0;
}
