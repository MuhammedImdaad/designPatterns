#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>

enum class PizzaType
{
    Cheese,
    Pepparoni,
    Veggie,
    Sea
};

class Pizza
{
public:
    virtual void prepare() = 0;
    void pack()
    {
        std::cout << "Packing...\n";
    }
    virtual ~Pizza() = default;
};

class CheesePizza : public Pizza
{
public:
    void prepare() override
    {
        std::cout << "cheese pizza...\n";
    }
};

class SeaFoodPizza : public Pizza
{
    void prepare() override
    {
        std::cout << "sea food pizza...\n";
    }
};

class NYCheesePizza : public Pizza
{
public:
    void prepare() override
    {
        std::cout << "NewYork style cheese pizza...\n";
    }
};

class NYSeaFoodPizza : public Pizza
{
    void prepare() override
    {
        std::cout << "NewYork style sea food pizza...\n";
    }
};


class CHCheesePizza : public Pizza
{
public:
    void prepare() override
    {
        std::cout << "Chicago style cheese pizza...\n";
    }
};

class CHSeaFoodPizza : public Pizza
{
    void prepare() override
    {
        std::cout << "Chicago style sea food pizza...\n";
    }
};
