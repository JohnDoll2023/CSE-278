// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

bool isEven(int num);
bool isOdd(int num) {
return (num == 0) ? false : isEven(abs(num) - 1);
}

bool isEven(int num) {
return (num == 0) ? true : isOdd(abs(num) - 1);
}


bool isFactor(int number, int factor) {
  return ((number % factor) == 0);
}

int main(int argc, char** argv) {
  int i = 0;
  std::cout << "Enter an integer: ";
  std::cin >> i;
  
  if (isEven(i)) {
    std::cout << "i is even\n";
  } else {
    std::cout << "i is odd\n";
  }

  return 0;
}
