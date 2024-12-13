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
    std::cout << "�����: " << roomNumber << "\n"
        << "�����������: " << capacity << " �������\n"
        << "����: " << price << " ���.\n";

    if (hasFridge) 
    {
        std::cout << "�����������: ��\n";
    }
    else 
    {
        std::cout << "�����������: ���\n";
    }

    if (hasTV) 
    {
        std::cout << "���������: ��\n";
    }
    else 
    {
        std::cout << "���������: ���\n";
    }

    if (hasBar) 
    {
        std::cout << "����-���: ��\n";
    }
    else 
    {
        std::cout << "����-���: ���\n";
    }
}

