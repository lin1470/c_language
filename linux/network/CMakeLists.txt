cmake_minimum_required(VERSION 3.9)
project(network)

set(CMAKE_CXX_STANDARD 11)

add_executable(network main.cpp socket/server.c socket/client.c)