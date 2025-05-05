#pragma once

class Observer
{
public:
    virtual void update(std::string notification) = 0;
    virtual ~Observer() = default;
};
