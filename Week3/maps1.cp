// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
  using StrIntMap = std::unordered_map<std::string, int>;
  const StrIntMap MonthNum =
    {{"january", 1}, {"february", 2}, {"march", 3},
     {"april", 4}, {"december", 12}, {"november", 11},
     {"october", 10}, {"may", 5}, {"august", 8},
     {"june", 6}, {"july", 7}, {"september", 9}};     

  // Print all elements in map
  for (const auto & entry : MonthNum) {
    std::cout << entry.first << " => " << entry.second << "\n";
  }
  
  return 0;
}
