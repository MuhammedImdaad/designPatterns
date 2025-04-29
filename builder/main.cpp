#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include <VacationBuilder.h>

int main()
{
    auto vac1 = VacationBuilder("John")
                .buildDay()
                    .addHotel("Hilton")
                    .addParkTicket("Victoria")
                .buildDay()
                    .addHotel("Mandarin")
                    .addEvent("Youth Forum")
                    .addReservation("Dinner")
                .create();

    cout << *vac1;
}