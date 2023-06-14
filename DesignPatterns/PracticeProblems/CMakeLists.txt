cmake_minimum_required(VERSION 3.25)
project(PracticeProblems)

set(CMAKE_CXX_STANDARD 23)

add_executable(PracticeProblems main.cpp CreationalPattern/Singleton/Logger.h CreationalPattern/Singleton/Logger.cpp CreationalPattern/FactoryMethod/Game.h CreationalPattern/FactoryMethod/Game.cpp CreationalPattern/FactoryMethod/runGame.h BehaviouralPatterns/Strategy/ShoppingCart.h BehaviouralPatterns/Strategy/ShoppingCart.cpp BehaviouralPatterns/Strategy/shopping.h BehaviouralPatterns/Observer/WeatherStation.cpp BehaviouralPatterns/Observer/WeatherStation.h BehaviouralPatterns/Observer/weather_station.h)
