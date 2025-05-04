#include <Beverages.h>
#include <memory>

class CodimentDecorator : public Beverage
{
protected:
    std::unique_ptr<Beverage> beverage;

public:
    CodimentDecorator(std::unique_ptr<Beverage> beverage) // a coffee or a decorator
        : beverage(std::move(beverage))
    {
        setSize(this->beverage->getSize());
    }
};

class Mocha : public CodimentDecorator
{
public:
    Mocha(std::unique_ptr<Beverage> beverage)
        : CodimentDecorator(std::move(beverage))
    {
    }

    virtual double cost() override
    {
        double out = beverage->cost();
        switch (beverage->getSize())
        {
        case Size::TALL:
            out += .2;
            break;
        case Size::VENTI:
            out += .5;
            break;
        case Size::GRANDE:
            out += .4;
            break;
        };

        return out;
    };

    virtual std::string getDescription() const override { return beverage->getDescription() + ", Mocha"; }
};

class Soy : public CodimentDecorator
{
public:
    Soy(std::unique_ptr<Beverage> beverage)
        : CodimentDecorator(std::move(beverage))
    {
    }

    virtual double cost() override
    {
        return beverage->cost() + .15;
    };

    virtual std::string getDescription() const override { return beverage->getDescription() + ", Soy"; }
};

class Whip : public CodimentDecorator
{
public:
    Whip(std::unique_ptr<Beverage> beverage)
        : CodimentDecorator(std::move(beverage))
    {
    }

    virtual double cost() override
    {
        return beverage->cost() + .1;
    };

    virtual std::string getDescription() const override { return beverage->getDescription() + ", Whip"; }
};