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
     * @brief Конструктор отеля.
     *
     * Инициализирует объект отеля без номеров.
     */
    Hotel();

    /**
     * @brief Добавить комнату в отель.
     * @param room Умный указатель на объект Room, который добавляется в отель.
     */
    void addRoom(const std::shared_ptr<Room>& room);

    /**
     * @brief Показать информацию о доступных номерах.
     */
    void showAvailableRooms() const;

    /**
     * @brief Показать информацию о занятых номерах.
     */
    void showOccupiedRooms() const;

    /**
     * @brief Показать информацию о конкретной комнате.
     * @param roomNumber Номер комнаты.
     */
    void showRoomInfo(int roomNumber) const;
};
