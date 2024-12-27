#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Hotel.h"
#include "Guest.h"

class Hotel;

class Room : public std::enable_shared_from_this<Room>
{
private:
    int roomNumber; 
    bool hasFridge; 
    bool hasTV; 
    bool hasBar; 
    bool isOccupied; 
    double price; 
    std::vector<std::weak_ptr<Guest>> guests; 

    /**
     * @brief ����������� �������.
     * @param roomNumber ����� �������.
     * @param hasFridge ������� ������������.
     * @param hasTV ������� ����������.
     * @param hasBar ������� ����-����.
     * @param price ���� �� ����.
     */
    Room(int roomNumber, bool hasFridge, bool hasTV, bool hasBar, double price);

    std::shared_ptr<Hotel> hotel;

public:
    /**
     * @brief ����������� ����� ��� �������� ������� Room.
     * @param roomNumber ����� �������.
     * @param hasFridge ������� ������������.
     * @param hasTV ������� ����������.
     * @param hasBar ������� ����-����.
     * @param price ���� �� ����.
     * @return ����� ��������� �� ������ Room.
     */
    static std::shared_ptr<Room> create(int roomNumber, bool hasFridge, bool hasTV, bool hasBar, double price);

    /**
     * @brief �������� ����� �������.
     * @return ����� �������.
     */
    int getRoomNumber() const;

    /**
     * @brief ���������, ������ �� �������.
     * @return true, ���� ������� ������; ����� false.
     */
    bool isRoomOccupied() const;

    /**
     * @brief ���������� ������ ��������� �������.
     * @param isOccupied ����� ������ ��������� �������.
     */
    void setOccupied(bool isOccupied);

    /**
     * @brief �������� ���� �� ���� ���������� � �������.
     * @return ���� �� ����.
     */
    double getPrice() const;

    /**
     * @brief ������� �� ����� ���������� � �������.
     * �������� ����� �������, ���� � ������� �������.
     */
    void showRoomInfo() const;

    /**
     * @brief �������� ����� � �������.
     * @param guest ����� ��������� �� ������ Guest.
     */
    void addGuest(const std::shared_ptr<Guest>& guest);

    /**
     * @brief ���������� �����, � �������� ����������� �������.
     * @param hotel ����� ��������� �� ������ Hotel.
     */
    void setHotel(const std::shared_ptr<Hotel>& hotel);

    /**
     * @brief ������� ������ ������ � �������.
     */
    void listGuests() const;
};