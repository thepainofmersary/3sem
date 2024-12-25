#include <iostream>
#include "../Domain/Matrix.h"
#include "../Domain/RandomGenerator.h"
#include "../Domain/IStreamGenerator.h"
#include "../Domain/Task1.h"
#include "../Domain/Task2.h"
#include <locale>

int main() 
{
    setlocale(LC_ALL, "RU");
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    Matrix matrix(rows, cols);

    int choice;
    std::cout << "Выберите тип генератора (1 - Random, 2 - Input): ";
    std::cin >> choice;

    if (choice == 1) 
    {
        int min, max;
        std::cout << "Введите минимальное и максимальное значения: ";
        std::cin >> min >> max;
        RandomGenerator random_gen(min, max);
        matrix.fill(&random_gen);
    }
    else if (choice == 2) 
    {
        std::cout << "Введите элементы матрицы: ";
        IStreamGenerator input_gen(std::cin);
        matrix.fill(&input_gen);
    }
    else 
    {
        throw std::invalid_argument("Некорректный выбор.");
        return 1;
    }

    std::cout << "Исходная матрица:\n";
    matrix.print();

    Task1 task1(&matrix);
    std::cout << "После задачи 1:\n";
    task1.perform_task();

    Task2 task2(&matrix);
    std::cout << "После задачи 2:\n";
    task2.perform_task();
 
    return 0;
}
