// Copyright 2020 John Doll
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

void interactive() {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");
    // Variable to build query string
    std::string qString;
    // Get user input for query
    while (getline(std::cin, qString) && qString != "quit") {
        // Create a query
        mysqlpp::Query query = myDB.query(qString);
        try {
            // Check query is correct
            query.parse();
            // Execute query
            mysqlpp::StoreQueryResult result = query.store();
            // Results is a 2D vector of mysqlpp::String objects.
            // Print the results.
            std::cout << "-----Query Result-----" << std::endl;
            for (size_t row = 0; row < result.size(); row++) {
                std::cout << "| ";
                for (size_t column = 0; column < result[row].size(); column++) {
                    std::cout << result[row][column] << " | ";
                }
                std::cout << std::endl;
            }
            std::cout << "------End Result------" << std::endl;
        } catch(mysqlpp::BadQuery e) {
            std::cerr << "Query: " << qString <<std::endl;
            std::cerr << "Query is not correct SQL syntax" <<std::endl;
        }
    }
}

std::string generateLoadQuery(std::string& line) {
    // Create base insert query string
    std::string base;
    std::vector<std::string> content;
    // Split file on commas
    boost::split(content, line, boost::is_any_of(","));
    // Start building query from split files (table name)
    base = "INSERT INTO " + content[0] + " (";
    // Strings to hold attributes and values
    std::string attribute;
    std::string value;
    // Build attribute and value strings
    for (int i = 1; i < content.size(); i++) {
           attribute += ", " + content[i].substr(0, content[i].find(":", 0));
           value += ", " + content[i].substr(1 + content[i].find(":"));
    }
    // Form full query string
    return base += attribute.substr(2) + ") VALUES (" + value.substr(2) + ");";
}

void loadData(std::string& path) {
    // Open file stream
    std::ifstream input(path);

    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");

    // Some necessary variables for the file IO
    int count = 0;
    std::string str;
    // Read file line-by-line
    while (getline(input, str)) {
        // Create query string from current line
        std::string queryStr = generateLoadQuery(str);
        count++;
        // Create mysql++ query
        mysqlpp::Query query = myDB.query(queryStr);
        try {
            // Check query is correct
            query.parse();
            // Execute Query
            query.store();
            std::cout << "Data Line " << count << " Loaded" << std::endl;
        } catch (mysqlpp::BadQuery e) {
            std::cerr << "Query: " << queryStr << std::endl;
            std::cerr << "Query is not correct SQL syntax" <<std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    // Ensure arguments are specified
    if (argc != 2 && argc != 3) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string file;
    std::ifstream input;
    if (argc == 3) {
       file = argv[2];
       input.open(file);
    }
    if (option == "-I") {
       interactive();
    } else if (option == "-L" && input.good()) {
        loadData(file);
        input.close();
    } else {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

    // All done
    return 0;
}
