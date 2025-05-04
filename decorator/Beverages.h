#pragma once
#include <string>
#include <iostream>

enum class Size
{
    TALL,
    GRANDE,
    VENTI
};

class Beverage
{
    Size size = Size::TALL;

protected:
    std::string description;

public:
    virtual std::string getDescription() const { return description; }

    friend std::ostream &operator<<(std::ostream &os, Beverage &beverage)
    {
        os << beverage.getDescription() << " - $" << beverage.cost() << std::endl;
        return os;
    }

    void setSize(Size size) {this->size = size;}

    Size getSize() { return size; }

    virtual double cost() = 0;
    virtual ~Beverage() = default;
};

class Espresso : public Beverage
{
public:
    Espresso(Size size = Size::TALL)
    {
        setSize(size);
        description = "Espresso";
    }

    virtual double cost() override
    {
        switch (getSize())
        {
        case Size::TALL:
            return 1.99;
        case Size::VENTI:
            return 3.19;
        case Size::GRANDE:
            return 2.59;
        default:
            return 0;
        }
    }

    ~Espresso(){
        // std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend(Size size = Size::TALL)
    {
        setSize(size);
        description = "Latte";
    }

    virtual double cost() override
    {
        
        switch (getSize())
        {
        case Size::TALL:
            return .89;
        case Size::VENTI:
            return 1.79;
        case Size::GRANDE:
            return 1.29;
        default:
            return 0;
        }
    }
};