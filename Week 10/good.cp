#include <iostream>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char* argv[]) {
  short var = 0x0106;
  short last = 0x4241;
  short empty = 0;

  empty = var;

  std::cout << "var = " << var << " last = " << last << " empty = ";
  std::cout << empty << std::endl;

  return 0;
}
