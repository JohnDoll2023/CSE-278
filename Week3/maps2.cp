// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
  using StrIntMap = std::unordered_map<std::string, int>;
  const StrIntMap WordNum = {{"one", 1}, {"two", 2}, {"three", 3}};

  // Look up entry in hash map
  std:: string word;
  std::cout << "Enter a word: ";
  std::cin >> word;
  if (WordNum.find(word) == WordNum.end()) {
    std::cout << "The word " << word << " is not valid\n";
  }
  
  return 0;
}
