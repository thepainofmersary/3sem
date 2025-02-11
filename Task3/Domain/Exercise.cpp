#include "Exercise.h"
#include <memory>

Exercise::Exercise(int rows, int cols, std::unique_ptr<Generator> generator, std::ostream& out)
    : out(out)
{
    matrix = std::make_unique<Matrix>(rows, cols);
    matrix->fill(generator.get());
}

void Exercise::Run()
{
    Task1();
    Task2();
}


//const Matrix& Exercise::get_result() const
//{
//    return matrix_data;
//}