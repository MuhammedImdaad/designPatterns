#pragma once
#include <memory>
#include <sstream>
#include <vector>
#include <algorithm>
#include <Observers.h>

class Subject
{
public:
    virtual void registerObserver(std::shared_ptr<Observer>) = 0;
    virtual void removeObserver(std::shared_ptr<Observer>) = 0;
    virtual void notifyObservers(const std::string &notification) = 0;
    virtual ~Subject() = default;
};

class WeatherData : public Subject
{
    double temperature;
    double pressure;
    double humidity;

    std::vector<std::shared_ptr<Observer>> observers;

public:
    virtual void registerObserver(std::shared_ptr<Observer> observer) override { observers.push_back(observer); };
    virtual void removeObserver(std::shared_ptr<Observer> observer) override
    {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    };

    virtual void notifyObservers(const std::string &notification) override
    {
        for (auto &observer : observers)
            observer->update(notification);
    };

    void setMeasurements(double temperature, double pressure, double humidity)
    {
        WeatherData::temperature = temperature;
        WeatherData::pressure = pressure;
        WeatherData::humidity = humidity;

        std::ostringstream ss;
        ss << temperature << " " << pressure << " " << humidity;

        notifyObservers(ss.str());
    }
    
};