#include "Task2.h"

Task2::Task2(Matrix* matrix) : Exercise(matrix->get_rows(), matrix->get_cols())
{
    matrix_data = *matrix;
}

void Task2::perform_task()
{
    for (size_t i = 0; i < matrix_data.get_rows(); ++i)
    {
        if (matrix_data.get_row(i)[0] % 3 == 0)
        {
            std::vector<int> zero_row(matrix_data.get_cols(), 0);
            matrix_data.insert_row(i, zero_row);
            ++i; 
        }
    }
    matrix_data.print();
}
