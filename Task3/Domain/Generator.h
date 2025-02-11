#pragma once

class Generator 
{
public:
    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Generator() {}

    /**
     * @brief Генерирует элемент.
     * @return Сгенерированное значение.
     */
    virtual int generate() = 0;
};
