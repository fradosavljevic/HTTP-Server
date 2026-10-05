#ifndef SERVER_HPP
#define SERVER_HPP
#include <netinet/in.h>
#include "Connection.hpp"

class Server {
public:
    Server(uint16_t port);

    void start();
    [[nodiscard]] Connection accept() const;
private:
    int file_descriptor;
    sockaddr_in server_address{};
};

#endif
