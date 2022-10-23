// Copyright 2020 Alan M. Ferrenberg
#include <iostream>
#include <string>
#include <fstream>

// Prototype for method defined below
void process(std::istream& in, std::ostream& out);
int main(int argc, char *argv[]) {
  std::ifstream input("test_input.txt");
  std::ofstream output("test_output.html");
  if (!input.good() || !output.good()) {
    std::cerr << "Error opening input/output streams\n";
    return 1;
  }
  process(input, output);
  // Streams are closed when variables go out of scope!
  // You can explicitly close them as well
  return 0;
}

void process(std::istream& in, std::ostream& out) {
  std::string input;
  while (std::getline(in, input)) {
    out << "<div class='line'>" << input << "</div>\n";
  }
}
