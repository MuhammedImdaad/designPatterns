#include <Factory.h>

Factory *Factory::instance = nullptr;

int main()
{
    auto &f1 = BasicFactory::getInstance();
    f1.createObject();
    
    Factory::setInstance(new FactoryDerived());
    auto &factory = Factory::getInstance();
    factory.createObject();
}