//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef PRACTICEPROBLEMS_WEATHER_STATION_H
#define PRACTICEPROBLEMS_WEATHER_STATION_H

#include <iostream>
#include <memory>
#include <vector>
#include <memory>

#include "WeatherStation.h"

void weatherStation() {

    WeatherStation *station = new WeatherStation();
    std::shared_ptr<HumidityDisplay> observer1 = std::make_shared<HumidityDisplay>(*station);
    std::shared_ptr<TemperatureDisplay> observer2 = std::make_shared<TemperatureDisplay>(*station);

    station->CreateMessage("Humidity: 10%");
    station->Notify();

    station->CreateMessage("Temperature: 20C");
    station->Notify();

    observer1->RemoveMeFromTheList();

    observer2->RemoveMeFromTheList();
}

#endif //PRACTICEPROBLEMS_WEATHER_STATION_H
