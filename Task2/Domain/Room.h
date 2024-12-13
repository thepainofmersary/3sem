#pragma once

#include <iostream>

class Room 
{
private:
    int roomNumber;
    int capacity;
    bool hasFridge;
    bool hasTV;
    bool hasBar;
    bool isOccupied;
    double price;
    /*
     * @brief ����������� �������.
     * @param roomNumber ����� �������.
     * @param capacity ����������� �������.
     * @param hasFridge ������� ������������.
     * @param hasTV ������� ����������.
     * @param hasBar ������� ����-����.
     * @param price ���� �� ����.
     */
    Room(int roomNumber, int capacity, bool hasFridge, bool hasTV, bool hasBar, double price);
public:
    /*
     * @brief ����������� ����� ��� �������� ������� Room.
     * @param roomNumber ����� �������.
     * @param capacity ����������� �������.
     * @param hasFridge ������� ������������.
     * @param hasTV ������� ����������.
     * @param hasBar ������� ����-����.
     * @param price ���� �� ����.
     * @return ����� ��������� �� ������ Room.
     */
    static std::shared_ptr<Room> create(int roomNumber, int capacity, bool hasFridge, bool hasTV, bool hasBar, double price);
    /*
     * @brief �������� ����� �������.
     * @return ����� �������.
     */
    int getRoomNumber() const;
    /*
     * @brief ���������, ������ �� �������.
     * @return true, ���� ������� ������; ����� false.
     */
    bool isRoomOccupied() const;
    /*
     * @brief ���������� ������ ��������� �������.
     * @param isOccupied ������ ���������.
     */
    void setOccupied(bool isOccupied);
    /**
     * @brief �������� ���� �� ����.
     * @return ���� �������.
     */
    double getPrice() const;
    /*
     * @brief �������� ���������� � �������.
     * ������� �� ����� ���������� � ������, �����������, ���� � ��������� �������.
     */
    void showRoomInfo() const;
};