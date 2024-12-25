#include "Matrix.h"

Matrix::Matrix(int rows, int cols)
    : rows(rows), cols(cols), matrix_data(rows, std::vector<int>(cols)) {}

void Matrix::fill(Generator* gen) 
{
    for (auto& row : matrix_data) 
    {
        for (auto& elem : row) 
        {
            elem = gen->generate();
        }
    }
}

void Matrix::print() const 
{
    for (const auto& row : matrix_data)
    {
        for (const auto& elem : row) 
        {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
}

const std::vector<int>& Matrix::get_row(int index) const 
{
    return matrix_data.at(index);
}

size_t Matrix::get_rows() const 
{
    return rows;
}

size_t Matrix::get_cols() const
{
    return cols;
}

int Matrix::get_element(int row, int col) const
{
    return matrix_data.at(row).at(col);
}

void Matrix::set_element(int row, int col, int value)
{
    matrix_data.at(row).at(col) = value;
}

void Matrix::insert_row(int index, const std::vector<int>& row) 
{
    matrix_data.insert(matrix_data.begin() + index, row);
    ++rows;
}
