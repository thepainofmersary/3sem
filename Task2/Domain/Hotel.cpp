#include "Hotel.h"
#include <iostream>

Hotel::Hotel() {}

void Hotel::addRoom(const std::shared_ptr<Room>& room) 
{
    rooms.emplace_back(room);
}

void Hotel::addGuest(const std::shared_ptr<Guest>& guest) 
{
    guests.emplace_back(guest);
}

std::shared_ptr<Guest> Hotel::getGuest(int index) const 
{
    return guests.at(index);
}

void Hotel::showDiscounts() const 
{
    for (const auto& guest : guests) 
    {
        if (guest->isRegularGuestFlag()) 
        {
            std::cout << "���������� �����: " << guest->getName() << ", ������: " << guest->getDiscount() << "%\n";
        }
    }
}

void Hotel::showRoomInfo(int roomNumber) const 
{
    for (const auto& room : rooms) 
    {
        if (room->getRoomNumber() == roomNumber) 
        {
            room->showRoomInfo();
            break;
        }
    }
}

void Hotel::bookRoom(int roomNumber, const std::shared_ptr<Guest>& guest) 
{
    for (auto& room : rooms) 
    {
        if (room->getRoomNumber() == roomNumber && !room->isRoomOccupied()) 
        {
            room->setOccupied(true);
            bookedRooms.emplace_back(room, guest);
            std::cout << "����� " << roomNumber << " ������������ ��� ����� " << guest->getName() << ".\n";
            break;
        }
    }
}

void Hotel::showOccupiedRooms() const 
{
    for (const auto& booked : bookedRooms) 
    {
        std::cout << "����� " << booked.first->getRoomNumber() << " ������������ ������ " << booked.second->getName() << ".\n";
    }
}

void Hotel::showAvailableRooms() const 
{
    for (const auto& room : rooms) 
    {
        if (!room->isRoomOccupied()) 
        {
            std::cout << "����� " << room->getRoomNumber() << " ��������.\n";
        }
    }
}
