cmake_minimum_required(VERSION 4.3)
project(HTTP_Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(HTTP_Server src/main.cpp
        src/networking/Connection.cpp
        include/networking/Connection.hpp
        include/networking/Server.hpp
        src/networking/Server.cpp
        include/http/Request.hpp
        include/http/Response.hpp
        src/http/Request.cpp
        src/http/Response.cpp
        include/http/Parser.hpp
        src/http/Parser.cpp)

target_include_directories(HTTP_Server PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)