// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

void doIt(const int& i) {
  // i *= 3;
  std::cout << i << " ";
}

int main(int argc, char** argv) {
  int k = 10;
  doIt(5);
  std::cout << "\nk = " << k << "\n";

  return 0;
}
