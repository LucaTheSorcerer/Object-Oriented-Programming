cmake_minimum_required(VERSION 3.24)
project(L2)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS 1_money.h)

add_executable(L2  1_money_test.cpp 1_money.cpp)
