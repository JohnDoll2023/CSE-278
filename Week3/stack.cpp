// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

void doIt(int i, float f, std::string str) {
  if (i > 1) {
    doIt(--i, f, str.substr(1));
  }
}

int main() {
  std::string s = "abcd";

  doIt(5, 3.14, s);

  return 0;
}
