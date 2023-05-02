cmake_minimum_required(VERSION 3.25)
project(L4_noDirectories)

set(CMAKE_CXX_STANDARD 23)

add_executable(L4_noDirectories Shop.cpp Date.cpp Exception.h Fruit.cpp FruitController.cpp FruitException.cpp FruitRepository.cpp TestAll.cpp TestController.cpp TestDate.cpp TestDomain.cpp TestRepository.cpp UserInterface.cpp TestTime.cpp)
