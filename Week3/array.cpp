// Copyright 2020 Alan M. Ferrenberg
#include <iostream>

int sum(const int val[], const int size) {
  int sum = 0;
  for (int i = 0; (i < size); i++) {
    sum += val[i];
  }
  return sum;
}

void read(int val[], const int size) {
  std::cout << "Enter " << size << " numbers: ";
  for (int i = 0; (i < size); i++) {
    std::cin >> val[i];
  }
}

int main() {
  int vals[20];
  read(vals, 10);
  std::cout << "sum: " << sum(vals, 10) << std::endl;

  return 0;
}
