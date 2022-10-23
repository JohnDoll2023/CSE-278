// Copyright 2020
// John Doll Homework 1

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

/*
 * Reads in strings and counts the number of words beginning with a vowel
 */

int main() {
    std::string words;
    std::string letter;
    int count = 0;

    std::getline(std::cin, words);
    boost::algorithm::to_lower(words);

    while (words.size() > 0) {
        letter = words.substr(0, 1);
        if (letter == "a")
           count += 1;

        else if (letter == "e")
           count += 1;

        else if (letter == "i")
           count += 1;

        else if (letter == "o")
           count += 1;

        else if (letter == "u")
           count += 1;

        words.erase(0, words.substr(0, words.find(" ", 0)).size() + 1);
    }

    std::cout << count << std::endl;
    return 0;
}
