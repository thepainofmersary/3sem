#pragma once

#include <vector>
#include <memory>
#include "Room.h"
#include "Guest.h"

class Hotel
{
private:
    std::vector<std::shared_ptr<Room>> rooms;
    std::vector<std::shared_ptr<Guest>> guests;

public:
    Hotel();

    void addRoom(const std::shared_ptr<Room>& room);
    void addGuest(const std::shared_ptr<Guest>& guest);
    std::shared_ptr<Guest> getGuest(int index) const;

    void showAvailableRooms() const;
    void showOccupiedRooms() const;
    void showRoomInfo(int roomNumber) const;
    void showDiscounts() const;
    void bookRoom(int roomNumber, const std::vector<Guest*>& guests);
};
