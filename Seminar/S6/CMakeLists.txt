cmake_minimum_required(VERSION 3.21)
project(Trial)

set(CMAKE_CXX_STANDARD 20)

add_executable(Trial main.cpp CRUD_Repository.h Client.h ClientInMemoryRepository.cpp ClientController.cpp Vehicles.h)
