//
// Created by Luca Tudor on 30.04.2023.
//

#pragma once

#include <stdexcept>

namespace Time {
    class Date {
    private:
        int day;
        int month;
        int year;

    public:
        // Constructors

        //Default constructor

        explicit Date(int year = 0, int month = 0, int day = 0);

        // Copy constructor
        Date(const Date& date) = default;

        //Destructor

        ~Date() = default;

        // Getters

        [[nodiscard]] int getDay() const;
        [[nodiscard]] int getMonth() const;
        [[nodiscard]] int getYear() const;
        [[nodiscard]] std::string getDateAsString() const;

        // Setters

        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);

        //Calculate number of days in a month

        static int getNumberOfDaysInMonth(int month, int year);

        // Overloaded operators

        Date& operator=(const Date& other);
        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;

    };

}