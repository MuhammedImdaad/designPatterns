#pragma once
#include <vector>

enum class Action
{
    On,
    Off
};

class Command
{
public:
    virtual void execute(Action) = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class NoCommand : public Command
{
public:
    virtual void execute(Action){};
    virtual void undo() {};
};

class LightCommand : public Command
{
    Light &light;
    bool isOn = false;

public:
    LightCommand(Light &light)
        : light(light)
    {
    }

    virtual void execute(Action action)
    {
        if (action == Action::On)
            light.turnOn(), isOn = true;
        else
            light.turnOff(), isOn = false;
    }

    virtual void undo()
    {
        isOn ? light.turnOff() : light.turnOn();
    };
};

class FanCommand : public Command
{
    Fan &fan;
    // int prevSpeed = 0;
    Action lastAction = Action::On;

public:
    FanCommand(Fan &fan)
        : fan(fan)
    {
    }

    virtual void execute(Action action)
    {
        // prevSpeed = fan.getSpeed();
        if (action == Action::On)
            fan.increase();
        else
            fan.decrease();
        lastAction = action;
    };

    virtual void undo()
    {
        if (lastAction == Action::Off)
            fan.increase();
        else
            fan.decrease();
    };
};

class MacroCommand : public Command
{
    std::vector<std::shared_ptr<Command>> commands;

public:
    MacroCommand(const std::vector<std::shared_ptr<Command>> &commands)
        : commands(std::move(commands))
    {
    }
    virtual void execute(Action action)
    {
        for (auto &command : commands)
            command->execute(action);
    };

    virtual void undo()
    {
        for (auto it = commands.rbegin(); it != commands.rend(); it++)
        (*it)->undo();
    };
};