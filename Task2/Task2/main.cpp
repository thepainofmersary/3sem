#include <iostream>
#include <memory>
#include "../Domain/Guest.h"
#include "../Domain/Room.h"
#include "../Domain/Hotel.h"
#include <locale>

int main()
{
    setlocale(LC_ALL, "RU");
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);
    auto room3 = Room::create(103, true, false, true, 2800.0);

    auto hotel = std::make_shared<Hotel>();

    hotel->addRoom(room1);
    hotel->addRoom(room2);
    hotel->addRoom(room3);

    auto guest1 = Guest::create("Иван Иванов", true, 10.0, room1);
    auto guest2 = Guest::create("Мария Петрова", false, 0.0, room2);
    auto guest3 = Guest::create("Алексей Смирнов", true, 15.0, room3);

    room1->addGuest(guest1);
    room2->addGuest(guest2);
    room3->addGuest(guest3);

    std::cout << "Доступные комнаты:\n";
    hotel->showAvailableRooms();

    std::cout << "\nЗанятые комнаты:\n";
    hotel->showOccupiedRooms();

    std::cout << "\nИнформация о комнате 102:\n";
    hotel->showRoomInfo(102);

    return 0;
}