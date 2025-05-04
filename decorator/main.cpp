#include <Beverages.h>
#include <Codiments.h>
#include <memory>

#include <CoffeeBuilder.h>

int main()
{
    auto order = std::make_unique<Espresso>();
    std::cout << *order;

    auto order1 = std::make_unique<Whip>(std::make_unique<Espresso>(Size::GRANDE)); // whip espresso
    std::cout << *order1;

    auto order2 = std::make_unique<Mocha>(std::make_unique<Mocha>(std::make_unique<Espresso>(Size::VENTI))); // double mocha espresso
    std::cout << *order2;

    auto order3 = std::make_unique<Whip>(std::make_unique<Mocha>(std::make_unique<Soy>(std::make_unique<HouseBlend>(Size::GRANDE)))); // mocha soy latte with whip
    std::cout << *order3;

    // via builder pattern, look how clear it is
    auto order4 = CoffeeBuilder("latte", Size::GRANDE) // mocha soy latte with whip
                    .addSoy()
                    .addMocha()
                    .addWhip()
                    .pour();
    std::cout << *order4;

    // Espresso - $1.99
    // Espresso, Whip - $2.69
    // Espresso, Mocha, Mocha - $4.19
    // Latte, Soy, Mocha, Whip - $1.94
}