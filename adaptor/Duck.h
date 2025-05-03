#pragma once
#include <iostream>
#include <memory>

class Duck
{
public:
    virtual void fly() = 0;
    virtual void quack() = 0;

    virtual ~Duck() = default;
};

class MallardDuck : public Duck
{
public:
    void fly() override
    {
        std::cout << "duck flying...\n";
    }

    void quack() override
    {
        std::cout << "duck quacking...\n";
    }
};

void duckBehaviour(const std::shared_ptr<Duck>& duck)
{
    duck->quack();
    duck->fly();
}