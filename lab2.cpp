// Copyright
#include <iostream>
#include <string>

/*
 * A simple string operation program
 */
int main(int argc, char** argv) {
    std::string longest = "";
    std::string words;
    std::string current;
    int position = 0;
    int wordCount = 0;

    std::cout << "Enter a line: ";
    std::getline(std::cin, words);

    while (position < words.size()) {
        wordCount += 1;
        current = words.substr(position, words.find(" ", position) - position);

        if (current.size() >= longest.size())
            longest = current;

        words.erase(position, current.size() + 1);
    }

    std::cout << "Number of words: " << wordCount << std::endl;
    std::cout << "Largest word: " << longest << std::endl;

    return 0;
}

