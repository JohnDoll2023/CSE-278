// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  int val = 70;
  std::cout << "Decimal: " << std::dec << val << std::endl
            << "Octal: "   << std::oct << val << std::endl
            << "Hex: "   << std::hex << val << std::endl;
  std::cout << "bool: " << true << std::endl
            << "boolalpha: "   << std::boolalpha << true << std::endl;

  std::cout << "Pi default precision: " << M_PI << std::endl
            << "Pi 15-places precision: "  << std::setprecision(15)
            << M_PI << std::endl
            << "Pi 3-places precision: "  << std::setprecision(3)
            << M_PI << std::endl;

  return 0;
}
