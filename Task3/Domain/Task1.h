#pragma once

#include "Exercise.h"

class Task1 : public Exercise
{
public:
    /**
     * @brief Конструктор задачи 1.
     * @param matrix Указатель на матрицу, с которой будет выполняться задача.
     */
    Task1(Matrix* matrix);

    /**
     * @brief Выполняет задачу — заменяет максимальный элемент каждой строки на 0.
     */
    void perform_task() override;
};
