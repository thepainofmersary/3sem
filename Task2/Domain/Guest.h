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
     * @brief Конструктор гостя.
     * @param name Имя гостя.
     * @param isRegularGuest Флаг, является ли гость постоянным.
     * @param discount Скидка для постоянного гостя.
     */
    Guest(const std::string& name, bool isRegularGuest, double discount);
public:
    /**
     * @brief Статический метод для создания объекта Guest.
     * @param name Имя гостя.
     * @param isRegularGuest Флаг, является ли гость постоянным.
     * @param discount Скидка для постоянного гостя.
     * @return Умный указатель на объект Guest.
     */
    static std::shared_ptr<Guest> create(const std::string& name, bool isRegularGuest, double discount);

    /**
     * @brief Получить имя гостя.
     * @return Имя гостя.
     */
    std::string getName() const;

    /**
     * @brief Проверить, является ли гость постоянным.
     * @return true, если гость постоянный; иначе false.
     */
    bool isRegularGuestFlag() const;

    /**
     * @brief Получить скидку для постоянного гостя.
     * @return Скидка.
     */
    double getDiscount() const;

    /**
     * @brief Установить комнату гостя.
     * @param room Умный указатель на объект Room.
     */
    void setRoom(const std::shared_ptr<Room>& room);
};