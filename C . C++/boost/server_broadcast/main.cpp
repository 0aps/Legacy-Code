#include <boost/asio.hpp>
#include <boost/bind.hpp>

void handle_send_to(const boost::system::error_code& error)
{
    if(!error)
    {
        std::cout << "no hubo error.";
    }

}

int main()
{
  namespace ip = boost::asio::ip;
  boost::asio::io_service io_service;

  // Server binds to any address and any port.
  ip::udp::socket socket(io_service,
                         ip::udp::endpoint(ip::udp::v4(), 0));
  socket.set_option(boost::asio::socket_base::broadcast(true));

  // Broadcast will go to port 8888.
  ip::udp::endpoint broadcast_endpoint(ip::address_v4::broadcast(), 8888);

  // Broadcast data.
  boost::array<char, 4> buffer = {'a', 'b', 'c', 'd'};
  std::string hi = "hola";

  socket.async_send_to(boost::asio::buffer(hi), broadcast_endpoint,
            boost::bind(handle_send_to, boost::asio::placeholders::error));

    io_service.run();

    return 0;

}

