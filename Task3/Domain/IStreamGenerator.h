#pragma once
#include <iostream>
#include <stdexcept>
#include "Generator.h"

class IStreamGenerator : public Generator 
{
private:
    /**
     * @brief Ссылка на входной поток.
     */
    std::istream& input_stream;
public:
    /**
     * @brief Конструктор генератора, принимающий входной поток.
     * @param input Входной поток (по умолчанию std::cin).
     */
    explicit IStreamGenerator(std::istream& input = std::cin);

    /**
     * @brief Считывает и возвращает значение из потока.
     * @return Считанное значение.
     */
    int generate() override;
};
