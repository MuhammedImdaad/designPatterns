#include <Duck.h>
#include <Turkey.h>
#include <Adaptor.h>

int main()
{
    auto duck = std::make_shared<MallardDuck>();
    auto turkey = std::make_shared<WildTurkey>();

    auto turkeyDuck = std::make_shared<TurkeyAdaptor>(turkey);

    duckBehaviour(duck);
    duckBehaviour(turkeyDuck);
}