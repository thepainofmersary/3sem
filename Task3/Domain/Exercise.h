#pragma once

#include "Matrix.h"

class Exercise
{
protected:
    Matrix matrix_data;
public:
    /**
     * @brief Конструктор задачи.
     * @param rows Количество строк в матрице.
     * @param cols Количество столбцов в матрице.
     */
    Exercise(int rows, int cols);

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Exercise() {}

    /**
     * @brief Выполняет задачу (должно быть определено в наследниках).
     */
    virtual void perform_task() = 0;

    /**
     * @brief Устанавливает матрицу для выполнения задачи.
     * @param matrix Матрица, на которой будет выполняться задача.
     */
    void set_matrix(const Matrix& matrix);

    /**
     * @brief Возвращает матрицу после выполнения задачи.
     * @return Матрица, обработанная задачей.
     */
    const Matrix& get_result() const;
};
