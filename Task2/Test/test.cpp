#include "pch.h"
#include "../Domain/Guest.h"
#include "../Domain/Room.h"
#include "../Domain/Hotel.h"


TEST(AvailableRoomsBeforeOccupied_AddRoom_Success) 
{
    auto hotel = std::make_shared<Hotel>();
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);

    hotel->addRoom(room1);
    hotel->addRoom(room2);

    ASSERT_TRUE(room1->isRoomOccupied() == false);
    ASSERT_TRUE(room2->isRoomOccupied() == false);
}

TEST(AvailableRoomsAfterOccupied_AddRoom_Success) 
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

TEST(AddRoom_OccupiedRooms) 
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

TEST(Room_Guest_SharedPtr)
{
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto guest1 = Guest::create("           ", true, 10.0, room1);

    room1->addGuest(guest1);

    ASSERT_NE(room1, nullptr);  
    ASSERT_NE(guest1, nullptr); 
}