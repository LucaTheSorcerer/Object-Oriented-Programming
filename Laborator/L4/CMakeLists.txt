cmake_minimum_required(VERSION 3.25)
project(L4)

set(CMAKE_CXX_STANDARD 20)

add_executable(L4 Shop.cpp Entity/src/Fruit.cpp Entity/src/Fruit.h Repository/src/FruitRepository.h Repository/src/FruitRepository.cpp Controller/src/Controller.cpp Controller/src/Controller.h Console/src/Console.h Console/src/Console.cpp Exception/src/FruitException.h Exception/src/FruitException.cpp Entity/src/Entity.h Console/src/UI.h Date/src/Date/Date.cpp Date/src/Date/Date.h Date/src/Time.h Entity/test/testEntity.cpp Entity/test/testEntity.h Test/testAllComponents.h Test/testAllComponents.cpp)
