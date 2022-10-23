// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

double PI = 3.142;

int main() {
  unsigned int radius = 2;
  double volume = (4 * PI * radius * radius * radius /3.0);
  int intVolume = static_cast<int>(volume);
  char c = 65;
  std::cout << "Volume = " << volume << "\n";
  std::cout << "Integer volume = " << intVolume << "\n";
  std::cout << "c = " << static_cast<int>(c) << "\n";

  return 0;
}
