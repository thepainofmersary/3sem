#pragma once

#include <vector>
#include <memory>
#include "Room.h"
#include "Guest.h"

/*
 * @class Hotel
 * @brief �����, �������������� �����, ������� ��������� �������� � �������.
 */
class Hotel
{
private:
    /*
     * @brief ������ ���� ������� � �����.
     */
    std::vector<std::shared_ptr<Room>> rooms;

    /*
     * @brief ������ ���� ������ � �����.
     */
    std::vector<std::shared_ptr<Guest>> guests;

    /*
     * @brief ������ ��������������� ������� � ��������� � ������.
     */
    std::vector<std::pair<std::shared_ptr<Room>, Guest*>> bookedRooms;

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
     * @brief �������� ���������� � ���������� �������.
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

    void bookRoom(int roomNumber, Guest* guest);
    /*
     * @brief ���������� ������ ������, ������� ��������� � ��������� �������.
     * @param roomNumber ����� �������, ��� ������� ���������� �������� ������.
     */
    void showRoomGuests(int roomNumber) const;
};