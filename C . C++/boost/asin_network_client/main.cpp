#include <iostream>
#include "client.h"

using namespace std;

void client_message_handler_func () {
  //client is doing something
  std::cout << "client works hard" << std::endl;
}

int main(int argc, char **argv)
{
    if( argc > 6)
    {
        std::string add(argv[1]), user(argv[3]), pass(argv[4]);
        client cliente(&client_message_handler_func);
        cliente.ReconnectTime = atoi(argv[5]);
        cliente.Connect = (bool)atoi(argv[6]);
        cliente.connect(add, atoi(argv[2]), user, pass);

        cliente.execute();
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




