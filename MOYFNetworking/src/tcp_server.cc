#include <MOYFNetworking/tcp_server.hpp>
#include <MOYFNetworking/tcp_connection.hpp>
#include <iostream>

namespace MOYF
{
using boost::asio::ip::tcp;
TCPServer::TCPServer(IPV ipv, int port)
    : _ipVersion(ipv),
      _port(std::move(port)),
      _acceptor(tcp::acceptor(
          _ioContext,
          tcp::endpoint(_ipVersion == IPV::V4 ? tcp::v4() : tcp::v6(), _port)))
{
}

int TCPServer::Run()
{
    try {
        startAccept();
        _ioContext.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1;
    }
    return 0;
}

void TCPServer::startAccept()
{
    // Create a connection.
    auto connection = TCPConnection::Create(_ioContext);

    // Asynchronously accept the connection.
}

}  // namespace MOYF
