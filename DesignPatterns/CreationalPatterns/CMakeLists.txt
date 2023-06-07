cmake_minimum_required(VERSION 3.25)
project(CreationalPatterns)

set(CMAKE_CXX_STANDARD 23)

add_executable(CreationalPatterns main.cpp Singleton/Singleton.cpp FactoryMethod/FactoryMethod.h FactoryMethod/FactoryMethod.cpp)
