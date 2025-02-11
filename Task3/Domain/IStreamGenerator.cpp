#include "IStreamGenerator.h"

IStreamGenerator::IStreamGenerator(std::istream& input)
    : input_stream(input) {}

int IStreamGenerator::generate() 
{
    int value = 0;
    this->input_stream >> value;
    return value;
}
