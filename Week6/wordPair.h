// Copyright Christopher Vendome (vendomcg@miamioh.edu)

#ifndef WORDPAIR_H
#define WORDPAIR_H

#include <string>

class WordPair {
public:
    // No-argument constructor
    WordPair() {
        word1 = word2 = “”;
    }
    // Constructor to set the 2 words
    WordPair(const std::string& w1,
              const std::string& w2) {
        word1 = w1;
        word2 = w2;
    }
    // Destructor (converse of constructor)
    ~WordPair() {}
    // A getter method
    std::string get(bool w1 = true) {
        return w1 ? word1 : word2;
    }
private:
    std::string word1;
    std::string word2;
};

#endif /* WORDPAIR_H */
