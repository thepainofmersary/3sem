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

    // Помечаем room1 как занятую
    room1->setOccupied(true);

    // Проверяем доступность комнат после того, как room1 стала занятой
    ASSERT_TRUE(room1->isRoomOccupied() == true);  // room1 занята
    ASSERT_TRUE(room2->isRoomOccupied() == false);  // room2 доступна
}

TEST(AddRoom_OccupiedRooms) 
{
    auto hotel = std::make_shared<Hotel>();
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);

    hotel->addRoom(room1);
    hotel->addRoom(room2);

    // Помечаем room1 как занятую
    room1->setOccupied(true);

    // Проверяем занятые комнаты
    ASSERT_TRUE(room1->isRoomOccupied() == true);  // room1 занята
    ASSERT_TRUE(room2->isRoomOccupied() == false); // room2 не занята
}

TEST(Room_WeakPtr_Hotel) 
{
    auto hotel = std::make_shared<Hotel>();  // shared_ptr на отель
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);

    hotel->addRoom(room1);
    hotel->addRoom(room2);

    // Проверяем, что у комнаты есть слабая ссылка на отель
    auto weakHotel = room1->hotel.lock();  // Получаем shared_ptr от слабой ссылки

    ASSERT_NE(weakHotel, nullptr);  // Проверяем, что weak_ptr не пуст, т.е. отель существует
    ASSERT_EQ(weakHotel, hotel);  // Проверяем, что слабая ссылка указывает на правильный отель
}

TEST(Room_Guest_SharedPtr)
{
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto guest1 = Guest::create("Иван Иванов", true, 10.0);

    room1->addGuest(guest1);

    ASSERT_NE(room1, nullptr);  // Проверка, что room1 создан (shared_ptr)
    ASSERT_NE(guest1, nullptr); // Проверка, что guest1 создан (shared_ptr)
}