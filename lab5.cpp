// Copyright 2020 John Doll
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace boost::asio::ip;
using namespace std;
// Function to return date
string make_daytime_string() {
  char date[26];
  time_t now = time(0);
  return ctime_r(&now, date);
}

int checkPort(string num) {
  int portNum;

  try {
    portNum = stoi(num);
  }
  catch (exception& e) {
    cerr << "Must supply port number" << endl;
    return -1;
  }

  return portNum;
}


int main(int argc, char** argv) {
    // Check user inputs for port number
    if (argc != 2) {
       cerr << "Must supply port number" << endl;  return 0;  }
    // Validate input is numeric
    string check = argv[1];
    int port = checkPort(check);
    if (port == -1)  return 0;
    // Check port number is valid
    if (port <= 1024 || port > 65535) {
       cerr << "Cannot use privileged ports" << endl;  return 0;  }
    // Create the endpoint for the server
    tcp::endpoint endpoint(address::from_string("127.0.0.1"), 35000);
    // Create the socket (and any other necessary objects)
    boost::asio::io_service io_service;
    tcp::socket socket(io_service);
    // Wait and listen for a client to connect
    socket.connect(endpoint);
    // Prepare message to send back to client
    while (true) {
        string message = make_daytime_string();
        boost::system::error_code error;
        // Write the message for current time to the socket
        if (error == boost::asio::error::eof) {
            break;
        } else if (error) {
            throw boost::system::system_error(error);  }
        cout << message << endl;
    }
    socket.close();
    return 0;
}

