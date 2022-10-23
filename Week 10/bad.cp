#include <iostream>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char* argv[]) {
  short var = 0x0106;
  short last = 0x4241;
  char empty = 0;

  empty = static_cast<char>(var);

  std::cout << "var = " << var << " last = " << last << " empty = ";
  std::cout << static_cast<int>(empty) << std::endl;

  return 0;
}
