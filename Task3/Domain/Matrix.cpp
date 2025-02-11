#include "Matrix.h"

Matrix::Matrix(int rows, int cols)
    : rows(rows), cols(cols), matrix_data(rows, std::vector<int>(cols)) 
{
    if (rows <= 0 || cols <= 0)
    {
        throw std::invalid_argument("Размеры матрицы должны быть положительными числами.");
    }
}

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

void Matrix::print(std::ostream& out) const 
{
    for (const auto& row : matrix_data)
    {
        for (const auto& elem : row) 
        {
            out << elem << " ";
        }
        out << "\n";
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

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    for (const auto& row : matrix.matrix_data)
    {
        for (const auto& elem : row)
        {
            os << elem << " ";
        }
        os << "\n";
    }
    return os;
}   