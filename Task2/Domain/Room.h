#pragma once

#include <iostream>
#include <vector>
#include "Guest.h"

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
    std::vector<Guest*> guests; 

    /*
     * @brief Конструктор комнаты.
     * @param roomNumber Номер комнаты.
     * @param capacity Вместимость комнаты.
     * @param hasFridge Наличие холодильника.
     * @param hasTV Наличие телевизора.
     * @param hasBar Наличие мини-бара.
     * @param price Цена за ночь.
     */
    Room(int roomNumber, int capacity, bool hasFridge, bool hasTV, bool hasBar, double price);

public:
    /*
     * @brief Статический метод для создания объекта Room.
     * @param roomNumber Номер комнаты.
     * @param capacity Вместимость комнаты.
     * @param hasFridge Наличие холодильника.
     * @param hasTV Наличие телевизора.
     * @param hasBar Наличие мини-бара.
     * @param price Цена за ночь.
     * @return Умный указатель на объект Room.
     */
    static std::shared_ptr<Room> create(int roomNumber, int capacity, bool hasFridge, bool hasTV, bool hasBar, double price);

    /*
     * @brief Получить номер комнаты.
     * @return Номер комнаты.
     */
    int getRoomNumber() const;

    /*
     * @brief Проверить, занята ли комната.
     * @return true, если комната занята; иначе false.
     */
    bool isRoomOccupied() const;

    /*
     * @brief Установить статус занятости комнаты.
     * @param isOccupied Новый статус занятости комнаты.
     */
    void setOccupied(bool isOccupied);

    /*
     * @brief Получить цену за ночь проживания в комнате.
     * @return Цена за ночь.
     */
    double getPrice() const;

    /*
     * @brief Вывести на экран информацию о комнате.
     * Включает номер комнаты, вместимость, цену и наличие удобств.
     */
    void showRoomInfo() const;

    /*
     * @brief Добавить гостя в комнату.
     * @param guest Сырой указатель на объект Guest.
     */
    bool addGuest(Guest* guest);

    /*
     * @brief Вывести список гостей в комнате.
     */
    void listGuests() const;
};
