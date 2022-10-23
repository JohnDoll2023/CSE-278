// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> wordList;
  std::string word;

  // Read words from standard input until EOF
  while ((std::cin >> word)) {
    wordList.push_back(word);  // Add to end of vector
  }

  // Write words in reverse order to standard output
  for (int i = (wordList.size() - 1); (i >= 0); i--) {
    std::cout << wordList[i] << std::endl;
  }
  
  return 0;
}
