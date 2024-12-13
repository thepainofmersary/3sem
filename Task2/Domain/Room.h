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
     * @param isOccupied Статус занятости.
     */
    void setOccupied(bool isOccupied);
    /**
     * @brief Получить цену за ночь.
     * @return Цена комнаты.
     */
    double getPrice() const;
    /*
     * @brief Показать информацию о комнате.
     * Выводит на экран информацию о номере, вместимости, цене и удобствах комнаты.
     */
    void showRoomInfo() const;
};