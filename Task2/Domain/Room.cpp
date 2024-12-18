﻿#include "Room.h"

Room::Room(int roomNumber, int capacity, bool hasFridge, bool hasTV, bool hasBar, double price)
    : roomNumber(roomNumber), capacity(capacity), hasFridge(hasFridge), hasTV(hasTV), hasBar(hasBar), isOccupied(false), price(price) {}

std::shared_ptr<Room> Room::create(int roomNumber, int capacity, bool hasFridge, bool hasTV, bool hasBar, double price)
{
    return std::shared_ptr<Room>(new Room(roomNumber, capacity, hasFridge, hasTV, hasBar, price));
}

int Room::getRoomNumber() const
{
    return roomNumber;
}

bool Room::isRoomOccupied() const
{
    return isOccupied;
}

void Room::setOccupied(bool isOccupied)
{
    this->isOccupied = isOccupied;
}

double Room::getPrice() const
{
    return price;
}

void Room::showRoomInfo() const
{
    std::cout << "Номер: " << roomNumber << "\n"
        << "Вместимость: " << capacity << " человек\n"
        << "Цена: " << price << " руб.\n";

    std::cout << "Холодильник: " << (hasFridge ? "Да" : "Нет") << "\n";
    std::cout << "Телевизор: " << (hasTV ? "Да" : "Нет") << "\n";
    std::cout << "Мини-бар: " << (hasBar ? "Да" : "Нет") << "\n";
}

void Room::addGuest(Guest* guest)
{
    guests.push_back(guest);
}

void Room::listGuests() const
{
    std::cout << "Список гостей:\n";
    for (const auto* guest : guests)
    {
        std::cout << "- " << guest->getName() << "\n";
    }
}
