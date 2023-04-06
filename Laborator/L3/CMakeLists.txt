cmake_minimum_required(VERSION 3.25)
project(L3)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS DSM.h)


add_executable(L3 DSM.cpp DSM.h DSM.cpp DSM_test.cpp)
