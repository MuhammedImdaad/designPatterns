#pragma once
#include <iostream>

class Turkey
{
public:
    virtual void jump() = 0;
    virtual void gobble() = 0;

    virtual ~Turkey() = default;
};

class WildTurkey : public Turkey
{
public:
    void jump() override
    {
        std::cout << "turkey jumping...\n";
    }

    void gobble() override
    {
        std::cout << "turkey gobbling...\n";
    }
};