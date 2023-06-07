cmake_minimum_required(VERSION 3.25)
project(Test)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(Test main.cpp)
target_link_libraries(Test
        Qt5::Widgets
        )

