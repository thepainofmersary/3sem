#include "Hotel.h"
#include <iostream>

Hotel::Hotel() {}

void Hotel::addRoom(const std::shared_ptr<Room>& room)
{
    rooms.emplace_back(room);
    room->setHotel(shared_from_this());
}

void Hotel::showAvailableRooms() const
{
    for (const auto& weakRoom : rooms)
    {
        if (auto room = weakRoom.lock())
        {
            if (!room->isRoomOccupied())
            {
                std::cout << "����� " << room->getRoomNumber() << " ��������.\n";
            }
        }
    }
}

void Hotel::showOccupiedRooms() const
{
    for (const auto& weakRoom : rooms)
    {
        if (auto room = weakRoom.lock())
        {
            if (room->isRoomOccupied())
            {
                std::cout << "����� " << room->getRoomNumber() << " �����.\n";
            }
        }
    }
}

void Hotel::showRoomInfo(int roomNumber) const
{
    for (const auto& weakRoom : rooms)
    {
        if (auto room = weakRoom.lock())
        {
            if (room->getRoomNumber() == roomNumber)
            {
                room->showRoomInfo();
                return;
            }
        }
    }
    std::cout << "������� � ������� " << roomNumber << " �� �������.\n";
}