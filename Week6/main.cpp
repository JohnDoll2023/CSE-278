// Copyright 2020 Christopher Vendome (vendomcg@miamioh)

#include "Person.h"
#include <iostream>
#include <string>

int main() {
    Person p1(9001, "John");
    if (p1.getId() > 9000) {
        std::string name = p1.getName();
        std::cout << "The name is " << name << std::endl;
    }
}
