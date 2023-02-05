#ifndef __TCP_CONNECTION__
#define __TCP_CONNECTION__
#include <boost/asio.hpp>
#include <memory>
#include <string>

namespace MOYF
{
using boost::asio::ip::tcp;
class TCPConnection
{
   private:
    /* data */
    tcp::socket _socket;
    std::string _message{"Good day!\n"};

   private:
    explicit TCPConnection(boost::asio::io_context&);

   public:
    using pointer = std::shared_ptr<TCPConnection>;
    static pointer Create(boost::asio::io_context& ioContext)
    {
        return pointer(new TCPConnection(ioContext));
    }
    void Start();
    tcp::socket& Socket() { return _socket; }
    ~TCPConnection();
};

TCPConnection::~TCPConnection() {}

}  // namespace MOYF

#endif  //  __TCP_CONNECTION__