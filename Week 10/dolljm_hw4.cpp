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
    if (!input.good())
       std::cerr << "Error opening file" << std::endl;
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
    input.close();
}

std::string generateTableQuery(std::string line) {
    std::string base;
    std::vector<std::string> content;
    boost::split(content, line, boost::is_any_of(","));
    base = "CREATE TABLE dolljm_" + content[0].substr(11) + " (";
    std::string row;
    std::string key;
    std::vector<std::string> rowContent;
    for (int i = 1; i < content.size(); i++) {
        row += ", ";
        boost::split(rowContent, content[i], boost::is_any_of(":"));
        for (int j = 0; j < rowContent.size(); j++) {
            if (rowContent[j] == "not_null") {
               row += rowContent[j].substr(0, rowContent[j].find("_")) + " ";
               row += rowContent[j].substr(rowContent[j].find("_") + 1);
            } else if (rowContent[j] == "key") {
               key = ", PRIMARY KEY (" + rowContent[0] + ") ";
            } else {
                row += rowContent[j] + " ";
            }
        }
    }
    return base + row.substr(2) + key + ");";
}

void create(std::string file) {
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");
    std::string str;
    std::ifstream in(file);
    if (!in.good())
       std::cerr << "Error opening file" << std::endl;
    while (getline(in, str)) {
        std::string creator = generateTableQuery(str);
        mysqlpp::Query query = myDB.query(creator);
        try {
            query.parse();
            query.store();
            std::cout << "Table dolljm_myTable Created" << std::endl;
        } catch (mysqlpp::BadQuery e) {
            std::cerr << "Query: " << creator << std::endl;
            std::cerr << "Query is not correct SQL syntax" << std::endl;
        }
    }
    in.close();
}

void dropTable(std::string table) {
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");
    std::string base = "DROP TABLE " + table + ";";
    mysqlpp::Query query = myDB.query(base);
    try {
        query.parse();
        query.store();
        std::cout << "Table " << table << " Dropped" << std::endl;
    } catch (mysqlpp::BadQuery e) {
        std::cerr << "Query: " << base << std::endl;
        std::cerr << "query is not correct SQL syntax" << std::endl;
    }
}

void loadQueries(std::string& file, std::ostream& out) {
    std::ifstream input(file);
    if (!input.good() || !out.good())
       std::cerr << "Error with files" << std::endl;
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");
    std::string str;
    while (getline(input, str)) {
        mysqlpp::Query query = myDB.query(str);
        try {
            query.parse();
            mysqlpp::StoreQueryResult result = query.store();
            out << "-----Query Result-----" << std::endl;
            for (size_t row = 0; row < result.size(); row++) {
                out << "| ";
                for (size_t column = 0; column < result[row].size(); column++) {
                    out << result[row][column] << " | ";
                }
                out << std::endl;
            }
            out << "-----End Result-----" << std::endl;
        } catch (mysqlpp::BadQuery e) {
            std::cerr << "Query: " << str << std::endl;
            std::cerr << "Query is not correct SQL syntax" << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    // Ensure arguments are specified
    if (argc != 2 && argc != 3 && argc != 4) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        return 1;
    }
    std::string option = argv[1];
    if (option == "-I") { interactive();
    } else if (option == "-D") { dropTable(argv[2]);
    } else { std::string file = argv[2];
        if (option == "-L") loadData(file);
        if (option == "-C") create(file);
        if (option == "-W") {
           std::ofstream output;
           std::string outFile = argv[3];
           output.open(outFile);
           if (output.good()) {
              loadQueries(file, output);
              output.close();
           } else {
              std::cerr << "Error with output file" << std::endl;
              return -1;
           }
        }
    }
    // All done
    return 0;
}
