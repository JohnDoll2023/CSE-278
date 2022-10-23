// Copyright Christopher Vendome (vendomcg@miamioh.edu)

#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
public:
    // Constructor
    Person(const int id = 0, 
           const std::string& name = "");
    // Destructor
    ~Person();
    // Getter methods
    int getId() const;
    const std::string& getName() const;
private:
    int id;
    std::string name;
};

#endif /* PERSON_H */

