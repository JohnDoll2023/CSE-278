#include <iostream>
#include <string>

// Variables to simulate method parameters while keeping example simple.
char password[15];   // password entered by user
bool valid = false;  // Flag to indicate if password is correct

int main() {
    // Prompt and read password from user
    std::cout << "Enter secret code: ";
    std::cin  >> password;
    // Check to ensure user entered valid secret code
    const std::string Secret = "I@mR0oT!";    
    if (Secret == password) {
        valid = true;
    }
    // Print message if authentication was successful.
    if (valid) {
        std::cout << "Success. You are root!\n";
    } else {
        std::cout << "Authentication failure\n";
    }
    return 0;
}
