#include "client.h"
using boost:: asio:: ip:: tcp;

TcpClient:: TcpClient (boost::asio::io_service& io_service,
                     const std::string& server)
          : io_service (io_service),
          resolver (io_service),
          socket (io_service),
          query (server, "13"), timer (io_service)
{
    tcp:: resolver:: iterator endpoint_iterator = resolver.resolve (query);

    tcp:: endpoint endpoint = *endpoint_iterator;
    socket.async_connect (endpoint,
                         boost:: bind (&TcpClient::handleConnect, this,
                                     boost:: asio:: placeholders:: error, ++ endpoint_iterator));

}

void TcpClient:: send (const std::string& request)
{
    io_service.post (boost:: bind (&TcpClient::doSend, this, request));
}

void TcpClient:: execute ()
{
    io_service.reset ();
    int i = io_service.run ();
    //int i = io_service.poll ();
    i ++;
}

void TcpClient:: doSend (const std::string& request)
{
    //request - valid query
    bool isWriting =! requests.empty ();
    requests.push_back (request);
    if (! isWriting)
    {
        boost:: asio:: async_write (socket,
                                 boost:: asio:: buffer (requests.front ().data (),
                                                     requests.front ().length ()),
                                 boost:: bind (&TcpClient::handleWrite, this,
                                             boost:: asio:: placeholders:: error));
    }
}

void TcpClient:: handleTimerTimeout (const boost::system::error_code& err)
{
    if (err == boost:: asio:: error:: operation_aborted)//by timer
    {
        std:: cout <<"timerHandler:: operation_aborted" <<"\n";
        return;
    }
    if (err)
    {
        std:: cout <<"timer error:" <<err.message () <<"\n";
    }

    doClose ();
}

void TcpClient:: handleConnect (const boost::system::error_code& error,
                              boost:: asio:: ip:: tcp:: resolver:: iterator endpoint_iterator)
{
    if (! error)
    {
        std:: cout <<"Connect success" <<"\n";
    }
    else if (endpoint_iterator != tcp::resolver::iterator() )
    {
        socket.close ();
        tcp:: endpoint endpoint = *endpoint_iterator;
        socket.async_connect (endpoint,
                             boost:: bind (&TcpClient::handleConnect, this,
                                         boost:: asio:: placeholders:: error, ++ endpoint_iterator));
    }
    else
    {
        std:: cout <<"Connect failed" <<"\n";
    }
}

void TcpClient:: handleWrite (const boost::system::error_code& err)
{
    if (! err)
    {
        timer.cancel ();
        timer.expires_from_now (boost:: posix_time:: milliseconds (300));
        timer.async_wait (boost:: bind (&TcpClient::handleTimerTimeout, this,
                                     boost:: asio:: placeholders:: error));

        std:: cout <<"!!! handle_write" <<socket.is_open () <<"\n";
        boost:: asio:: async_read (socket,
                                boost:: asio:: buffer (tcpHeader, 6),
                                boost:: asio:: transfer_at_least (6),
                                boost:: bind (&TcpClient::handleReadTcpHeader, this,
                                            boost:: asio:: placeholders:: error,
                                            boost::asio::placeholders::bytes_transferred)
                                );
    }
    else
    {
        std:: cout <<"Error:" <<err.message () <<"\n";
        doClose ();
    }
}

void TcpClient:: handleReadTcpHeader (const boost::system::error_code& e, std:: size_t bytes_transferred)
{
    std:: cout <<"handleReadTcpHeader" <<"\n";
    if (! e)
    {
        std:: cout <<"handleReadTcpHeader2" <<"\n";

        size_t sizeModbus = static_cast <size_t> (tcpHeader [5]);
        bool isValid = (tcpHeader [0] == 0 && tcpHeader [1] == 0 &&
                        tcpHeader [2] == 0 && tcpHeader [3] == 0 &&
                        tcpHeader [4] == 0 && sizeModbus> 3);
        if (isValid)//invalid header - connection shutdown
        {
            inBuffer.resize (sizeModbus, '\0 ');
            std:: cout <<"handleReadTcpHeader:: async" <<"\n";
        }
        else
        {
            std:: cout <<"Error:! isValid" <<std:: endl;
            doClose ();
        }
    }
    else
    {
        std:: cout <<"Error:" <<e.message () <<std:: endl;
    }
}

void TcpClient:: doClose ()
{
    std:: cout <<"doClose:" <<std:: endl;
    socket.close ();
}
