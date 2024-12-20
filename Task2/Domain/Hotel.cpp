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
            std::cout << "Постоянный гость: " << guest->getName()
                << ", скидка: " << guest->getDiscount() << "%\n";
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

void Hotel::bookRoom(int roomNumber, Guest* guest)
{
    for (auto& room : rooms)
    {
        if (room->getRoomNumber() == roomNumber && !room->isRoomOccupied())
        {
            if (room->addGuest(guest))
            {
                bookedRooms.emplace_back(room, guest);  
                std::cout << "Гость " << guest->getName() << " забронирован в комнате " << roomNumber << ".\n";
                return;
            }
            else
            {
                std::cout << "Комната " << roomNumber << " не может принять больше гостей.\n";
                return;
            }
        }
    }
    std::cout << "Комната " << roomNumber << " не найдена или занята.\n";
}

void Hotel::showOccupiedRooms() const
{
    for (const auto& room : rooms)
    {
        if (room->isRoomOccupied())
        {
            std::cout << "Номер " << room->getRoomNumber() << " занят.\n";
            room->listGuests();
        }
    }
}

void Hotel::showAvailableRooms() const
{
    for (const auto& room : rooms)
    {
        if (!room->isRoomOccupied())
        {
            std::cout << "Номер " << room->getRoomNumber() << " доступен.\n";
        }
    }
}

void Hotel::showRoomGuests(int roomNumber) const
{
    for (const auto& room : rooms)
    {
        if (room->getRoomNumber() == roomNumber)
        {
            room->listGuests();  
            return;
        }
    }
    std::cout << "Комната с номером " << roomNumber << " не найдена.\n";
}