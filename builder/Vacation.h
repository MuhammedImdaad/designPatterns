#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class VacationBuilder;

using namespace std;

struct Day
{
    string hotel;
    vector<string> parkTickets;
    vector<string> specialEvents;
    vector<string> dinings;
};

class Vacation
{
    string customer;
    vector<Day> days;
    friend class VacationBuilder;

    // objects can only be created through the VacationBuilder
    Vacation(string customer)
        : customer(customer)
    {
    }

public:
    friend ostream &operator<<(ostream &os, const Vacation &vacation)
    {
        os << vacation.customer << " has planned for " << vacation.days.size() << " days of vacation:\n";
        for (size_t i = 0; i < vacation.days.size(); ++i)
        {
            os << "Day " << i + 1 << ": Hotel - " << vacation.days[i].hotel << "\n";
            os << "  Parks: ";
            for (const auto &park : vacation.days[i].parkTickets)
                os << park << " ";
            os << "\n  Events: ";
            for (const auto &event : vacation.days[i].specialEvents)
                os << event << " ";
            os << "\n  Dinings: ";
            for (const auto &dine : vacation.days[i].dinings)
                os << dine << " ";
            os << "\n";
        }
        return os;
    }
};