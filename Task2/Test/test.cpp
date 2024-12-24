#include <gtest/gtest.h>
#include "pch.h"
#include <memory>
#include "../Domain/Guest.h"
#include "../Domain/Hotel.h"
#include "../Domain/Room.h"
#include <locale>

TEST(RoomSharedPtr_GuestSharedPtr_Success)
{
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto guest1 = Guest::create("Иван Иванов", true, 10.0);

    room1->addGuest(guest1);

    ASSERT_NE(room1, nullptr);
    ASSERT_NE(guest1, nullptr);
}

TEST(Hotel_WeakPtr_Success)
{
    auto hotel = std::make_shared<Hotel>();
    auto room1 = Room::create(101, true, true, false, 3000.0);

    hotel->addRoom(room1);

    auto weakHotel = room1->hotel.lock();

    ASSERT_NE(weakHotel, nullptr);
}

TEST(Room_Info_Success)
{
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto guest1 = Guest::create("Иван Иванов", true, 10.0);

    room1->addGuest(guest1);

    ASSERT_EQ(room1->getRoomNumber(), 101);
    ASSERT_EQ(room1->getPrice(), 3000.0);
}

TEST(AddRoom_AvailableRoomsBeforeOccupied_Success) 
{
    auto hotel = std::make_shared<Hotel>();
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);

    hotel->addRoom(room1);
    hotel->addRoom(room2);

    ASSERT_TRUE(room1->isRoomOccupied() == false);
    ASSERT_TRUE(room2->isRoomOccupied() == false);
}

TEST(AddRoom_AvailableRoomsAfterOccupied)
{
    auto hotel = std::make_shared<Hotel>();
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);

    hotel->addRoom(room1);
    hotel->addRoom(room2);

    room1->setOccupied(true);

    ASSERT_TRUE(room1->isRoomOccupied() == true);  
    ASSERT_TRUE(room2->isRoomOccupied() == false);  
}

TEST(AddRoom_OccupiedRooms_Success) 
{
    auto hotel = std::make_shared<Hotel>();
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);

    hotel->addRoom(room1);
    hotel->addRoom(room2);

    room1->setOccupied(true);

    ASSERT_TRUE(room1->isRoomOccupied() == true);  
    ASSERT_TRUE(room2->isRoomOccupied() == false);
}