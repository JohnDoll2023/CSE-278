// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>

void process(std::istream& in, std::ostream& out) {
  std::string input;
  while (std::getline(in, input)) {
    out << "<div class='line'>" << input << "</div>\n";
  }
}

int main(int argc, char *argv[]) {
  process(std::cin, std::cout);
  
  return 0;
}
