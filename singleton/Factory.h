#include <vector>
#include <string>
#include <iostream>
#include <memory>

class A
{
public:
    A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class B : public A
{
public:
    B() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class BasicFactory
{
private:
    BasicFactory()
    {
        std::cout << "Basic Global Instance created\n";
    };

public:
    static BasicFactory &getInstance()
    {
        static BasicFactory factory; // C++11 Thread safe
        return factory;
    }

    virtual A createObject() const
    {
        return A{};
    }

    BasicFactory(const BasicFactory &other) = delete;
    BasicFactory &operator=(const BasicFactory &other) = delete;

    virtual ~BasicFactory()
    {
        std::cout << "Basic Global Instance destroyed\n";
    };
};

class Factory
{
private:
    static Factory *instance;

protected:
    Factory()
    {
        std::cout << "Global Instance created\n";
    };

public:
    static Factory &getInstance()
    {
        if (instance == nullptr)
            instance = new Factory{};
        return *instance;
    }

    static void setInstance(Factory *other)
    {
        if (instance != nullptr)
            delete instance;
        instance = other;
    }

    virtual A createObject() const
    {
        return A{};
    }

    Factory(const Factory &other) = delete;
    Factory &operator=(const Factory &other) = delete;

    virtual ~Factory()
    {
        std::cout << "Global Instance destroyed\n";
    };
};

class FactoryDerived : public Factory
{
public:
    A createObject() const override
    {
        return B{};
    }
};