#include <Pizza.h>
#include <Factory.h>

class SimplePizzaStore
{
    SimplePizzaFactory factory;

public:
    std::unique_ptr<Pizza> orderPizza(PizzaType type)
    {
        auto pizza = factory.createPizza(type);
        pizza->prepare();
        pizza->pack();
        return pizza;
    }
};

/// @brief /////////////////////////////////////////////////////
class PizzaStore
{
public:
    std::unique_ptr<Pizza> orderPizza(PizzaType type)
    {
        auto pizza = createPizza(type);
        pizza->prepare();
        pizza->pack();
        return pizza;
    }

    virtual std::unique_ptr<Pizza> createPizza(PizzaType type) = 0;
};

class NewYorkPizzaStore : public PizzaStore
{
public:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override
    {
        std::unique_ptr<Pizza> pizza;
        switch (type)
        {
        case PizzaType::Cheese:
            pizza = std::make_unique<NYCheesePizza>();
            break;
        case PizzaType::Sea:
            pizza = std::make_unique<NYSeaFoodPizza>();
            break;
        default:
            break;
        }

        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore
{
public:
    std::unique_ptr<Pizza> createPizza(PizzaType type) override
    {
        std::unique_ptr<Pizza> pizza;
        switch (type)
        {
        case PizzaType::Cheese:
            pizza = std::make_unique<CHCheesePizza>();
            break;
        case PizzaType::Sea:
            pizza = std::make_unique<CHSeaFoodPizza>();
            break;
        default:
            break;
        }

        return pizza;
    }
};