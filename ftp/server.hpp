#ifndef SERVER_HPP
#define SERVER_HPP

#include "alias_for_boost.hpp"

namespace fs {

class Server
{
public:
    Server() = delete;

    explicit Server(unsigned short port):
        io_service_{},
        acceptor_{io_service_, Tcp::endpoint{Tcp::v4(), port}}
    {
        run();
    }

private:
    Io_service io_service_;
    Acceptor acceptor_;

    void run();
    void make_new_session(Tcp::socket&& soc)const;
};

}//namespace
#endif // SERVER_HPP