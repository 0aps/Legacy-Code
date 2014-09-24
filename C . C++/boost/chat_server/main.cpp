//
// chat_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "chat_message.hpp"

using boost::asio::ip::tcp;

//----------------------------------------------------------------------

typedef std::deque<chat_message> chat_message_queue;

//----------------------------------------------------------------------

class chat_participant
{
public:
  virtual ~chat_participant() {}
  virtual void deliver(const chat_message& msg) = 0;
};

typedef boost::shared_ptr<chat_participant> chat_participant_ptr;

//----------------------------------------------------------------------

class chat_room
{
public:
  void join(chat_participant_ptr participant)
  {
    participants_.insert(participant);
    std::for_each(recent_msgs_.begin(), recent_msgs_.end(),
        boost::bind(&chat_participant::deliver, participant, _1));
  }

  void leave(chat_participant_ptr participant)
  {
    participants_.erase(participant);
  }

  void deliver(const chat_message& msg)
  {
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs)
      recent_msgs_.pop_front();

    std::for_each(participants_.begin(), participants_.end(),
        boost::bind(&chat_participant::deliver, _1, boost::ref(msg)));
  }

private:
  std::set<chat_participant_ptr> participants_;
  enum { max_recent_msgs = 100 };
  chat_message_queue recent_msgs_;
};

//----------------------------------------------------------------------

class chat_session
  : public chat_participant,
    public boost::enable_shared_from_this<chat_session>
{
public:
  chat_session(boost::asio::io_service& io_service, chat_room& room)
    : socket_(io_service),
      room_(room)
  {
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start(int *c)
  {
      d = c;
    room_.join(shared_from_this());
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.data(), chat_message::header_length),
        boost::bind(
          &chat_session::handle_read_header, shared_from_this(),
          boost::asio::placeholders::error));
  }

  void deliver(const chat_message& msg)
  {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
      boost::asio::async_write(socket_,
          boost::asio::buffer(write_msgs_.front().data(),
            write_msgs_.front().length()),
          boost::bind(&chat_session::handle_write, shared_from_this(),
            boost::asio::placeholders::error));
    }
  }

  void handle_read_header(const boost::system::error_code& error)
  {
    if (!error && read_msg_.decode_header())
    {
      boost::asio::async_read(socket_,
          boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
          boost::bind(&chat_session::handle_read_body, shared_from_this(),
            boost::asio::placeholders::error));
    }
    else
    {
      room_.leave(shared_from_this());
    }
  }

  void handle_read_body(const boost::system::error_code& error)
  {
    if (!error)
    {
      room_.deliver(read_msg_);
      boost::asio::async_read(socket_,
          boost::asio::buffer(read_msg_.data(), chat_message::header_length),
          boost::bind(&chat_session::handle_read_header, shared_from_this(),
            boost::asio::placeholders::error));
    }
    else
    {
      room_.leave(shared_from_this());
    }
  }

  void handle_write(const boost::system::error_code& error)
  {
    if (!error)
    {
      write_msgs_.pop_front();
      if (!write_msgs_.empty())
      {
        boost::asio::async_write(socket_,
            boost::asio::buffer(write_msgs_.front().data(),
              write_msgs_.front().length()),
            boost::bind(&chat_session::handle_write, shared_from_this(),
              boost::asio::placeholders::error));
      }
    }
    else
    {
      room_.leave(shared_from_this());
    }
  }

private:
  tcp::socket socket_;
  chat_room& room_;
  int *d;
  chat_message read_msg_;
  chat_message_queue write_msgs_;
};

typedef boost::shared_ptr<chat_session> chat_session_ptr;

//----------------------------------------------------------------------

class chat_server
{
public:
  chat_server(boost::asio::io_service& io_service,
      const tcp::endpoint& endpoint)
    : io_service_(io_service),
      acceptor_(io_service, endpoint),c(0)
  {
    start_accept();
  }

  void start_accept()
  {

        std::cout << "New connection arrived: " << c++ << std::endl;
    chat_session_ptr new_session(new chat_session(io_service_, room_));
    acceptor_.async_accept(new_session->socket(),
        boost::bind(&chat_server::handle_accept, this, new_session,
          boost::asio::placeholders::error));
  }

  void handle_accept(chat_session_ptr session,
      const boost::system::error_code& error)
  {
    if (!error)
    {
      session->start(&c);
    }

    start_accept();
  }

private:
  boost::asio::io_service& io_service_;
  int c;
  tcp::acceptor acceptor_;
  chat_room room_;
};

typedef boost::shared_ptr<chat_server> chat_server_ptr;
typedef std::list<chat_server_ptr> chat_server_list;

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      std::cerr << "Usage: chat_server <port> [<port> ...]\n";
      return 1;
    }

    boost::asio::io_service io_service;

    chat_server_list servers;
    for (int i = 1; i < argc; ++i)
    {
      using namespace std; // For atoi.
      tcp::endpoint endpoint(tcp::v4(), atoi(argv[i]));
      chat_server_ptr server(new chat_server(io_service, endpoint));
      servers.push_back(server);
    }

    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}

