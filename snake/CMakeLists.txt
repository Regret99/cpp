cmake_minimum_required(VERSION 3.31)
project(snake)

set(CMAKE_CXX_STANDARD 20)

add_executable(snake main.cpp
        utils.cpp
        utils.h)
