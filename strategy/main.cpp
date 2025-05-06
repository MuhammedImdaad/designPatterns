#include <Duck.h>

int main()
{
    auto mallard = std::make_unique<MallardDuck>();
    mallard->display();
    mallard->performQuack();
    mallard->performFly();

    auto model = std::make_unique<ModelDuck>();
    model->display();
    model->performFly(); 
    model->setFlyBehaviour(std::make_unique<FlyRocketPowerd>());
    model->performFly();
}