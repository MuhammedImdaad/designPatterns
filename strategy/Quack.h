#pragma once
#include <iostream>

class QuackBehaviour
{
public:
    virtual void quack() = 0;
    virtual ~QuackBehaviour() = default;
};

class Quack : public QuackBehaviour
{
public:
    virtual void quack() override { std::cout << "quacking...\n"; }
};

class Squeak : public QuackBehaviour
{
public:
    virtual void quack() override { std::cout << "squeaking...\n"; }
};