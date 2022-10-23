#include <iostream>
#include <string>

// Copyright 2020 Alan M. Ferrenberg

int main(int argc, char* argv[]) {
  std::string list[] = {"C++", "Java", "Python", "Javascript", "Ruby"};
  std::string *ptr1, *ptr2, *ptr3;

  ptr1 = list;
  ptr1 += 3;
  ptr1--;
  std::cout << ptr1->size() << std::endl;

  ptr2 = &list[1];
  std::cout << ptr2 << ":" << ptr2->size() << std::endl;
  std::cout << *ptr2 << ":" << (++ptr2)->size() << std::endl;

  if (ptr1 == ptr2) {
    ptr3 = list + 4;
  } else {
    ptr3 = &list[1];
  }
  
  std::cout << *ptr3 << std::endl;

  if (++ptr1 != ptr2++) {
    std::cout << *(ptr1++) << ":" << *(--ptr2) << std::endl;
  }
  
  return 0;
}
