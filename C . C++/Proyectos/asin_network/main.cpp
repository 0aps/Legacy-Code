
#include <iostream>
#include "client.h"

#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

using namespace std;

void client_message_handler_func () {
  //client is doing something
  std::cout << "I'm the message callback function of the client." << std::endl;
}

boost::asio::io_service io_service;
boost::asio::deadline_timer timer1(io_service);

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}

void handler1()
{
    std::cout << "\t\t\t\t\t\t\t\t\t" << currentDateTime() << std::endl;

    timer1.expires_from_now(boost::posix_time::seconds(1));
    timer1.async_wait(boost::bind(handler1));
}

int main(int argc, char **argv)
{
    if( argc > 6)
    {
        std::string add(argv[1]), user(argv[3]), pass(argv[4]);
        client cliente(&client_message_handler_func);
        cliente.ReconnectTime = atoi(argv[5]);
        cliente.Connect = (bool)atoi(argv[6]);
        cliente.make_connection(add, atoi(argv[2]), user, pass);

        timer1.expires_from_now(boost::posix_time::seconds(1));
        timer1.async_wait(boost::bind(handler1));

        boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
        cliente.execute();
        t.join();

    }else
    {
        std::cout << "\n\nClient Class implementation example.\n"
                  << "The client will connect to an internal address and receive it message.\n"
                  << "If client connect argument is set to 1 the connections will be persistence\n"
                  << "otherwise it will not. Finally, the reconnect_time is set in seconds.\n\n"
                  << "client.exe server_address port username password reconnect_time connect_persistence\n"
                  << "[or]\n"
                  << "./client server_address port username password reconnect_time connect_persistence\n\n"
                  << "Example: client.exe 192.168.1.2 3250 feynman physics 3 1\n\n";
    }


    return 0;
}
/*
#include <iostream>
#include "server.h"

#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

using namespace std;

boost::asio::io_service io_service;
boost::asio::deadline_timer timer1(io_service);


const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}

void handler1(server *serv, std::string *msg)
{
    serv->BroadCast(msg->c_str());
    std::cout << "Current Time: " << currentDateTime() << std::endl;

    timer1.expires_from_now(boost::posix_time::seconds(1));
    timer1.async_wait(boost::bind(handler1, serv, msg));

}

int main(int argc, char**argv)
{
    if(argc > 4)
    {
        std::string msg(argv[1]), path(argv[4]);

        server serv(path);
        serv.Authenticate = (bool)atoi(argv[3]);
        serv.listen(atoi(argv[2]));

        timer1.expires_from_now(boost::posix_time::seconds(1));
        timer1.async_wait(boost::bind(handler1, &serv,  &msg));

        boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
        serv.execute();
        t.join();
    }else
        std::cout << "\n\nServer Class implementation example. \n"
                  << "The server will listen to a port and send a message every 2 seconds to the clients connected in the lan.\n\n"
                  <<  "server.exe \"message_to_be_send\" port_to_listen authenticate user_files_path \n[or]\n"
                  <<  "./server \"message_to_be_send\" port_to_listen authenticate user_files_path\n\nExample: "
                  <<  "server.exe \"Isn't R. Feynman the most greatest physicist ever?\" 3250 1 user.txt\n\n";


    return 0;
}*/

/*
#include <iostream>
#include "client.h"

#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

using namespace std;

void client_message_handler_func () {
  //client is doing something
  std::cout << "I'm the message callback function of the client." << std::endl;
}

boost::asio::io_service io_service;
boost::asio::deadline_timer timer1(io_service);

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}

void handler1()
{
    std::cout << "\t\t\t\t\t\t\t\t\t" << currentDateTime() << std::endl;

    timer1.expires_from_now(boost::posix_time::seconds(1));
    timer1.async_wait(boost::bind(handler1));
}

int main(int argc, char **argv)
{
    if( argc > 6)
    {
        std::string add(argv[1]), user(argv[3]), pass(argv[4]);
        client cliente(&client_message_handler_func);
        cliente.ReconnectTime = atoi(argv[5]);
        cliente.Connect = (bool)atoi(argv[6]);
        cliente.make_connection(add, atoi(argv[2]), user, pass);

        timer1.expires_from_now(boost::posix_time::seconds(1));
        timer1.async_wait(boost::bind(handler1));

        boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
        cliente.execute();
        t.join();

    }else
    {
        std::cout << "\n\nClient Class implementation example.\n"
                  << "The client will connect to an internal address and receive it message.\n"
                  << "If client connect argument is set to 1 the connections will be persistence\n"
                  << "otherwise it will not. Finally, the reconnect_time is set in seconds.\n\n"
                  << "client.exe server_address port username password reconnect_time connect_persistence\n"
                  << "[or]\n"
                  << "./client server_address port username password reconnect_time connect_persistence\n\n"
                  << "Example: client.exe 192.168.1.2 3250 feynman physics 3 1\n\n";
    }


    return 0;
}
*/
