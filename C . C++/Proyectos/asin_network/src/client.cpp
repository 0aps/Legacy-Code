#include "client.h"
#include "parent.h"
#define SEND_TIME 10

using boost::asio::ip::tcp;

client::client(client_message_handler your_function) :
        reconnectTimer(io_service), sendTimer(io_service), idle(io_service), LastBroadcastTime(0),
        handler_CM(your_function)
{
    socket.reset(new boost::asio::ip::tcp::socket(io_service));
}

client::~client()
{
    if(socket->is_open())
     {
         socket->close();
     }

}

void client::make_connection(const std::string server, unsigned short port,
                     const std::string username, const std::string password)
{

    try
    {
        this->username = username;
        this->password = password;

        tcp::endpoint endpoint(boost::asio::ip::address::from_string(server), port);

        end_point = endpoint;

        std::cout << "Trying to connect to address " << endpoint.address().to_string()
                  << " at port " <<  endpoint.port() << std::endl;


        socket->async_connect(endpoint,
        boost::bind(&client::handleFirstConnect, this, boost::asio::placeholders::error));

    }
    catch(const std::exception &e)
    {
        std::cout << "Server exception: " << e.what() << std::endl;
    }

}

void client::handleFirstConnect(const boost::system::error_code& error)
{
    if(!error)
    {
        socket->send(boost::asio::buffer(username+'-'+password+'-'));

        try
        {
            socket->receive(boost::asio::buffer(buffer, 256), 0);

        }catch (boost::system::system_error& error)
        {
            if (error.code() == boost::asio::error::eof)
            {
                std::cout << "Username/Password combination isn't register." << std::endl;
                 socket->close();
            }
        }

        if( socket->is_open() )
            {
              std::cout << "Connect success." << std::endl;

              reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime));
              reconnectTimer.async_wait(boost::bind(&client::do_timeout, this, boost::asio::placeholders::error));

              sendTimer.expires_from_now(boost::posix_time::seconds(SEND_TIME));
              sendTimer.async_wait(boost::bind(&client::do_ping, this, "S", boost::asio::placeholders::error));

              boost::asio::async_read(*socket.get(),
                    boost::asio::buffer(read_msg_.data(), parent::message::header_length),
                        boost::bind(&client::handleloop, this,
                            boost::asio::placeholders::error,  boost::asio::placeholders::bytes_transferred));
            }

    }else
    {
        std::cout << "Connect failed. " << std::endl;
        if(Connect)
            {
                 std::cout << "Reconnecting ..." << std::endl;
                 do_reconnect(0);

            }
    }

}

void client::handleloop(const boost::system::error_code& error,
                                size_t bytes_recvd)
{
    if (! error && read_msg_.decode_header())
    {
        boost::asio::async_read(*socket.get(),
            boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                boost::bind(&client::hearbeat, this,
                    boost::asio::placeholders::error,  boost::asio::placeholders::bytes_transferred));

    }

}

void client::hearbeat(const boost::system::error_code& error,
                                    size_t bytes_recvd)
{
    if(!error)
    {
         if(bytes_recvd > 0)
            {
              std::cout << "Server Message: ";
              std::cout.write(read_msg_.body(), read_msg_.body_length()) << std::endl;
              LastBroadcastTime = time(NULL);

              handler_CM();
            }

          boost::asio::async_read(*socket.get(),
              boost::asio::buffer(read_msg_.data(), parent::message::header_length),
                   boost::bind(&client::handleloop, this,
                        boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

    }

}

void client::do_timeout(const boost::system::error_code& error)
{
    if(LastBroadcastTime && difftime(time(NULL), LastBroadcastTime ) >= ReconnectTime)
    {
        if(socket->is_open())
        {
            socket->close();
        }

    }else
    {
         reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime));
         reconnectTimer.async_wait(boost::bind(&client::do_timeout, this, boost::asio::placeholders::error));
    }

}

void client::do_ping(const char *msg, const boost::system::error_code& error)
{
    if(!error)
    {
        try
        {
            if(!strncmp(msg, "S", 1))
            {
                 socket->send(boost::asio::buffer(std::string(msg)));

                sendTimer.expires_from_now(boost::posix_time::seconds(SEND_TIME));
                sendTimer.async_wait(boost::bind(&client::do_ping, this, "S", boost::asio::placeholders::error));

            }
            else
            {
                 socket->send(boost::asio::buffer(std::string(msg)));
            }
        }catch(boost::system::system_error &error)
         {
            std::cout << "Connect failed. " << std::endl;
            if(Connect)
            {
               std::cout << "Reconnecting ..." << std::endl;
               do_reconnect(1);

            }else
                   socket->close(), io_service.stop();

        }
    }
}


void client::handleConnectNew(const boost::system::error_code& error)
{
     if(!error)
    {
       std::cout << "Connect success." << std::endl;

        do_ping("P", error);
        boost::asio::async_read(*socket.get(),
                    boost::asio::buffer(read_msg_.data(), parent::message::header_length),
                        boost::bind(&client::handleloop, this,
                            boost::asio::placeholders::error,  boost::asio::placeholders::bytes_transferred));

        sendTimer.expires_from_now(boost::posix_time::seconds(SEND_TIME));
        sendTimer.async_wait(boost::bind(&client::do_ping, this, "S", boost::asio::placeholders::error));

        reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime));
        reconnectTimer.async_wait(boost::bind(&client::do_timeout, this, boost::asio::placeholders::error));

    }else
    {
        std::cout << "Connect failed. " << std::endl;

           if(Connect)
            {
                std::cout << "Reconnecting ..." << std::endl;
                do_reconnect(1);
            }
            else
                socket->close(), io_service.stop();
    }

}

//false state = first reconnect
void client::do_reconnect(bool state)
{
    sendTimer.cancel();
    reconnectTimer.cancel();
    LastBroadcastTime = 0;
    idle.expires_from_now(boost::posix_time::seconds(5));
    idle.wait();

    if(state && socket->is_open())
    {
       socket->close();
    }

    socket.reset();
    socket.reset(new boost::asio::ip::tcp::socket(io_service));

    if(state)
    {
      socket->async_connect(end_point,
         boost::bind(&client::handleConnectNew, this, boost::asio::placeholders::error));
    }
    else
    {
      socket->async_connect(end_point,
        boost::bind(&client::handleFirstConnect, this, boost::asio::placeholders::error));
    }
}
