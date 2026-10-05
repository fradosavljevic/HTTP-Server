#include "networking/Connection.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

Connection::Connection(int file_descriptor) {
    this->file_descriptor = file_descriptor;
}

ssize_t Connection::send(const char *msg) const {
    ssize_t send_status = ::send(file_descriptor, msg, strlen(msg), 0);
    return send_status;
}

ssize_t Connection::receive() {
    ssize_t receive_status = recv(file_descriptor, buffer, sizeof(buffer), 0);
    return receive_status;
}

const char *Connection::data() const {
    return buffer;
}

int Connection::close() const {
    return ::close(file_descriptor);
}
