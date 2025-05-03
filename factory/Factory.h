#include <Pizza.h>

class SimplePizzaFactory
{
public:
virtual std::unique_ptr<Pizza> createPizza(PizzaType type) const
    {
        std::unique_ptr<Pizza> pizza;
        switch (type)
        {
        case PizzaType::Cheese:
            pizza = std::make_unique<CheesePizza>();
            break;
        case PizzaType::Sea:
            pizza = std::make_unique<SeaFoodPizza>();
            break;
        default:
            break;
        }

        return pizza;
    }
};