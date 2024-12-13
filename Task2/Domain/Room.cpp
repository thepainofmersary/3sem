#include "Room.h"

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

    if (hasFridge) 
    {
        std::cout << "Холодильник: Да\n";
    }
    else 
    {
        std::cout << "Холодильник: Нет\n";
    }

    if (hasTV) 
    {
        std::cout << "Телевизор: Да\n";
    }
    else 
    {
        std::cout << "Телевизор: Нет\n";
    }

    if (hasBar) 
    {
        std::cout << "Мини-бар: Да\n";
    }
    else 
    {
        std::cout << "Мини-бар: Нет\n";
    }
}

