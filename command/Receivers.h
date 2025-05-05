#pragma once
#include <iostream>

class Light
{
public:
    void turnOn() { std::cout << "Light turned On\n"; }
    void turnOff() { std::cout << "Light turned Off\n"; }
};

class Fan
{
    int speed = 0;
    const int maxSpeed = 3;

public:
    void increase()
    {
        if (speed == 0)
            std::cout << "Fan turned on" << std::endl;
        if (speed < maxSpeed)
            speed++;
        std::cout << "Fan speed is increased to " << speed << std::endl;
    }

    void decrease()
    {
        if (speed)
            speed--;

        if (speed)
            std::cout << "Fan speed is decreased to " << speed << std::endl;
        else
            std::cout << "Fan turned off" << std::endl;
    }

    int getSpeed(){return speed;}
};