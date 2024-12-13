#include <iostream>
#include <memory>
#include "../Domain/Hotel.h"
#include "../Domain/Guest.h"
#include "../Domain/Room.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RU");
    auto hotel = std::make_shared<Hotel>();

    hotel->addRoom(Room::create(101, 2, true, true, false, 5000));
    hotel->addRoom(Room::create(102, 3, true, false, true, 7000));

    hotel->addGuest(Guest::create("Иван Иванов", true, 10));
    hotel->addGuest(Guest::create("Петр Петров", false, 0));

    hotel->showAvailableRooms();

    hotel->bookRoom(101, hotel->getGuest(0));
    hotel->bookRoom(102, hotel->getGuest(1));

    hotel->showOccupiedRooms();

    hotel->showDiscounts();

    return 0;
}
