#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

  boost::array<char, 1024> buffer;
  std::string meh;

void handle_receive_from(const boost::system::error_code& error,
                         size_t bytes_recvd)
{
    if(!error)
    {

  std::cout  << buffer.data() << std::endl
             << bytes_recvd << std::endl;

    }

}

int main()
{
  namespace ip = boost::asio::ip;
  boost::asio::io_service io_service;

  // Client binds to any address on port 8888 (the same port on which
  // broadcast data is sent from server).
  ip::tcp::socket socket(io_service,
                         ip::tcp::endpoint(ip::tcp::v4(), 8888 ));

  ip::tcp::endpoint sender_endpoint;

  // Receive data.

    socket.async_receive_from(boost::asio::buffer(buffer), sender_endpoint,
     boost::bind(handle_receive_from,  boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));

    io_service.run();

    return 0;
}
