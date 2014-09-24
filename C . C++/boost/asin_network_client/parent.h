#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <map>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>


class receiver
{
  private:

   typedef void (*client_message_handler)();
        client_message_handler handler_CM;

  boost::asio::ip::udp::socket socket_;
  boost::asio::ip::udp::endpoint sender_endpoint_;
  enum { max_length = 1024 };
   short multicast_port;
  char data_[max_length];

public:

  receiver(boost::asio::io_service& io_service, client_message_handler handler_message):
                    socket_(io_service), handler_CM(handler_message)
    {
    }


 void set_config(const short multicast_port)
  {
      this->multicast_port = multicast_port;

      boost::asio::ip::udp::endpoint listen_endpoint(
            boost::asio::ip::udp::v4(), multicast_port);

      socket_.open(listen_endpoint.protocol());
      socket_.bind(listen_endpoint);

  }

  void read_message(time_t* LastBroadcastTime)
  {
       boost::asio::ip::udp::endpoint sender_endpoint;

      socket_.async_receive_from(
            boost::asio::buffer(data_, max_length), sender_endpoint,
            boost::bind(&receiver::handle_receive_from, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred, LastBroadcastTime));
  }

  void handle_receive_from(const boost::system::error_code& error,
      size_t bytes_recvd, time_t* LastBroadcastTime)
  {
        if(bytes_recvd > 0)
        {
              std::cout << "Server Message: ";
              std::cout.write(data_, bytes_recvd) << std::endl;
              *LastBroadcastTime = time(NULL);

              handler_CM();
        }

  }


};


#endif // PARENT_H_INCLUDED
