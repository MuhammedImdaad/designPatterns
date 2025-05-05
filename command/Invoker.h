#pragma once
#include <memory>
#include <Commands.h>
#include <iostream>

class RemoteController
{
    const int size;
    std::vector<std::shared_ptr<Command>> slots;
    std::shared_ptr<Command> lastCommand;

public:
    RemoteController(int size = 4)
        : size(size),
          slots(size, std::make_shared<NoCommand>()),
          lastCommand(std::make_unique<NoCommand>())
    {
    }

    void setCommand(int slot, std::shared_ptr<Command> command)
    {
        slots[slot] = command;
    }

    std::shared_ptr<Command> getCommand(int slot) { return slots[slot]; }

    friend std::ostream &operator<<(std::ostream &os, RemoteController &remote)
    {
        os << "RemoteController slots:\n";
        for (int i = 0; i < remote.size; ++i)
        {
            os << "Slot " << i << ": "
               << (remote.slots[i] ? typeid(*remote.slots[i]).name() : "NoCommand")
               << "\n";
        }
        os << "Undo : " << typeid(*remote.lastCommand).name() << std::endl;
        return os;
    }

    void pressPlus(int slot)
    {
        if (slot < 0 || slot >= size)
            throw std::out_of_range("Invalid slot index");
        slots[slot]->execute(Action::On);
        lastCommand = slots[slot];
    }

    void pressNegative(int slot)
    {
        if (slot < 0 || slot >= size)
            throw std::out_of_range("Invalid slot index");
        slots[slot]->execute(Action::Off);
        lastCommand = slots[slot];
    }

    void pressUndo()
    {
        lastCommand->undo();
    }
};