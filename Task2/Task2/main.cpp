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

    auto guest1 = Guest::create("Иван Иванов", true, 10);
    auto guest2 = Guest::create("Петр Петров", false, 0);
    auto guest3 = Guest::create("Алексей Алексей", true, 5);

    hotel->addGuest(guest1);
    hotel->addGuest(guest2);
    hotel->addGuest(guest3);

    hotel->bookRoom(101, guest1.get());  // Бронируем комнату 101 для гостя Иванова
    hotel->bookRoom(101, guest2.get());  // Бронируем комнату 101 для гостя Петрова
    hotel->bookRoom(102, guest3.get());  // Бронируем комнату 102 для гостя Алексеева

    hotel->showRoomGuests(101);  // Выводим список гостей в комнате 101
    hotel->showRoomGuests(102);  // Выводим список гостей в комнате 102

    return 0;
}