#include <sstream>
#include "http/Parser.hpp"

Request Parser::parse(const std::string &request) {
    size_t end = request.find('\n');
    std::string request_line = request.substr(0, end);

    std::istringstream stream(request_line);

    std::string method;
    std::string target;
    std::string version;

    stream >> method >> target >> version;

    std::unordered_map<std::string, std::string> headers;

    std::string header_line;

    while (std::getline(stream, header_line)) {
        if (header_line == "\r")
            break;

        size_t separator = header_line.find(':');

        std::string key = header_line.substr(0, separator);
        std::string value = header_line.substr(separator + 1);

        if (!value.empty() && value[0] == ' ')
            value.erase(0, 1);

        if (!key.empty())
            headers[key] = value;
    }

    return {
        std::move(method),
        std::move(target),
        std::move(version),
        std::move(headers)
    };
}
