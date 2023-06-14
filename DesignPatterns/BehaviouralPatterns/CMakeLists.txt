cmake_minimum_required(VERSION 3.25)
project(BehaviouralPatterns)

set(CMAKE_CXX_STANDARD 23)

add_executable(BehaviouralPatterns main.cpp Strategy/Strategy.h Strategy/Strategy.cpp Observer/Observer.h Observer/Observer.cpp)