/*
//
// chat_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <algorithm>
#include <iostream>
#include <set>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class chat_message
{
public:
  enum { header_length = 4 };
  enum { max_body_length = 512 };

  chat_message()
    : body_length_(0)
  {
  }

  const char* data() const
  {
    return data_;
  }

  char* data()
  {
    return data_;
  }

  size_t length() const
  {
    return header_length + body_length_;
  }

  const char* body() const
  {
    return data_ + header_length;
  }

  char* body()
  {
    return data_ + header_length;
  }

  size_t body_length() const
  {
    return body_length_;
  }

  void body_length(size_t new_length)
  {
    body_length_ = new_length;
    if (body_length_ > max_body_length)
      body_length_ = max_body_length;
  }

  void encode_header()
  {
    using namespace std; // For sprintf and memcpy.
    char header[header_length + 1] = "";
    sprintf(header, "%4d", body_length_);
    memcpy(data_, header, header_length);
  }

private:
  char data_[header_length + max_body_length];
  size_t body_length_;
};


//----------------------------------------------------------------------

class chat_participant
{
public:
  virtual ~chat_participant() {}
  virtual void deliver(const chat_message& msg) = 0;
};

typedef boost::shared_ptr<chat_participant> chat_participant_ptr;

//----------------------------------------------------------------------

class connections_poll
{
public:
  void join(chat_participant_ptr participant)
  {
    participants_.insert(participant);
  }

  void leave(chat_participant_ptr participant)
  {
    participants_.erase(participant);
  }

  void deliver(const chat_message& msg)
  {
    std::for_each(participants_.begin(), participants_.end(),
        boost::bind(&chat_participant::deliver, _1, boost::ref(msg)));
  }

private:
  std::set<chat_participant_ptr> participants_;
};

//----------------------------------------------------------------------

class session
  : public chat_participant,
    public boost::enable_shared_from_this<session>
{
public:
  session(boost::asio::io_service& io_service, connections_poll& room)
    : socket_(io_service),
      poll_conec(room)
  {
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
      poll_conec.join(shared_from_this());

}

  void deliver(const chat_message& msg)
  {
          boost::asio::async_write(socket_,
          boost::asio::buffer(msg.data(),
            msg.length()),
          boost::bind(&session::handle_write, shared_from_this(),
            boost::asio::placeholders::error));

  }

  void handle_write(const boost::system::error_code& error)
  {
    if (!error)
    {
        std::cout << "No error sending message to clients." << std::endl;
    }
    else
    {
      poll_conec.leave(shared_from_this());
    }
  }

private:
  tcp::socket socket_;
  connections_poll& poll_conec;
};

//----------------------------------------------------------------------

class server
{
public:
  server(): acceptor_(io_service_)
  {
  }

    void listen(const short port)
{
        this->port = port;
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);
        acceptor_.open(endpoint.protocol());
        acceptor_.bind(endpoint);
        acceptor_.listen();
        std::cout << "Listening new connections. " << std::endl;

        start_accept();
}
void execute() { io_service_.run(); };

  void start_accept()
  {

    boost::shared_ptr<session> new_session(new session(io_service_, poll_conec));

    acceptor_.async_accept(new_session->socket(),
        boost::bind(&server::handle_accept, this, new_session,
          boost::asio::placeholders::error));
  }

  void handle_accept(boost::shared_ptr<session> session,
      const boost::system::error_code& error)
  {
    if (!error)
    {

      std::cout << "New connection arrived " << std::endl;
      session->start();
    }

    start_accept();
  }

  void BroadCast(const char*txt)
  {
      read_msg_.body_length(strlen(txt));
      memcpy(read_msg_.body(), txt, read_msg_.body_length());
      read_msg_.encode_header();
      poll_conec.deliver(read_msg_);

  }



private:
  boost::asio::io_service io_service_;
  tcp::acceptor acceptor_;
  connections_poll poll_conec;
  chat_message read_msg_;
  short port;
};

//----------------------------------------------------------------------

boost::asio::io_service io_service;
boost::asio::deadline_timer timer1(io_service);

void handler1(server *serv, std::string *msg)
{
    serv->BroadCast(msg->c_str());

    timer1.expires_from_now(boost::posix_time::seconds(1));
    timer1.async_wait(boost::bind(handler1, serv, msg));

}

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      std::cerr << "Usage: chat_server <port> [<port> ...]\n";
      return 1;
    }

      std::string msg("holaaaaa");
      server serv;

      serv.listen(atoi(argv[1]));

      timer1.expires_from_now(boost::posix_time::seconds(1));
      timer1.async_wait(boost::bind(handler1, &serv,  &msg));

      boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
      serv.execute();
      t.join();

}
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
*/
