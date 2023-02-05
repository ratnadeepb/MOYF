#ifndef __TCP_SERVER__
#define __TCP_SERVER__

#include <boost/asio.hpp>

namespace MOYF
{
enum class IPV {
    V4,
    V6,
};

class TCPServer
{
   private:
    IPV _ipVersion;
    int _port;
    boost::asio::io_context _ioContext;
    boost::asio::ip::tcp::acceptor _acceptor;

   private:
    void startAccept();

   public:
    TCPServer(IPV, int);
    int Run();
    ~TCPServer();
};

TCPServer::~TCPServer() {}

}  // namespace MOYF

#endif  // __TCP_SERVER__