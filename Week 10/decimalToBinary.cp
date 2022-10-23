// Copyright 2020 Alan M. Ferrenberg
// Program to display a decimal number in binary format
#include <vector>
#include <iostream>
#include <string>
#include <climits>

// Make sure that the provided value is a valid unsigned int
unsigned long long checkValue(std::string value) {
  // Use an unsigned long long to catch the case where the string is
  // an integer, but is larger than UINT_MAX
  unsigned long long convertedValue;
  
  // If convertedValue cannot be cast as an unsigned long long, there will
  // be an exception generated.  Catch it and return an error message
  try {
    convertedValue = static_cast<unsigned long long>(std::stoull(value));
  }
  catch (std::exception& e) {
    std::cerr << "The argument must be an unsigned integer.\n";
    return ULLONG_MAX;
  }

  // The argument is an integer, but may be larger than what can be stored
  // in an unsigned int.  If that's the case, return an error message.
  if (convertedValue > UINT_MAX) {
    std::cerr << "The argument must be an unsigned integer.\n";
    return ULLONG_MAX;    
  }
  return convertedValue;
}

int main(int argc, char** argv) {
  unsigned int quotient, remainder;
  // Verify the correct number of arguments
  if (argc != 2) {
    std::cerr << "Specify the decimal number to convert\n";    
    return 1;
  }
  
  // Check that the argument is actually a valid unsigned int
  unsigned long long testValue = checkValue(argv[1]);
  if (testValue == ULLONG_MAX) {return 2;}

  quotient = static_cast<unsigned int>(testValue);

  // Check for the case where the number to convert is zero
  if (quotient == 0) {
    std::cout << "0\n";
  } else {
  // Use a vector to store the "bits" of the binary representation
    std::vector<unsigned int> binaryRepresentation;
    while (quotient > 0) {
      remainder = quotient % 2;    
      quotient = quotient/2;

    // Add the remainder to the vector that stores the binary representation
      binaryRepresentation.push_back(remainder);
    }

  // Write out the reverse of the remainders
    for (int i = (binaryRepresentation.size() - 1); i >= 0; i--) {
      std::cout << binaryRepresentation[i];
    }
    std::cout << std::endl;
  }

  return 0;
}
