cmake_minimum_required(VERSION 3.27)
project(piscineObject)

set(CMAKE_CXX_STANDARD 11)

add_executable(piscineObject main.cpp
        includes/account.hpp
        includes/bank.hpp
        srcs/account.cpp
        srcs/bank.cpp)
