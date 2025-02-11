#include "MyExercise.h"
#include <iostream>
#include "Matrix.h"

void MyExercise::Task1()
{
    matrix->print(out);
    for (size_t i = 0; i < matrix->get_rows(); ++i)
    {
        int max_value = matrix->get_element(i, 0);
        int max_index = 0;

        for (size_t j = 1; j < matrix->get_cols(); ++j)
        {
            int current_value = matrix->get_element(i, j);
            if (current_value > max_value)
            {
                max_value = current_value;
                max_index = j;
            }
        }
        matrix->set_element(i, max_index, 0);
    }
    out << *matrix << std::endl;
}

void MyExercise::Task2()
{
    for (size_t i = 0; i < matrix->get_rows(); ++i)
    {
        if (matrix->get_row(i)[0] % 3 == 0)
        {
            std::vector<int> zero_row(matrix->get_cols(), 0);
            matrix->insert_row(i, zero_row);
            ++i;
        }
    }
    out << *matrix << std::endl;
}