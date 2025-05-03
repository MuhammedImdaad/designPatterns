#include <Store.h>

int main()
{
    // simple factory
    SimplePizzaStore ps1;
    auto pizza1 = ps1.orderPizza(PizzaType::Cheese);

    // factory design pattern
    PizzaStore* ny = new NewYorkPizzaStore{};
    PizzaStore* ch = new ChicagoPizzaStore{};
    auto pizza2 = ny->orderPizza(PizzaType::Sea);
    auto pizza3 = ch->orderPizza(PizzaType::Cheese);
}