#pragma once
#include <random>
#include "Generator.h"

class RandomGenerator : public Generator 
{
private:
    /**
     * @brief Генератор случайных чисел.
     */
    std::mt19937 generator;

    /**
     * @brief Диапазон значений для генерации.
     */
    std::uniform_int_distribution<int> distribution;

public:
    /**
     * @brief Конструктор генератора случайных чисел.
     * @param min Минимальное значение.
     * @param max Максимальное значение.
     */
    RandomGenerator(int min, int max);

    /**
     * @brief Генерирует случайное значение в заданном диапазоне.
     * @return Случайное значение.
     */
    int generate() override;
};
