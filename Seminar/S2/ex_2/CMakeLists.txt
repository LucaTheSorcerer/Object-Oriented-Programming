cmake_minimum_required(VERSION 3.24)
project(ex_2)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS bank.h tests.h)

add_executable(ex_2 app.cpp bank.cpp)
