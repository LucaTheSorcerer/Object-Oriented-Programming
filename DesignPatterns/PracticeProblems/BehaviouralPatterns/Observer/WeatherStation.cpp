//
// Created by Luca Tudor on 14.06.2023.
//

#include "WeatherStation.h"

#include <utility>

void WeatherStation::Attach(std::shared_ptr<IObserver> observer) {
    list_observer_.push_back(observer);
}

void WeatherStation::Detach(std::shared_ptr<IObserver> observer) {
    list_observer_.remove(observer);
}

void WeatherStation::Notify() {
    std::list<std::shared_ptr<IObserver>>::iterator iterator = list_observer_.begin();
    HowManyObservers();
    while(iterator != list_observer_.end()) {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

void WeatherStation::CreateMessage(std::string message) {
    this->message_ = std::move(message);
    Notify();
}

void WeatherStation::HowManyObservers() {
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}

double WeatherStation::getTemperature() {

    return this->temperature_;
}

double WeatherStation::getHumidity() {

    return this->humidity_;
}

double WeatherStation::getPressure() {

    return this->pressure_;
}

void WeatherStation::setTemperature(double newTemperature) {

}

void WeatherStation::setHumidity(double newHumidity) {

}

void WeatherStation::setPressure(double newPressure) {

}

int TemperatureDisplay::static_number_ = 0;

TemperatureDisplay::TemperatureDisplay(WeatherStation &weatherStation_) : weather_station_(weatherStation_) {

    this->temperature_ = 10;
    this->weather_station_.Attach(std::make_shared<TemperatureDisplay>(*this));
    std::cout << "Hi, I'm the TemperatureDisplay \"" << ++TemperatureDisplay::static_number_ << "\".\n";
    this->number = TemperatureDisplay::static_number_;
}

void TemperatureDisplay::Update(const std::string &message_from_subject) {
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void TemperatureDisplay::RemoveMeFromTheList() {
    weather_station_.Detach(std::make_shared<TemperatureDisplay>(*this));
    std::cout << "TemperatureDisplay \"" << number << "\" removed from the list.\n";
}

void TemperatureDisplay::PrintInfo() {
std::cout << "TemperatureDisplay \"" << this->number << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}

int HumidityDisplay::static_number_ = 0;

HumidityDisplay::HumidityDisplay(WeatherStation &weatherStation_) : weather_station_(weatherStation_){

    this->humidity_ = 10;
    this->weather_station_.Attach(std::make_shared<HumidityDisplay>(*this));
    std::cout << "Hi, I'm the HumidityDisplay \"" << ++HumidityDisplay::static_number_ << "\".\n";
    this->number = HumidityDisplay::static_number_;
}

void HumidityDisplay::Update(const std::string &message_from_subject) {
    message_from_subject_ = message_from_subject;
    PrintInfo();
}

void HumidityDisplay::RemoveMeFromTheList() {
    weather_station_.Detach(std::make_shared<HumidityDisplay>(*this));
    std::cout << "HumidityDisplay \"" << number << "\" removed from the list.\n";
}

void HumidityDisplay::PrintInfo() {
    std::cout << "HumidityDisplay \"" << this->number << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}
