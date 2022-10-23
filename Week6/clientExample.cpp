// Copyright 2020 Christopher Vendome (vendomcg@miamioh.edu)
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

using namespace boost::asio::ip;

int main() {
    // Any program that uses asio need to have at least one io_service object
    boost::asio::io_service io_service;
    // Create endpoint specifying the server IP address
    // and application port number
    tcp::endpoint endpoint(address::from_string("127.0.0.1"), 35000);
    // Create socket and connect it to the endpoint
    socket socket(io_service); 
    socket.connect(endpoint);
    // Loop through the server response
    while (true) {
      boost::array<char, 128> buf;
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
      // Check whether message is complete or experienced an error
        if (error == boost::asio::error::eof) {
            break;
        } else if (error) {
            throw boost::system::system_error(error);
        }
      // Write the message to stdout
        std::cout.write(buf.data(), len);
    }
    socket.close();
    return 0;
}

