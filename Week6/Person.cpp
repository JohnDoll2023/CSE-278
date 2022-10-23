// Copyright 2020 Christopher Vendome (vendomcg@miamioh.edu)
#include "Person.h"

// Constructor
Person::Person(const int id,
               const std::string& name) {
    this->id = id;
    this->name = name;
}

// Destructor
Person::~Person() {}

// Getter methods
int Person::getId() const {
    return id;
}

const std::string& Person::getName() const {
    return name;  // Return reference to main
}

