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
    Guest(const std::string& name, bool isRegularGuest, double discount, const std::shared_ptr<Room>& room);
public:
    /**
     * @brief Статический метод для создания объекта Guest.
     * @param name Имя гостя.
     * @param isRegularGuest Флаг, является ли гость постоянным.
     * @param discount Скидка для постоянного гостя.
     * @return Умный указатель на объект Guest.
     */
    static std::shared_ptr<Guest> create(const std::string& name, bool isRegularGuest, double discount, const std::shared_ptr<Room>& room);

    /**
     * @brief Получить имя гостя.
     * @return Имя гостя.
     */
    std::string getName() const;

    std::shared_ptr<Room> getRoom() const;

    /*
    * @brief Установить комнату гостя.
    * @param room Умный указатель на объект Room.
    */
    void setRoom(const std::shared_ptr<Room>&room);
};