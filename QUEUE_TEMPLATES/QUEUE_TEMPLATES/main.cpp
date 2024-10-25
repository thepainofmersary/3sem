#include <iostream>
#include "../Domain/queue.h"
#include <locale.h>

void displayMenu() 
{
    std::cout << "�������� ��������:\n";
    std::cout << "1. �������� ������� � ������� (enqueue)\n";
    std::cout << "2. ������� ������� �� ������� (dequeue)\n";
    std::cout << "3. ���������� �������� ������� (peek)\n";
    std::cout << "4. ���������, ����� �� ������� (isEmpty)\n";
    std::cout << "5. ������� ���������� ������� (toString)\n";
    std::cout << "0. �����\n";
}

int main() 
{
    setlocale(LC_ALL, "RU");
    Queue<int> queue(5); // ������� ������� �� 5 ���������
    int choice;
    int element;

    do 
    {
        displayMenu();
        std::cout << "��� �����: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            std::cout << "������� ������� ��� ����������: ";
            std::cin >> element;
            try 
            {
                queue.enqueue(element);
                std::cout << "������� " << element << " �������� � �������.\n";
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
                std::cout << "�������� �������: " << element << std::endl;
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
                std::cout << "�������� �������: " << element << std::endl;
            }
            catch (const std::exception& e) 
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << (queue.isEmpty() ? "������� �����." : "������� �� �����.") << std::endl;
            break;
        case 5:
            std::cout << "���������� �������: " << queue << std::endl;
            break;
        case 0:
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "������������ �����. ����������, ���������� �����.\n";
            break;
        }
        std::cout << std::endl;
    } 
    while (choice != 0);

    return 0;
}
