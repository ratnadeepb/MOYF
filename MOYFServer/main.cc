#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main()
{
    try {
        // A context object to track i/o on the system.
        boost::asio::io_context io_context;
        // An acceptor object to accept connections.
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 1337));

        while (true) {
            std::cout << "Accepting new connection on port 1337" << std::endl;
            // Connection socket.
            tcp::socket socket(io_context);
            // Accept connection.
            acceptor.accept(socket);

            std::cout << "Client connected, sending message" << std::endl;
            std::string hello_msg = "Good day!\n";
            boost::system::error_code error;
            // Write the message into the socket and store any error.
            boost::asio::write(socket, boost::asio::buffer(hello_msg), error);
        }  // socket destructor called.
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}