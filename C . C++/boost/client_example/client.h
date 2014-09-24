#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <queue>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class TcpClient: private boost:: noncopyable
{
public:
    TcpClient (boost::asio::io_service& io_service,
              const std::string& server);
    void connect ();
    void send (const std::string& request);
    void execute ();
private:
    void doSend (const std::string& request);
    void handleTimerTimeout (const boost::system::error_code& err);
    void handleConnect (const boost::system::error_code& error,
                       boost:: asio:: ip:: tcp:: resolver:: iterator endpoint_iterator);
    void handleWrite (const boost::system::error_code& err);
    void handleReadTcpHeader (const boost::system::error_code& e, std:: size_t bytes_transferred);
void doClose ();
    boost::asio::io_service& io_service;
    boost:: asio:: ip:: tcp:: resolver resolver;
    boost:: asio:: ip:: tcp:: socket socket;
    boost:: asio:: ip:: tcp:: resolver:: query query;
    boost:: asio:: deadline_timer timer;
    boost:: array <unsigned char, 6> tcpHeader;
    std:: vector <unsigned char> inBuffer;
    std:: vector <unsigned char> outBuffer;
    std:: deque <std:: string> requests;
};
#endif//TCPCLIENT_H
