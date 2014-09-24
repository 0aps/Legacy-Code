#ifndef CLIENT_H
#define CLIENT_H

#include "client.h"
#include "parent.h"

/*
    Client Class
*/

typedef void (*client_message_handler)();

class client
{
    public:
        //If connect is set then client connection will be persistence.
        bool Connect;

        //time the server will take to reconnect.
        int ReconnectTime;

        //client_message_handler type must be define by you.
        //it's the function pointer to the manage client behavior after
        //receive message
        client(client_message_handler your_function);
        ~client();

        //it connects to the server address at port
        //with username and password defined
        void make_connection(const std::string server, unsigned short port,
                     const std::string username, const std::string password);

        //run client configuration
        void execute() { io_service.run(); };

    private:

        //internal functions to manage client connection
        void handleFirstConnect(const boost::system::error_code& error);
        void handleConnectNew(const boost::system::error_code& error);
        void hearbeat(const boost::system::error_code& error, size_t bytes_recvd);
        void handleloop(const boost::system::error_code& error, size_t bytes_recvd);
        void do_ping(const char *msg, const boost::system::error_code& error);
        void do_timeout(const boost::system::error_code& error);
        void do_reconnect(bool);


        boost::asio::io_service io_service;
        boost::shared_ptr<boost::asio::ip::tcp::socket> socket;
        boost::asio::deadline_timer	reconnectTimer, sendTimer, idle;
        boost::asio::ip::tcp::endpoint end_point;

        client_message_handler handler_CM;
        parent::message read_msg_;

        std::string username, password;
        time_t LastBroadcastTime;
        char buffer[256];
};

#endif // CLIENT_H
