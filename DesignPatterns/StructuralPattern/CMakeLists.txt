cmake_minimum_required(VERSION 3.25)
project(StructuralPattern)

set(CMAKE_CXX_STANDARD 23)

add_executable(StructuralPattern main.cpp Adapter/Adapter.h Adapter/Adapter.cpp Composite/Composite.h Composite/Composite.cpp)
