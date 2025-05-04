#pragma once
#include <Beverages.h>
#include <Codiments.h>

class CoffeeBuilder
{
private:
    std::unique_ptr<Beverage> coffee;

public:
    CoffeeBuilder(const std::string &coffeeType, Size size = Size::TALL)
    {
        if (coffeeType == "espresso")
        {
            coffee = std::make_unique<Espresso>(size);
        }
        else if (coffeeType == "latte")
        {
            coffee = std::make_unique<HouseBlend>(size);
        }
        else
            throw std::logic_error("Invalid coffee type provided");
    }

    template <typename Codiment>
    CoffeeBuilder &addCodiment()
    {
        coffee = std::make_unique<Codiment>(std::move(coffee));
        return *this;
    }

    CoffeeBuilder &addSoy() { return addCodiment<Soy>(); }
    CoffeeBuilder &addMocha() { return addCodiment<Mocha>(); }
    CoffeeBuilder &addWhip() { return addCodiment<Whip>(); }

    auto pour() { return std::move(coffee); }
};