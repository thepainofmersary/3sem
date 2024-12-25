#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include "Generator.h"

class Matrix
{
private:
    /**
     * @brief Двумерный вектор для хранения элементов матрицы.
     */
    std::vector<std::vector<int>> matrix_data;

    /**
     * @brief Количество строк в матрице.
     */
    size_t rows;

    /**
     * @brief Количество столбцов в матрице.
     */
    size_t cols;

public:
    /**
     * @brief Конструктор матрицы.
     * @param rows Количество строк.
     * @param cols Количество столбцов.
     */
    Matrix(int rows, int cols);

    /**
     * @brief Заполняет матрицу значениями, сгенерированными переданным генератором.
     * @param gen Указатель на генератор.
     */
    void fill(Generator* gen);

    /**
     * @brief Печатает матрицу на экран.
     */
    void print() const;

    /**
     * @brief Возвращает строку матрицы по индексу.
     * @param index Индекс строки.
     * @return Константная ссылка на строку.
     */
    const std::vector<int>& get_row(int index) const;

    /**
     * @brief Получает количество строк в матрице.
     * @return Количество строк.
     */
    size_t get_rows() const;

    /**
     * @brief Получает количество столбцов в матрице.
     * @return Количество столбцов.
     */
    size_t get_cols() const;

    /**
     * @brief Получает элемент матрицы по индексам строки и столбца.
     * @param row Индекс строки.
     * @param col Индекс столбца.
     * @return Значение элемента.
     */
    int get_element(int row, int col) const;

    /**
     * @brief Устанавливает значение элемента матрицы.
     * @param row Индекс строки.
     * @param col Индекс столбца.
     * @param value Новое значение.
     */
    void set_element(int row, int col, int value);

    /**
     * @brief Вставляет строку из нулей перед указанной строкой.
     * @param index Индекс строки.
     */
    void insert_row(int index, const std::vector<int>& row);
};
