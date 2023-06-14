//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef PRACTICEPROBLEMS_WEATHERSTATION_H
#define PRACTICEPROBLEMS_WEATHERSTATION_H

#include <iostream>
#include <list>
#include <string>
#include <memory>


/**
 * Create a WeatherStation class that represents a weather station.
 * Implement the Observer pattern by defining an abstract Observer class with an update() method.
 * Create concrete observer classes (e.g., TemperatureDisplay, HumidityDisplay) that display different weather
 * parameters. The WeatherStation class should have methods to register and remove observers, as well as a method to
 * update the weather parameters and notify all registered observers.
 */

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void Update(const std::string &message_from_subject) = 0;
};

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void Attach(std::shared_ptr<IObserver> observer) = 0;
    virtual void Detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void Notify() = 0;
};

class WeatherStation : public ISubject {

private:
    std::list<std::shared_ptr<IObserver>> list_observer_;
    std::string message_;

    // Weather data
    double temperature_;
    double humidity_;
    double pressure_;


public:
    virtual ~WeatherStation() {
        std::cout << "Goodbye, I was the WeatherStation.\n";
    }

    void Attach(std::shared_ptr<IObserver> observer) override;
    void Detach(std::shared_ptr<IObserver> observer) override;
    void Notify() override;

    void CreateMessage(std::string message = "Empty");
    void HowManyObservers();
    double getTemperature();
    double getHumidity();
    double getPressure();

    void setTemperature(double newTemperature);
    void setHumidity(double newHumidity);
    void setPressure(double newPressure);
};

class TemperatureDisplay : public IObserver {
private:
    double temperature_;
    std::string message_from_subject_;
    WeatherStation &weather_station_;
    static int static_number_;
    int number;

public:

    explicit TemperatureDisplay(WeatherStation &weather_station__);
    virtual ~TemperatureDisplay() {
        std::cout << "Goodbye, I was the TemperatureDisplay.\n";
    }
    void Update(const std::string &message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();

};

class HumidityDisplay : public IObserver {
private:
    double humidity_ = 10;
    std::string message_from_subject_;
    WeatherStation &weather_station_;
    static int static_number_;
    int number;

public:
    explicit HumidityDisplay(WeatherStation &weatherStation_);
    virtual ~HumidityDisplay() {
        std::cout << "Goodbye, I was the HumidityDisplay.\n";
    }
    void Update(const std::string &message_from_subject) override;
    void RemoveMeFromTheList();
    void PrintInfo();
};


#endif //PRACTICEPROBLEMS_WEATHERSTATION_H
