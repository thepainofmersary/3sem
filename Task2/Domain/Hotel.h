#pragma once

#include <vector>
#include <memory>
#include "Room.h"

class Room;

class Hotel : public std::enable_shared_from_this<Hotel>
{
public:
    std::vector<std::weak_ptr<Room>> rooms;
    /**
     * @brief ����������� �����.
     *
     * �������������� ������ ����� ��� �������.
     */
    Hotel();

    /**
     * @brief �������� ������� � �����.
     * @param room ����� ��������� �� ������ Room, ������� ����������� � �����.
     */
    void addRoom(const std::shared_ptr<Room>& room);

    /**
     * @brief �������� ���������� � ��������� �������.
     */
    void showAvailableRooms() const;

    /**
     * @brief �������� ���������� � ������� �������.
     */
    void showOccupiedRooms() const;

    /**
     * @brief �������� ���������� � ���������� �������.
     * @param roomNumber ����� �������.
     */
    void showRoomInfo(int roomNumber) const;
};
