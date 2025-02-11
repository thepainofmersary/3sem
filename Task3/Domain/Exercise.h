#pragma once

#include "Matrix.h"

class Exercise
{
protected:
    std::unique_ptr<Matrix> matrix;
    std::ostream& out;
    virtual void Task1() = 0;
    virtual void Task2() = 0;
public:
    /**
     * @brief Конструктор задачи.
     * @param rows Количество строк в матрице.
     * @param cols Количество столбцов в матрице.
     */
    Exercise(int rows, int cols, std::unique_ptr<Generator> generator, std::ostream& out = std::cout);

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Exercise() {}

    /**
     * @brief Выполняет задачу (должно быть определено в наследниках).
     */
    virtual void perform_task() = 0;

    /**
     * @brief Возвращает матрицу после выполнения задачи.
     * @return Матрица, обработанная задачей.
     */
    const Matrix& get_result() const;

    void Run();
};
