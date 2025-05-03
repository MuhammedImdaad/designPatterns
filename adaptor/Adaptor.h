#include <Duck.h>
#include <Turkey.h>
#include <memory>

class TurkeyAdaptor : public Duck
{
    std::shared_ptr<Turkey> turkey;

public:
    TurkeyAdaptor(std::shared_ptr<Turkey> turkey)
        : turkey(turkey)
    {
    }

    void fly() override
    {
        std::cout << "Turkey jumping for 3 times\n";
        for (int i = 0; i < 3; i++)
            turkey->jump();
    }

    void quack() override
    {
        turkey->gobble();
    }
};