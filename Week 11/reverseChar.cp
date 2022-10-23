#include <iostream>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char* argv[]) {
  char list[] = {1, 3, 5, 7, 11};
  char *ptr;

  ptr = &list[4];

  for (int i = 0; i < 5; i++) {
    std::cout << static_cast<void*>(ptr) << ": " << +(*ptr) << std::endl;
    ptr--;
  }
  return 0;
}
