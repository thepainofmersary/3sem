#include "Exercise.h"

Exercise::Exercise(int rows, int cols)
    : matrix_data(rows, cols) {}

void Exercise::set_matrix(const Matrix& matrix) 
{
    matrix_data = matrix;
}

const Matrix& Exercise::get_result() const
{
    return matrix_data;
}
