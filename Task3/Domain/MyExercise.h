#pragma once
#include "Exercise.h"

class MyExercise : public Exercise
{
public:
    MyExercise(
        int rows,
        int columns,
        std::unique_ptr<Generator> generator,
        std::ostream& out = std::cout)
        : Exercise(rows, columns, std::move(generator), out) {}

    void perform_task() override {} 

protected:
    void Task1() override;
    void Task2() override;
};
