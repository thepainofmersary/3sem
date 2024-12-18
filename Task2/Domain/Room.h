#pragma once

#include <iostream>
#include <vector>
#include "Guest.h"

class Room
{
private:
    int roomNumber;
    int capacity;
    bool hasFridge;
    bool hasTV;
    bool hasBar;
    bool isOccupied;
    double price;
    std::vector<Guest*> guests; 

    Room(int roomNumber, int capacity, bool hasFridge, bool hasTV, bool hasBar, double price);

public:
    static std::shared_ptr<Room> create(int roomNumber, int capacity, bool hasFridge, bool hasTV, bool hasBar, double price);

    int getRoomNumber() const;
    bool isRoomOccupied() const;
    void setOccupied(bool isOccupied);
    double getPrice() const;
    void showRoomInfo() const;

    void addGuest(Guest* guest);
    void listGuests() const;
};
