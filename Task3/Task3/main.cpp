#include <iostream>
#include "../Domain/Matrix.h"
#include "../Domain/RandomGenerator.h"
#include "../Domain/IStreamGenerator.h"
#include "../Domain/MyExercise.h"
#include <locale>

int main() 
{
    setlocale(LC_ALL, "RU");
    std::unique_ptr<Generator> randomGenerator = std::make_unique<RandomGenerator>(1, 100);
    
    MyExercise exercise(3, 3, std::move(randomGenerator));
    
    exercise.Run();

    return 0;
}
