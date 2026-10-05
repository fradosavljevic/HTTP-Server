#include <iostream>

#include "networking/Connection.hpp"
#include "networking/Server.hpp"

int main() {
    Server server(12345);
    server.start();

    Connection connection = server.accept();

    ssize_t bytes_received = connection.receive();

    if (bytes_received > 0) {
        std::cout.write(connection.data(), bytes_received);
        std::cout << std::endl;
    }

    const char* response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Length: 3\r\n"
        "\r\n"
        "Hi!";

    ssize_t r = connection.send(response);

    int c = connection.close();

    return 0;
}