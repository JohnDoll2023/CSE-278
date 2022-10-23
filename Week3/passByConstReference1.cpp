// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

int capsCount(const std::string& str) {
  const std::string capitals = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int capsCount = 0;
  for (size_t i = 0; (i < str.size()); i++) {
    if (capitals.find(str[i]) != std::string::npos) {
      capsCount++;
    }
  }
  return capsCount;
}

int main(int argc, char** argv) {
  std::string testString = "ThIs iS a TesT StriNG";
  std::cout << testString << " "  << capsCount(testString) << std::endl;
  std::cout << "Hello World " << capsCount("Hello World") << std::endl;

  return 0;
}
