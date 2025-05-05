#include <Subject.h>
#include <Displays.h>

int main()
{
    // subject
    auto weatherData = std::make_shared<WeatherData>();

    // observers
    auto currentDisplay = std::make_shared<CurrentConditionDisplay>();
    weatherData->registerObserver(currentDisplay);
    auto statisticsDisplay = std::make_shared<StatisticsDisplay>();
    weatherData->registerObserver(statisticsDisplay);
    auto forecaseDisplay = std::make_shared<ForecastDisplay>();
    weatherData->registerObserver(forecaseDisplay);

    // testing
    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(82, 70, 29.2f);
    weatherData->removeObserver(forecaseDisplay);
    weatherData->setMeasurements(78, 90, 29.2f);
}