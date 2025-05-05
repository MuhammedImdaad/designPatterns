#pragma once
#include <sstream>
#include <iostream>
#include <Observers.h>
#include <Subject.h>
#include <limits>

class CurrentConditionDisplay : public Observer
{
    double temperature;
    double pressure;
    double humidity;

public:
    CurrentConditionDisplay()
    {
    }

    virtual void update(std::string notification) override
    {
       std::istringstream ss(notification);
       ss >> temperature >> pressure >> humidity;

       std::cout << "Realtime Display updated\t Temperature: " << temperature << ", Humidity: " << humidity << std::endl;
    }
};

class StatisticsDisplay : public Observer
{
    double minTemperature = std::numeric_limits<double>::max();
    double maxTemperature = std::numeric_limits<double>::lowest();
    double sumTemperature = 0;
    int numReadings = 0;

public:
    StatisticsDisplay() {}

    virtual void update(std::string notification) override
    {
        double temperature;
        std::istringstream ss(notification);
        ss >> temperature;

        // Update statistics
        if (temperature < minTemperature)
            minTemperature = temperature;
        if (temperature > maxTemperature)
            maxTemperature = temperature;
        sumTemperature += temperature;
        numReadings++;

        double avgTemperature = sumTemperature / numReadings;

        // Display statistics
        std::cout << "Statistics Display updated\t Min Temperature: " << minTemperature
                  << ", Max Temperature: " << maxTemperature
                  << ", Avg Temperature: " << avgTemperature << std::endl;
    }
};

class ForecastDisplay : public Observer
{
    public:
    virtual void update(std::string notification) override
    {
        std::cout << "Forecast Display updated\t Unable to forecast!" << std::endl;    
    }
};