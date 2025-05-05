#include <Receivers.h>
#include <Invoker.h>
#include <Commands.h>

int main()
{
    RemoteController remote;
    Light light;
    Fan fan;

    remote.setCommand(0, std::make_shared<LightCommand>(light));
    remote.setCommand(1, std::make_shared<FanCommand>(fan));
    std::vector<std::shared_ptr<Command>> macro{
        remote.getCommand(0),
        remote.getCommand(1)};
    remote.setCommand(2, std::make_shared<MacroCommand>(macro));
    std::cout << remote;

    remote.pressPlus(0);
    remote.pressPlus(1);
    remote.pressPlus(1);
    remote.pressUndo();
    remote.pressNegative(0);
    std::cout << remote;
    remote.pressNegative(1);
    remote.pressPlus(2);
    remote.pressNegative(2);
}