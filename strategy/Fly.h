#pragma once
#include <iostream>

class FlyBehaviour
{
public:
    virtual void fly() = 0;
    virtual ~FlyBehaviour() = default;
};

class FlyWithWings : public FlyBehaviour
{
public:
    virtual void fly() override { std::cout << "flying...\n"; }
};

class FlyNoWay : public FlyBehaviour
{
public:
    virtual void fly() override { std::cout << "cannot fly :(\n"; }
};

class FlyRocketPowerd : public FlyBehaviour
{
public:
    virtual void fly() override { std::cout << "fly like a rocket --> \n"; }
};