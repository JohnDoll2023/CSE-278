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
 
    // Variable to build query string
    std::string qString;
    
    // Get user input for query
    while(/* reading in lines */ && /* some conditon */) { 
        // Create a query

        try{
            // Check query is correct

            // Execute query

            // Results is a 2D vector of mysqlpp::String objects.
            // Print the results.
            std::cout << "-----Query Result-----" << std::endl;
            for (size_t row = 0; (row < /* result variable */.size()); row++) {
                /*
                 * Some logic to display the results
                 */                
            }
            std::cout << "------End Result------" << std::endl;
        } catch(mysqlpp::BadQuery e) {
            std::cerr << "Query: " << qString <<std::endl;
            std::cerr << "Query is not correct SQL syntax" <<std::endl;
        }
    }
}

std::string generateLoadQuery(std::string& line){
    // Create base insert query string

    // Split file on commas

    // Start building query from split files (table name)

    // Strings to hold attributes and values

    // Build attribute and value strings

    // Form full query string

}

void loadData(std::string& path){
    // Open file stream
    
    // Connect to database with: database, server, userID, password


    // Some necessary variables for the file IO

    // Read file line-by-line
    while (/* reading lines */) {
        // Create query string from current line

        // Create mysql++ query

        try{
            // Check query is correct

            //Execute Query
            std::cout << /* feedback it worked - format on assignment */;   
        } catch(mysqlpp::BadQuery e) {
            std::cerr << "Query: " << queryStr<<std::endl;
            std::cerr << "Query is not correct SQL syntax" <<std::endl;
        }
    }
    
}

int main(int argc, char *argv[]) {
    // Ensure arguments are specified
    if(/* some condition */){
        std::cerr << /* some message */;
        return 1;
    }

    std::string option = argv[1];

    if(/* some condition */) {
        /* do something */
    } 
    else if (/* some condition */ && /* some other check */) {
        /* do something else */
    }
    else {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

    // All done
    return 0; 
}
