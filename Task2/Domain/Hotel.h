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
     * @brief Конструктор отеля.
     *
     * Инициализирует объект отеля без номеров и гостей.
     */
    Hotel();
    /*
     * @brief Добавить комнату в отель.
     * @param room Умный указатель на объект Room, который добавляется в отель.
     */
    void addRoom(const std::shared_ptr<Room>& room);
    /*
     * @brief Добавить гостя в отель.
     * @param guest Умный указатель на объект Guest, который добавляется в отель.
     */
    void addGuest(const std::shared_ptr<Guest>& guest);
    /*
     * @brief Получить гостя по индексу.
     * @param index Индекс гостя в списке.
     * @return Умный указатель на объект Guest.
     */
    std::shared_ptr<Guest> getGuest(int index) const;

    /*
     * @brief Показать информацию о доступных номерах.
     */
    void showAvailableRooms() const;
    /*
     * @brief Показать информацию о занятых номерах.
     */
    void showOccupiedRooms() const;
    /*
     * @brief Показать информацию о комнате.
     * @param roomNumber Номер комнаты.
     */
    void showRoomInfo(int roomNumber) const;
    /*
     * @brief Показать скидки для постоянных гостей.
     */
    void showDiscounts() const;
    /*
     * @brief Забронировать комнату для гостя.
     * @param roomNumber Номер комнаты.
     * @param guest Умный указатель на объект Guest.
     */
    void bookRoom(int roomNumber, const std::shared_ptr<Guest>& guest);
};