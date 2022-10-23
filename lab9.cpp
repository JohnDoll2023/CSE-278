// Copyright 2020 John Doll
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char* argv[]) {
    // Check file input
    if (argc != 2) cerr << "Invalid number of arguments" << endl;

    string file = argv[1];
    ifstream input(file);
    if (!input.good()) cerr << "Invalid file" << endl;

    // Setup any necessary stream(s)
    istringstream reader;
    string line, strNum;
    // Process input
    while (getline(input, line)) {
        // Split input data
        reader.str(line);
        string temp;

        while (reader >> temp) strNum = temp;
        int num = stoi(strNum);

        // Stringstream to hold the hex value
        stringstream hexVal;

        // Convert data
        // Put data into stream as hex value
        hexVal << hex << num;
        string test = hexVal.str();

        // Check to see if hex value size is even
        if (hexVal.str().size() % 2 == 1) {
            // Clear stringstream
            hexVal.str("");
            // Put data in the stream with a leading value
            hexVal << setfill('0') << setw(test.size() + 1) << hex << num;    }

        // Print out hex in little ending splitting the pairs
        // with a " | " character (e.g., | 01 | )
       string hline = hexVal.str();
       cout << "| ";
       while (hline.size() >= 1) {
           cout << hline.substr(hline.size()-2) << " | ";
           hline = hline.substr(0, hline.size()-2);
       } cout << endl;
       reader.clear();   }
}
