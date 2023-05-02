cmake_minimum_required(VERSION 3.25)
project(L4_noDirs)

set(CMAKE_CXX_STANDARD 23)

add_executable(L4_noDirs Shop.cpp Controller.h Date.cpp Fruit.cpp FruitController.cpp FruitException.cpp FruitRepository.cpp TestAll.cpp TestController.cpp TestDate.cpp TestDomain.cpp TestRepository.cpp TestTime.cpp ConsoleUI.cpp Date.h Entity.h Exception.h Fruit.h FruitController.h FruitException.h FruitRepository.h Repository.h Time.h ConsoleUI.h TestAll.h TestController.h TestDate.h TestDomain.h TestRepository.h TestTime.h UI.h)
