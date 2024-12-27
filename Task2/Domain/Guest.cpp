﻿#include "Guest.h"
#include "Room.h"
#include <memory>

Guest::Guest(const std::string& name, bool isRegularGuest, double discount, const std::shared_ptr<Room>& room)
    : name(name), isRegularGuest(isRegularGuest), discount(discount), room(room) {}

std::shared_ptr<Guest> Guest::create(const std::string& name, bool isRegularGuest, double discount, const std::shared_ptr<Room>& room)
{
    return std::shared_ptr<Guest>(new Guest(name, isRegularGuest, discount, room));
}

std::string Guest::getName() const
{
    return name;
}

std::shared_ptr<Room> Guest::getRoom() const
{
    return room;
}

void Guest::setRoom(const std::shared_ptr<Room>& room)
{
    this->room = room;
}