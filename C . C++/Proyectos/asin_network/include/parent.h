#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>


namespace parent
{

    class message
    {
        public:
            enum { header_length = 4 };
            enum { max_body_length = 512 };

            message();
            const char* data() const;
            char* data();
            const char* body() const;
            char* body();
            size_t length() const;
            size_t body_length() const;
            void body_length(size_t new_length);
            void encode_header();
            bool decode_header();

        private:
            char data_[header_length + max_body_length];
            size_t body_length_;
    };

    class c_participant
    {
        public:
            virtual ~c_participant() {};
            virtual void deliver(const message& msg) = 0;

             time_t state;
    };


    class connections_poll
    {
        public:
        void join(boost::shared_ptr<c_participant> participant);
        void leave(boost::shared_ptr<c_participant> participant);
        void deliver(const message& msg);
        void setTime(boost::shared_ptr<c_participant> participant);
        time_t getTime(boost::shared_ptr<c_participant> participant);
        std::queue< boost::shared_ptr<c_participant> > toDelete;

        private:
          std::set< boost::shared_ptr<c_participant> > participants_;

    };

    class session :
                    public c_participant,
                    public boost::enable_shared_from_this<session>
    {
        public:
            session(boost::asio::io_service& io_service, connections_poll& room);

            boost::asio::ip::tcp::socket& socket();
            void start(bool Authenticate, std::map<std::string, std::string> UserList);

        private:

            void handle_read(const boost::system::error_code& error,
                            size_t bytes_transferred, bool Authenticate,
                            std::map<std::string, std::string> UserList);

            void handle_write(const boost::system::error_code& error);
            void handle_write2(const boost::system::error_code& error);

            void deliver(const message& msg);

            boost::asio::ip::tcp::socket socket_;
            connections_poll& poll_conec;

            enum { max_length = 256 };
            char data_[max_length];
            int ping, send;
    };

}



#endif // PARENT_H_INCLUDED
