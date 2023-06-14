//
// Created by Luca Tudor on 14.06.2023.
//

#include "Logger.h"


//static variable of class logger

std::shared_ptr<Logger> Logger::logger_ = nullptr;

std::shared_ptr<Logger> Logger::getInstance(const std::string &value) {
    if(logger_ == nullptr) {
        logger_ = std::shared_ptr<Logger>(new Logger(value));
    }

    return logger_;
}

void Logger::debug(const std::string &message) {

    std::cout << "Debug: " << message << std::endl;
}

void Logger::info(const std::string &message) {

    std::cout << "Info: " << message << std::endl;
}

void Logger::error(const std::string &message) {

    std::cout << "Error: " << message << std::endl;
}

std::string Logger::getMessage() const {
    return value_;
}
