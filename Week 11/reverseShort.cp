#include <iostream>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char* argv[]) {
  short list[] = {1, 3, 5, 7, 11};
  short *ptr;

  ptr = &list[4];

  for (int i = 0; i < 5; i++) {
    std::cout << ptr << ": " << *ptr << std::endl;
    ptr--;
  }
  return 0;
}
