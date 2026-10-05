#ifndef CONNECTION_HPP
#define CONNECTION_HPP
#include <sys/types.h>

class Connection {
public:
    Connection(int file_descriptor);

    [[nodiscard]] ssize_t send(const char *) const;
    ssize_t receive();
    [[nodiscard]] const char* data() const;
    [[nodiscard]] int close() const;
private:
    int file_descriptor;
    char buffer[1024]{};
};

#endif
