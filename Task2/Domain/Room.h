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
     * @brief Конструктор комнаты.
     * @param roomNumber Номер комнаты.
     * @param hasFridge Наличие холодильника.
     * @param hasTV Наличие телевизора.
     * @param hasBar Наличие мини-бара.
     * @param price Цена за ночь.
     */
    Room(int roomNumber, bool hasFridge, bool hasTV, bool hasBar, double price);

    std::shared_ptr<Hotel> hotel;

public:
    /**
     * @brief Статический метод для создания объекта Room.
     * @param roomNumber Номер комнаты.
     * @param hasFridge Наличие холодильника.
     * @param hasTV Наличие телевизора.
     * @param hasBar Наличие мини-бара.
     * @param price Цена за ночь.
     * @return Умный указатель на объект Room.
     */
    static std::shared_ptr<Room> create(int roomNumber, bool hasFridge, bool hasTV, bool hasBar, double price);

    /**
     * @brief Получить номер комнаты.
     * @return Номер комнаты.
     */
    int getRoomNumber() const;

    /**
     * @brief Проверить, занята ли комната.
     * @return true, если комната занята; иначе false.
     */
    bool isRoomOccupied() const;

    /**
     * @brief Установить статус занятости комнаты.
     * @param isOccupied Новый статус занятости комнаты.
     */
    void setOccupied(bool isOccupied);

    /**
     * @brief Получить цену за ночь проживания в комнате.
     * @return Цена за ночь.
     */
    double getPrice() const;

    /**
     * @brief Вывести на экран информацию о комнате.
     * Включает номер комнаты, цену и наличие удобств.
     */
    void showRoomInfo() const;

    /**
     * @brief Добавить гостя в комнату.
     * @param guest Умный указатель на объект Guest.
     */
    void addGuest(const std::shared_ptr<Guest>& guest);
};