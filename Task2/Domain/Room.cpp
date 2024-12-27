#include "Room.h"

Room::Room(int roomNumber, bool hasFridge, bool hasTV, bool hasBar, double price)
    : roomNumber(roomNumber), hasFridge(hasFridge), hasTV(hasTV), hasBar(hasBar), isOccupied(false), price(price) {}

std::shared_ptr<Room> Room::create(int roomNumber, bool hasFridge, bool hasTV, bool hasBar, double price)
{ 
    return std::shared_ptr<Room>(new Room(roomNumber, hasFridge, hasTV, hasBar, price));
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
        << "Цена: " << price << " руб.\n"
        << "Холодильник: " << (hasFridge ? "Да" : "Нет") << "\n"
        << "Телевизор: " << (hasTV ? "Да" : "Нет") << "\n"
        << "Мини-бар: " << (hasBar ? "Да" : "Нет") << "\n";
}

void Room::addGuest(const std::shared_ptr<Guest>& guest)
{
    guests.push_back(guest);
    guest->setRoom(shared_from_this()); 
    isOccupied = true;
}