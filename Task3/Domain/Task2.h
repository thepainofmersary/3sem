#pragma once

#include "Exercise.h"

class Task2 : public Exercise
{
public:
    /**
     * @brief Конструктор задачи 2.
     * @param matrix Указатель на матрицу, с которой будет выполняться задача.
     */
    Task2(Matrix* matrix);

    /**
     * @brief Выполняет задачу — вставляет строку из нулей перед строками,
     *        первый элемент которых делится на 3.
     */
    void perform_task() override;
};
