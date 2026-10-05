#ifndef REQUEST_HPP
#define REQUEST_HPP
#include <string>
#include <unordered_map>

class Request {
public:
    Request(std::string, std::string, std::string, std::unordered_map<std::string, std::string>);
private:
    std::string method;
    std::string target;
    std::string version;
    std::unordered_map<std::string, std::string> headers;
};

#endif
