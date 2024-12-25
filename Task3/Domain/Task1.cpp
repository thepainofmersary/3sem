#include "Task1.h"

Task1::Task1(Matrix* matrix) : Exercise(matrix->get_rows(), matrix->get_cols())
{
    matrix_data = *matrix;
}

void Task1::perform_task()
{
    for (size_t i = 0; i < matrix_data.get_rows(); ++i)
    {
        int max_value = matrix_data.get_element(i, 0);
        int max_index = 0;

        for (size_t j = 1; j < matrix_data.get_cols(); ++j)
        {
            int current_value = matrix_data.get_element(i, j);
            if (current_value > max_value)
            {
                max_value = current_value;
                max_index = j;
            }
        }
        matrix_data.set_element(i, max_index, 0);
    }
    matrix_data.print();
}
