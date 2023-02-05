#include <MOYFNetworking/tcp_connection.hpp>
#include <boost/asio.hpp>
#include <iostream>

namespace MOYF
{
TCPConnection::TCPConnection(boost::asio::io_context& ioContext)
    : _socket(ioContext)
{
}

void TCPConnection::Start()
{
    // boost::asio::async_write(socket, boost::asio::buffer(_message));
    boost::asio::async_write(
        _socket, boost::asio::buffer(_message),
        [this](const boost::system::error_code& error,
               size_t bytesTransferred) {
            if (error) {
                std::cout << "Failed to send message" << std::endl;
            } else {
                std::cout << "Sent " << bytesTransferred << " bytes of data."
                          << std::endl;
            }
        });
}
}  // namespace MOYF
