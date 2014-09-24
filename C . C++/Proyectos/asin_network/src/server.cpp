#include "server.h"
#include "parent.h"

server::server(std::string path): path(path), acceptor_(io_service_), same_msg(0)
{
    std::ifstream ifo;
    ifo.exceptions( std::ifstream::badbit );

    try
    {
        std::string username, password;
        ifo.open(path.c_str());

        if(ifo.is_open())
            while(std::getline(ifo, username, ',') && std::getline(ifo, password))
            {
                 password.resize(password.size()-1);
                 UserList[username] = password;
            }
         else
         {
             std::cerr << "Couldn't open " << path << " file." << std::endl;
             exit(0);
         }

    }catch( std::ifstream::failure e)
    {
        std::cerr << "Something happend with " << path << " file.\n"
                  << e.what() << std::endl;
        exit(0);
    }

    ifo.close();
}

server::~server()
{
     std::ofstream ouf(path.c_str());
     std::map<std::string, std::string>::iterator it;

    if(!ouf.is_open())
    {
        std::cerr << "Couldn't open " << path << std::endl;
    }

    for(it = UserList.begin(); it != UserList.end(); ++it)
    {
        ouf << it->first << "," << it->second << "," << std::endl;
    }

    ouf.close();
}

void server::listen(const short port)
{
        this->port = port;
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);
        acceptor_.open(endpoint.protocol());
        acceptor_.bind(endpoint);
        acceptor_.listen();

        start_acept();
}

void server::start_acept()
{
        std::cout << "Listening new connections ..." << std::endl;

        boost::shared_ptr<parent::session> new_session(new parent::session(io_service_, poll_conec));

        acceptor_.async_accept(new_session->socket(),
                                boost::bind(&server::handle_accept, this, new_session,
                                boost::asio::placeholders::error));
}

void server::handle_accept(boost::shared_ptr<parent::session> new_session,
      const boost::system::error_code& error)
{
    if (!error)
    {
        std::cout << "New connection arrived." << std::endl;
        new_session->start(Authenticate, UserList);
    }

    start_acept();
}

void server::BroadCast(const char *txt)
{
        if( !same_msg )
        {
          read_msg_.body_length(strlen(txt));
          memcpy(read_msg_.body(), txt, read_msg_.body_length());
          read_msg_.encode_header();
          same_msg = 1;
        }

        poll_conec.deliver(read_msg_);
}
