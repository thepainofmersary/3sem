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
    std::vector<std::pair<std::shared_ptr<Room>, std::shared_ptr<Guest>>> bookedRooms;
public:
    /*
     * @brief ����������� �����.
     *
     * �������������� ������ ����� ��� ������� � ������.
     */
    Hotel();
    /*
     * @brief �������� ������� � �����.
     * @param room ����� ��������� �� ������ Room, ������� ����������� � �����.
     */
    void addRoom(const std::shared_ptr<Room>& room);
    /*
     * @brief �������� ����� � �����.
     * @param guest ����� ��������� �� ������ Guest, ������� ����������� � �����.
     */
    void addGuest(const std::shared_ptr<Guest>& guest);
    /*
     * @brief �������� ����� �� �������.
     * @param index ������ ����� � ������.
     * @return ����� ��������� �� ������ Guest.
     */
    std::shared_ptr<Guest> getGuest(int index) const;

    /*
     * @brief �������� ���������� � ��������� �������.
     */
    void showAvailableRooms() const;
    /*
     * @brief �������� ���������� � ������� �������.
     */
    void showOccupiedRooms() const;
    /*
     * @brief �������� ���������� � �������.
     * @param roomNumber ����� �������.
     */
    void showRoomInfo(int roomNumber) const;
    /*
     * @brief �������� ������ ��� ���������� ������.
     */
    void showDiscounts() const;
    /*
     * @brief ������������� ������� ��� �����.
     * @param roomNumber ����� �������.
     * @param guest ����� ��������� �� ������ Guest.
     */
    void bookRoom(int roomNumber, const std::shared_ptr<Guest>& guest);
};