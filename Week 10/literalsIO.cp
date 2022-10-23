// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

int main() {
  int num = 0;
  std::cout << "Enter a hexadecimal number: ";
  std::cin >>  std::hex >> num;
  // Print number in various bases
  std::cout <<  "Decimal :    " << std::dec << num << std::endl
            <<  "Octal:       " << std::oct << num << std::endl
            <<  "Hexadecimal: " << std::hex << num << std::endl;
  
  return 0;
}
