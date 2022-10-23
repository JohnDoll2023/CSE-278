#include <iostream>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char* argv[]) {
  int list[] = {1, 3, 5, 7, 11};
  int *ptr;

  for (ptr = &list[4]; !(ptr < &list[0]); ptr--) {
    std::cout << ptr << ": " << *ptr << std::endl;
  }
  return 0;
}
