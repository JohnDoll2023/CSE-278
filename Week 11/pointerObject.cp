#include <iostream>
#include <string>

// Copyright 2020 Alan M. Ferrenberg

void print(const std::string *list) {
  while (*list != "") {
    std::cout << *list << " (" << list->length() << ")\n";
    list++;
  }
}

int main(void) {
  std::string words[] = {"one", "two", "three", ""};

  print(words);

  return 0;
}
