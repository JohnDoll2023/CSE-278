// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

int main() {
  int i = 12;      // 12 in decimal
  int j = 0b1100;  // 12 in binary
  int k = 014;     // 12 in octal
  int l = 0xb;     // 12 in hexadecimal

  if ( (i == j) && (i == k) && (i = l) ) {
    std::cout << "They're all the same!\n";
  }
  
  return 0;
}
