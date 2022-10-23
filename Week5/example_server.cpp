// Copyright Christopher Vendome (vendomcg@miamioh.edu)
#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio::ip;
using namespace boost::asio;
using namespace std;

int main() {
    // Any program that uses asio need to have at least one io_service object
    boost::asio::io_service io_service;

    // acceptor object needs to be created to listen for new connections
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 35000));

    // creates a socket
    tcp::socket socket(io_service);

    // wait and listen
    acceptor.accept(socket);
    cout << "Listening on port " << acceptor.local_endpoint().port() << endl;

    // writing the message to client
    boost::system::error_code ignored_error;
    write(socket, boost::asio::buffer("HelloWorld\n"), ignored_error);
    return 0;
}

