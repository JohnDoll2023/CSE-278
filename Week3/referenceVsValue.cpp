// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

std::string upperVal(std::string str) {
  for (size_t i = 0; (i < str.size()); i++) {
    str[i] = toupper(str[i]);
  }
  return str;
}

void upperRef(std::string& str) {
  for (size_t i = 0; (i < str.size()); i++) {
    str[i] = toupper(str[i]);
  }
}


int main(int argc, char** argv) {
  std::string test1 = "hello", test2 = "world";
  upperRef(test1);
  std::string res = upperVal(test2);
  std::cout << "Ref: " << test1 << "\nVal Arg: " << test2
            << "\nVal Ret: " << res << std::endl;

  return 0;
}
