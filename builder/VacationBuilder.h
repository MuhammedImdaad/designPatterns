#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include <Vacation.h>

using namespace std;

class VacationBuilder
{
    unique_ptr<Vacation> vacation;

public:
    VacationBuilder(string customer)
        : vacation(new Vacation(customer))
    {
    }
    VacationBuilder &buildDay() // fluent interface
    {
        vacation->days.push_back({});
        return *this;
    }
    VacationBuilder &addHotel(string hotel)
    {
        vacation->days.back().hotel = hotel;
        return *this;
    }
    VacationBuilder &addParkTicket(string park)
    {
        vacation->days.back().parkTickets.emplace_back(park);
        return *this;
    }
    VacationBuilder &addReservation(string dine)
    {
        vacation->days.back().dinings.emplace_back(dine);
        return *this;
    }
    VacationBuilder &addEvent(string event)
    {
        vacation->days.back().specialEvents.emplace_back(event);
        return *this;
    }
    unique_ptr<Vacation> create()
    {
        return std::move(vacation);
    }
};