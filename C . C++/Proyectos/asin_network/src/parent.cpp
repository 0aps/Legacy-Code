#include "parent.h"

using namespace parent;


/*
    Message
*/

message::message() : body_length_(0) {}

const char* message::data() const
{
        return data_;
}

char* message::data()
{
        return data_;
}

const char* message::body() const
{
        return data_ + header_length;
}

char* message::body()
{
        return data_ + header_length;
}

size_t message::length() const
{
        return header_length + body_length_;
}

size_t message::body_length() const
{
        return body_length_;
}

void message::body_length(size_t new_length)
{
        body_length_ = new_length;

        if (body_length_ > max_body_length)
            body_length_ = max_body_length;
}

void message::encode_header()
{
    using namespace std; // For sprintf and memcpy.

        char header[header_length + 1] = "";
        sprintf(header, "%4d", body_length_);
        memcpy(data_, header, header_length);
}

  bool message::decode_header()
  {
    using namespace std; // For strncat and atoi.
    char header[header_length + 1] = "";
    strncat(header, data_, header_length);
    body_length_ = atoi(header);
    if (body_length_ > max_body_length)
    {
      body_length_ = 0;
      return false;
    }
    return true;
  }


/*

    Connections Polls

*/

void connections_poll::join(boost::shared_ptr<c_participant> participant)
{
        participants_.insert(participant);
}

void connections_poll::leave(boost::shared_ptr<c_participant> participant)
{
        if(participants_.count(participant ) > 0)
            participants_.erase(participant);
}

void connections_poll::deliver(const message& msg)
{
        if(!participants_.empty())
        {
            std::for_each(participants_.begin(), participants_.end(),
                boost::bind(&c_participant::deliver, _1, boost::ref(msg)));

            while(!toDelete.empty())
            {
                connections_poll::leave(toDelete.front());
                toDelete.pop();
            }

            std::cout << "No error sending message to clients."
                      << "\nConnections: " << participants_.size() <<  std::endl;
        }
        else
        {
            std::cout << "No clients connected." << std::endl;
        }

}

void connections_poll::setTime(boost::shared_ptr<c_participant> participant)
{

    std::set< boost::shared_ptr<c_participant> >::iterator iter = participants_.find(participant);
    if (iter != participants_.end())
    {
        (*iter)->state = time(NULL);
    }

}

time_t connections_poll::getTime(boost::shared_ptr<c_participant> participant)
{

    std::set< boost::shared_ptr<c_participant> >::iterator iter = participants_.find(participant);
    if (iter != participants_.end())
    {
        return (*iter)->state;
    }
    else return 0;

}


/*

    Session

*/



session::session(boost::asio::io_service& io_service, connections_poll& room)
            : socket_(io_service), poll_conec(room) {memset (data_, '0', 256);   }


boost::asio::ip::tcp::socket&  session::socket()
{
        return socket_;
}

void session::deliver(const message& msg)
{
       if(socket_.is_open())
         {
            boost::asio::async_write(socket_,
                boost::asio::buffer(msg.data(), msg.length()),
                    boost::bind(&session::handle_write2, shared_from_this(),
                        boost::asio::placeholders::error));
        }
}

void session::start(bool Authenticate, std::map<std::string, std::string> UserList)
{
    if(socket_.is_open())
    {
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
            boost::bind(&session::handle_read, shared_from_this(),
                boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred, Authenticate, UserList));
    }

}

void session::handle_read(const boost::system::error_code& error,
                            size_t bytes_transferred, bool Authenticate,
                            std::map<std::string, std::string> UserList)
{
        if (!error)
        {
            ping = strncmp(data_, "P", bytes_transferred);
            send = strncmp(data_, "S", bytes_transferred);

                //figure if the Authentication is set, to compare user/pass combination
                //agains userlist
                if(Authenticate && ping && send)
                {
                    std::string user(data_), pass;
                    unsigned short delim = user.find('-');


                    pass = user.substr(delim+1, user.substr(delim+1).find('-'));
                    user = user.substr(0, delim );

                    if( UserList.find(user) != UserList.end() && UserList[user] == pass  )
                    {
                        std::cout << "Client: " << user << " connected. " << std::endl;

                            boost::asio::async_write(socket_,
                                boost::asio::buffer(data_, bytes_transferred),
                                    boost::bind(&session::handle_write, this,
                                        boost::asio::placeholders::error));


                    poll_conec.join(shared_from_this());
                    poll_conec.setTime(shared_from_this());


                    }else
                    {

                        std::cout << "[" << user << "]" << "[" << pass << "]." << std::endl;
                        std::cout << "Username/Password combination isn't register." << std::endl;


                        socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
                        socket_.close();
                    }
                }else if(ping && send)
                {
                    //I let everybody in
                        std::string user(data_);
                        user = user.substr(0, user.find('-'));

                        std::cout << "Client: " << user << " connected. " << std::endl;

                        boost::asio::async_write(socket_,
                            boost::asio::buffer(data_, bytes_transferred),
                                boost::bind(&session::handle_write, this,
                                    boost::asio::placeholders::error));

                        poll_conec.join(shared_from_this());
                        poll_conec.setTime(shared_from_this());

                }else if(!ping)
                {
                    poll_conec.join(shared_from_this());
                    poll_conec.setTime(shared_from_this());
                }
                else if(!send)
                {
                    poll_conec.setTime(shared_from_this());
                }

            if(socket_.is_open())
             {
                   socket_.async_read_some(boost::asio::buffer(data_, max_length),
                    boost::bind(&session::handle_read, shared_from_this(),
                        boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred, Authenticate, UserList));
             }
         }
          else
          {
           //     std::cout << error.message() << std::endl
           //         << error.category().name() << std::endl;
          }

}

void session::handle_write(const boost::system::error_code& error)
{
  if (!error)
  {
  }
  else
  {
     poll_conec.toDelete.push(shared_from_this());
  }

}

void session::handle_write2(const boost::system::error_code& error)
{
    if (!error)
    {
        if( difftime( time(NULL), poll_conec.getTime(shared_from_this()) ) > 30  )
        {
            poll_conec.toDelete.push(shared_from_this());
        }
            //do whatever you want after sending msg to clients.
    }
    else
    {
       poll_conec.toDelete.push(shared_from_this());
    }
}
