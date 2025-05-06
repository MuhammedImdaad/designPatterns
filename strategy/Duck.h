#pragma once
#include <iostream>
#include <memory>
#include <Fly.h>
#include <Quack.h>

class Duck
{
protected:
    std::unique_ptr<FlyBehaviour> flyBehaviour;
    std::unique_ptr<QuackBehaviour> quackBehaviour;

public:
    void performFly() { flyBehaviour->fly(); };
    void setFlyBehaviour(std::unique_ptr<FlyBehaviour> flyBehaviour){Duck::flyBehaviour = std::move(flyBehaviour);}

    void performQuack() { quackBehaviour->quack(); };
    void setQuackBehaviour(std::unique_ptr<QuackBehaviour> quackBehaviour){Duck::quackBehaviour = std::move(quackBehaviour);}
    
    virtual void display() = 0;
    virtual ~Duck() = default;
};

class MallardDuck : public Duck
{
public:
    MallardDuck()
    {
        setFlyBehaviour(std::make_unique<FlyWithWings>());
        setQuackBehaviour(std::make_unique<Quack>());
    }

    virtual void display() override
    {
        std::cout << "looks like a mallard\n";
    }
};

class ModelDuck : public Duck
{
public:
    ModelDuck()
    {
        setFlyBehaviour(std::make_unique<FlyWithWings>());
        setQuackBehaviour(std::make_unique<Quack>());
    }
    virtual void display() override
    {
        std::cout << "looks like a model\n";
    }
};

class RubberDuck : public Duck
{
public:
    RubberDuck()
    {
        setFlyBehaviour(std::make_unique<FlyNoWay>());
        setQuackBehaviour(std::make_unique<Squeak>());
    }
    virtual void display() override
    {
        std::cout << "looks like a play duck\n";
    }
};