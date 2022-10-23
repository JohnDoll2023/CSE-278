#include <iostream>

// Copyright 2020 Alan M. Ferrenberg

int sum(const int list[]) {
  int sum = 0;
  for (int i = 0; (list[i] != -1); i++) {
    sum += list[i];
  }
  return sum;
}

int sumPtr(const int* list) {
  int sum = 0;
  for (const int *i = list; (*i != -1); i++) {
    sum += *i;
  }
  return sum;
}

int sumPtr2(const int* list) {
  int sum = 0;
  for (sum = 0; (*list != -1); sum += *list, list++) {}
  return sum;
}

int main(void) {
  int list[] = {1, 2, 3, -1};

  std::cout << sum(list) << std::endl;
  std::cout << sumPtr(list) << std::endl;
  std::cout << sumPtr2(list) << std::endl;

  return 0;
}
