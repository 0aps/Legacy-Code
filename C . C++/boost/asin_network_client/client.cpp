#include "client.h"
#include "parent.h"

using boost::asio::ip::tcp;

client::client(client_message_handler your_function) :
        socket(io_service), reconnectTimer(io_service), looptimer(io_service), LastBroadcastTime(0),
        handler_CM(your_function)
{
}

void client::connect(const std::string server, unsigned short port,
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


        socket.async_connect(endpoint,
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
        char buffer[1024];
        boost::asio::write(socket, boost::asio::buffer(username+'-'+password));

        try
        {
            socket.receive(boost::asio::buffer(buffer, 1024), 0);
        }catch (boost::system::system_error& error)
        {
            if (error.code() == boost::asio::error::eof)
            {
                std::cout << "Username/Password combination isn't register." << std::endl;
                 socket.close();
            }
        }

        if( socket.is_open() )
            {
              std::cout << "Connect success." << std::endl;

              rec = new receiver(io_service, handler_CM);
              rec->set_config(8888);

              looptimer.expires_from_now(boost::posix_time::seconds(1));
              looptimer.async_wait(boost::bind(&client::handleloop, this, boost::asio::placeholders::error));

            }

    }else
    {
        std::cout << "Connect failed. " << std::endl;

           if(Connect)
            {
                 std::cout << "Reconnecting ..." << std::endl;

                reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime));
                reconnectTimer.async_wait(boost::bind(&client::do_reconnect_first, this, boost::asio::placeholders::error));
            }
    }

}

void client::handleloop(const boost::system::error_code& error)
{
    if (! error)
    {

        rec->read_message(&LastBroadcastTime);

           if(Connect && LastBroadcastTime  && difftime(time(NULL), LastBroadcastTime ) >= ReconnectTime)
           {
             std::cout << "Connect failed. \n"
                       << "Reconnecting ..." << std::endl;

                reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime));
                reconnectTimer.async_wait(boost::bind(&client::do_reconnect, this, boost::asio::placeholders::error));
            }
            else
            {
                looptimer.expires_from_now(boost::posix_time::milliseconds(25));
                looptimer.async_wait(boost::bind(&client::hearbeat, this, boost::asio::placeholders::error));
            }

    }

}

void client::hearbeat(const boost::system::error_code& error)
{
    if(!error)
    {
      try
      {
            socket.send(boost::asio::buffer("PING", 4));

            looptimer.expires_from_now(boost::posix_time::milliseconds(25));
            looptimer.async_wait(boost::bind(&client::handleloop, this, boost::asio::placeholders::error));
      }
        catch(boost::system::system_error &error)
        {
                std::cout << "Connect failed. " << std::endl;

                if(Connect)
                {
                    int meh = difftime(time(NULL), LastBroadcastTime);

                    std::cout << "Reconnecting ..." << std::endl;
                    if( meh >= ReconnectTime)
                    {
                        reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime));
                        reconnectTimer.async_wait(boost::bind(&client::do_reconnect, this, boost::asio::placeholders::error));
                    }
                    else
                    {
                        reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime-meh));
                        reconnectTimer.async_wait(boost::bind(&client::do_reconnect, this, boost::asio::placeholders::error));
                    }
                }
                else
                    socket.close(), io_service.stop();

        }
    }

}

void client::handleConnectNew(const boost::system::error_code& error)
{
     if(!error)
    {
       std::cout << "Connect success." << std::endl;

       looptimer.expires_from_now(boost::posix_time::seconds(1));
       looptimer.async_wait(boost::bind(&client::handleloop, this, boost::asio::placeholders::error));

    }else
    {
        std::cout << "Connect failed. " << std::endl;

           if(Connect)
            {
                int meh = difftime(time(NULL), LastBroadcastTime);

                std::cout << "Reconnecting ..." << std::endl;
                if( meh >= ReconnectTime)
                {

                    reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime));
                    reconnectTimer.async_wait(boost::bind(&client::do_reconnect, this, boost::asio::placeholders::error));
                }
                else
                {
                    reconnectTimer.expires_from_now(boost::posix_time::seconds(ReconnectTime-meh));
                    reconnectTimer.async_wait(boost::bind(&client::do_reconnect, this, boost::asio::placeholders::error));
                }
            }
            else
                socket.cancel(), socket.close(), io_service.stop();
    }

}

void client::do_reconnect(const boost::system::error_code& error)
{

    if(socket.is_open())
    {
       socket.close();
    }

    socket.async_connect(end_point,
        boost::bind(&client::handleConnectNew, this, boost::asio::placeholders::error));
}

void client::do_reconnect_first(const boost::system::error_code& error)
{
    socket.async_connect(end_point,
        boost::bind(&client::handleFirstConnect, this, boost::asio::placeholders::error));

}
