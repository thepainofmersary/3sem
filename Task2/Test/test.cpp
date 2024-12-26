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

    // �������� room1 ��� �������
    room1->setOccupied(true);

    // ��������� ����������� ������ ����� ����, ��� room1 ����� �������
    ASSERT_TRUE(room1->isRoomOccupied() == true);  // room1 ������
    ASSERT_TRUE(room2->isRoomOccupied() == false);  // room2 ��������
}

TEST(AddRoom_OccupiedRooms) 
{
    auto hotel = std::make_shared<Hotel>();
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);

    hotel->addRoom(room1);
    hotel->addRoom(room2);

    // �������� room1 ��� �������
    room1->setOccupied(true);

    // ��������� ������� �������
    ASSERT_TRUE(room1->isRoomOccupied() == true);  // room1 ������
    ASSERT_TRUE(room2->isRoomOccupied() == false); // room2 �� ������
}

TEST(Room_WeakPtr_Hotel) 
{
    auto hotel = std::make_shared<Hotel>();  // shared_ptr �� �����
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto room2 = Room::create(102, false, true, true, 3500.0);

    hotel->addRoom(room1);
    hotel->addRoom(room2);

    // ���������, ��� � ������� ���� ������ ������ �� �����
    auto weakHotel = room1->hotel.lock();  // �������� shared_ptr �� ������ ������

    ASSERT_NE(weakHotel, nullptr);  // ���������, ��� weak_ptr �� ����, �.�. ����� ����������
    ASSERT_EQ(weakHotel, hotel);  // ���������, ��� ������ ������ ��������� �� ���������� �����
}

TEST(Room_Guest_SharedPtr)
{
    auto room1 = Room::create(101, true, true, false, 3000.0);
    auto guest1 = Guest::create("���� ������", true, 10.0);

    room1->addGuest(guest1);

    ASSERT_NE(room1, nullptr);  // ��������, ��� room1 ������ (shared_ptr)
    ASSERT_NE(guest1, nullptr); // ��������, ��� guest1 ������ (shared_ptr)
}