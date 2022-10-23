// Copyright 2020 Christopher Vendome
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>

int main(int argc, char** argv) {
    mysqlpp::Connection myDB("cse278", "localhost",
            "cse278", "S3rul3z");
    mysqlpp::Query query = myDB.query();
    query << "SELECT pname, price FROM Product;";
    query.parse();
    mysqlpp::StoreQueryResult result = query.store();
    for (size_t row = 0; row < result.size(); row++) {
        std::string pname = result[row][0].c_str();
        float price = result[row][1];
        std::cout << pname << ":" << price << "\n";
    }
    return 0;
}

