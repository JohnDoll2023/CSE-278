#include <iostream>
#include <string>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Fail" << std::endl;
    return 1;
  }

  std::string list[argc-1];
  for (int i = 0; i < argc-1; i++) {
    list[i] = argv[i+1];
  }

  std::string *ptr = &list[2];
  std::string i;

  if (*--ptr == "passwd") {
    std::cout << *ptr++ << std::endl;
    std::cin >> i;
  }

  if (*ptr == i) {
    std::cout << "Pass" << std::endl;
    return 0;
  }
  std::cerr << "Fail" << std::endl;
  return 1;
}
