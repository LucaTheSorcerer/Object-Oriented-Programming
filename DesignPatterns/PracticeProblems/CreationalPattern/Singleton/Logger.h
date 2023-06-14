//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef PRACTICEPROBLEMS_LOGGER_H
#define PRACTICEPROBLEMS_LOGGER_H

#include <string>
#include <iostream>
#include <utility>

/**
 * Singleton:
    Implement a Logger class using the Singleton pattern.
    The Logger class should have a getInstance() method that returns the single instance of the Logger class.
    The Logger class should provide methods for logging messages at different levels (e.g., debug, info, error).
 */

class Logger {

protected:
    explicit Logger(std::string  value) : value_(std::move(value)) {}
    static std::shared_ptr<Logger> logger_;
    std::string value_;

public:
    Logger(Logger &other) = delete;

    void operator=(const Logger &)  = delete;

    static std::shared_ptr<Logger> getInstance(const std::string& value);

    void debug(const std::string& message);
    void info(const std::string& message);
    void error(const std::string& message);

    [[nodiscard]] std::string getMessage() const;
};


#endif //PRACTICEPROBLEMS_LOGGER_H
