// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

int factorial(int num) {
  return (num <= 1) ? 1 : num*factorial(num - 1);
}

int main(int argc, char** argv) {
  int i = 0;
  std::cout << "Enter an integer, less than 13: ";
  std::cin >> i;

  std::cout << "The factorial of " << i << " is " << factorial(i) << std::endl;

  return 0;
}
