#include <iostream>
#include <boost/array.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>

#include "client.h"

int main ()
{
        try
        {
            boost:: asio:: io_service io_service;
            TcpClient c (io_service, "127.0.0.1");

            c.execute ();

            boost:: xtime xt;
            boost:: xtime_get (&xt, boost:: TIME_UTC_);
            xt.sec += 4;
            boost:: thread:: sleep (xt);

            std:: string query (5,0);
            query.push_back (0x6);//data size low
            query.push_back (0xFF);
            query.push_back (0x3);
            query.push_back (0);//begin address hight
            query.push_back (0);//begin address low
            query.push_back (0);//qnt registers hight
            query.push_back (124);//qnt registers low

            for (int i =0; i <10; ++ i)
                c.send (query);

            c.execute ();

            boost:: xtime_get (&xt, boost:: TIME_UTC_);
            xt.sec += 1;
            boost:: thread:: sleep (xt);
        }
        catch (const boost::system::error_code& e)
        {
            std:: cout <<"Oshibka.\n" <<boost:: system:: system_error (e).what () <<std:: endl;
        }
        catch (const std::runtime_error& e)
        {
            std:: cout <<"Oshibka.\n" <<e.what () <<std:: endl;
        }
        catch (...)
        {
            std:: cout <<"Oshibka.\n" <<"the Reason is unknown." <<std:: endl;
        }
}
