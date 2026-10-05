#include "networking/Server.hpp"
#include <iostream>
#include <sys/socket.h>

Server::Server(uint16_t port) {
    file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);
}

void Server::start() {
    int bind_status = bind(file_descriptor, reinterpret_cast<sockaddr *>(&server_address), sizeof(server_address));
    if (bind_status == -1) {
        std::cout << "Error while binding" << std::endl;
        return;
    }
    int listen_status = listen(file_descriptor, SOMAXCONN);
    if (listen_status == -1) {
        std::cout << "Error while listening" << std::endl;
    }
}

Connection Server::accept() const {
    int accept_fd = ::accept(file_descriptor, nullptr, nullptr);
    if (accept_fd == -1) {
        std::cout << "Error while accepting" << std::endl;
    }
    return {accept_fd};
}
