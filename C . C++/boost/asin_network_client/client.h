#ifndef CLIENT_H
#define CLIENT_H

#include "client.h"
#include "parent.h"

typedef void (*client_message_handler)();

class client
{
    public:
        bool Connect;
        int ReconnectTime;

        client(client_message_handler your_function);

        void connect(const std::string server, unsigned short port,
                     const std::string username, const std::string password);
        void execute() { io_service.run(); };

    private:

        void handleFirstConnect(const boost::system::error_code& error);
        void handleConnectNew(const boost::system::error_code& error);
        void hearbeat(const boost::system::error_code& error);
        void handleloop(const boost::system::error_code& error);
        void do_reconnect(const boost::system::error_code& error);
        void do_reconnect_first(const boost::system::error_code& error);


        boost::asio::io_service io_service;
        boost::asio::ip::tcp::socket socket;
        boost::asio::streambuf	read_buffer;
        boost::asio::deadline_timer	reconnectTimer, looptimer;
        boost::asio::ip::tcp::endpoint end_point;
        receiver *rec;

        client_message_handler handler_CM;
        std::string username, password;
        time_t LastBroadcastTime;
};

#endif // CLIENT_H
