#include "http/Request.hpp"
#include <utility>
using namespace std;

Request::Request(string method, string target, string version, unordered_map<string, string> headers) {
    this->method = std::move(method);
    this->target = std::move(target);
    this->version = std::move(version);
    this->headers = std::move(headers);
}
