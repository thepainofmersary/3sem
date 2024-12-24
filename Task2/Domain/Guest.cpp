#include "Guest.h"
#include "Room.h"
#include <memory>

Guest::Guest(const std::string& name, bool isRegularGuest, double discount)
    : name(name), isRegularGuest(isRegularGuest), discount(discount) {}

std::shared_ptr<Guest> Guest::create(const std::string& name, bool isRegularGuest, double discount)
{
    return std::shared_ptr<Guest>(new Guest(name, isRegularGuest, discount));
}

std::string Guest::getName() const
{
    return name;
}

bool Guest::isRegularGuestFlag() const
{
    return isRegularGuest;
}

double Guest::getDiscount() const
{
    return discount;
}

void Guest::setRoom(const std::shared_ptr<Room>& room)
{
    this->room = room;
}