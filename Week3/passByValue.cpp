// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

void doIt(int i) {
  i *= 3;
  std::cout << i << " ";
}

int main(int argc, char** argv) {
  int k = 10;
  doIt(5);
  doIt(3 + 2);
  doIt(k);
  std::cout << "\nk = " << k << "\n";

  return 0;
}
