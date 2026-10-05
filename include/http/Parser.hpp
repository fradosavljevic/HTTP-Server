#ifndef PARSER_HPP
#define PARSER_HPP
#include "Request.hpp"

class Parser {
public:
    static Request parse(const std::string& request);
};

#endif
