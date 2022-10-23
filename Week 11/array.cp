#include <iostream>
#include <string>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char* argv[]) {
  int list[] = {1, 2, 3, -1};
  int *lp = list;
  *(lp + 2) *= 2;  // Equivalent to list[2] *= 2;
  for (int* i = list; (*i != -1); i++) {
    std::cout << *i << std::endl;
  }

  return 0;
}
