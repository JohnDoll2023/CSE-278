#include <iostream>
#include <string>

// Only globals show up in symbol table. So we have 3 global variables
// to ensure they show up in the symbol table.
int variable1         = 10;
double variable2      = 3.142;
std::string variable3 = "hello";

/** A simple method to test mapping of C++ to assembly. */
int doSomething() {
    int var2 = 20;
    var2 += variable1;
    return var2;
}

/*
 * A simple main function.
 */
int main() {
    std::cout << "Result: " << doSomething() << std::endl;
    return 0;
}
