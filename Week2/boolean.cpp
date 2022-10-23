// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

// Declaration of main
int main();

// Definition of main
int main() {
  bool isEmpty = false;
  bool ready = true;
  bool result = (isEmpty && ready) || !ready;

  std::cout << "result " << result << std::endl;;
  std::cout << "True " << true << "\tFalse: " << false << std::endl;;
  return 0;
}
