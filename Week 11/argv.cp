#include <iostream>
#include <string>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char * argv[]) {
  if (argc < 4) {
    std::cerr << "\nProgram requires at least three command line arguments\n";
    return 1;
  }
  std::cout << argv[1] << std::endl;
  std::cout << argv[2] << std::endl;
  std::cout << argv[3] << std::endl;

  char x;
  int j;
  while ((x = argv[1][j]) != 0) {
    std::cout << "argv[1][" << j << "] = " << static_cast<int>(x) << std::endl;
    j++;
  }

  return 0;
}
