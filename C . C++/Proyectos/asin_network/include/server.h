#ifndef SERVER_H
#define SERVER_H

#include "parent.h"

/*
    Server Class
*/


class server
{
    public:

        bool Authenticate;
        std::string path;

        //Constructor takes the path to the files where usernames and passwords are defined.
        server(std::string path);
        ~server();

        //It sends a message to the clients.
        void BroadCast(const char *txt);

        //The server will listen connections on port.
        void listen(const short port);

        //run the server until it gets out of work.
        void execute() { io_service_.run(); };


    private:

        //accepted connections will go here
        void handle_accept(boost::shared_ptr<parent::session> new_session,
                            const boost::system::error_code& error);

        void start_acept();

        std::map <std::string, std::string> UserList;
        short port, same_msg;

        //boost asio variables for IO
        boost::asio::io_service io_service_;
        boost::asio::ip::tcp::acceptor acceptor_;
        parent::connections_poll poll_conec;
        parent::message read_msg_;
};

#endif // SERVER_H
