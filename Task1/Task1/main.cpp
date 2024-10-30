#include <iostream>
#include "../Domain/queue.h"
#include <locale.h>

void displayMenu()
{
    std::cout << "Выберите действие:\n";
    std::cout << "1. Добавить элемент в очередь (enqueue)\n";
    std::cout << "2. Извлечь элемент из очереди (dequeue)\n";
    std::cout << "3. Посмотреть головной элемент (peek)\n";
    std::cout << "4. Проверить, пуста ли очередь (isEmpty)\n";
    std::cout << "5. Вывести содержимое очереди (toString)\n";
    std::cout << "0. Выход\n";
}

int main()
{
    setlocale(LC_ALL, "RU");
    Queue<int> queue(5); // Создаем очередь на 5 элементов
    int choice;
    int element;

    do
    {
        displayMenu();
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите элемент для добавления: ";
            std::cin >> element;
            try
            {
                queue.enqueue(element);
                std::cout << "Элемент " << element << " добавлен в очередь.\n";
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case 2:
            try
            {
                element = queue.dequeue();
                std::cout << "Извлечен элемент: " << element << std::endl;
            }
            catch (const std::exception& exception)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case 3:
            try
            {
                element = queue.peek();
                std::cout << "Головной элемент: " << element << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << (queue.isEmpty() ? "Очередь пуста." : "Очередь не пуста.") << std::endl;
            break;
        case 5:
            std::cout << "Содержимое очереди: " << queue << std::endl;
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
        std::cout << std::endl;
    } while (choice != 0);
    return 0;
}
