#include <array>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main(int argc, char** argv)
{
    try {
        // A context object to track i/o on the system.
        boost::asio::io_context io_context;
        // Use the resolver to create a series of IO connection streams
        // -> endpoints.
        tcp::resolver resolver{io_context};
        // tcp::resolver::results_type
        auto endpoints = resolver.resolve("127.0.0.1", "1337");

        // Create and connect to sockets.
        tcp::socket socket{io_context};
        boost::asio::connect(socket, endpoints);

        while (true) {
            // Listen for messages.
            std::array<char, 128> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);
            if (error == boost::asio::error::eof) {
                break;
            } else if (error) {
                throw boost::system::system_error(error);
            }
            std::cout.write(buf.data(), len);
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}