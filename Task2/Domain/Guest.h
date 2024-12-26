#pragma once

#include <string>
#include <memory>

class Room; 

class Guest
{
private:
    std::string name; 
    bool isRegularGuest; 
    double discount; 
    std::shared_ptr<Room> room; 

    /**
     * @brief ����������� �����.
     * @param name ��� �����.
     * @param isRegularGuest ����, �������� �� ����� ����������.
     * @param discount ������ ��� ����������� �����.
     */
    Guest(const std::string& name, bool isRegularGuest, double discount);
public:
    /**
     * @brief ����������� ����� ��� �������� ������� Guest.
     * @param name ��� �����.
     * @param isRegularGuest ����, �������� �� ����� ����������.
     * @param discount ������ ��� ����������� �����.
     * @return ����� ��������� �� ������ Guest.
     */
    static std::shared_ptr<Guest> create(const std::string& name, bool isRegularGuest, double discount);

    /**
     * @brief �������� ��� �����.
     * @return ��� �����.
     */
    std::string getName() const;

    /**
     * @brief ���������, �������� �� ����� ����������.
     * @return true, ���� ����� ����������; ����� false.
     */
    bool isRegularGuestFlag() const;

    /**
     * @brief �������� ������ ��� ����������� �����.
     * @return ������.
     */
    double getDiscount() const;

    /**
     * @brief ���������� ������� �����.
     * @param room ����� ��������� �� ������ Room.
     */
    void setRoom(const std::shared_ptr<Room>& room);
};