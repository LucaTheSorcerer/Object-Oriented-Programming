cmake_minimum_required(VERSION 3.25)
project(L4)

set(CMAKE_CXX_STANDARD 20)

add_executable(L4 Shop.cpp Entity/Fruit.cpp Entity/Fruit.h Repository/fruit_repository.h Repository/fruit_repository.cpp Repository/FileRepository/fruit_file_repository.cpp Controller/controller.cpp Controller/controller.h Console/console.h Console/console.cpp Exception/FruitException.h Exception/FruitException.cpp)
