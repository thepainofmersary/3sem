#pragma once
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <initializer_list>

template <typename T>
class Queue
{
private:
    T* data;
    size_t capacity;
    size_t front;
    size_t rear;
    size_t count;
public:
    /*
    * @brief Конструктор по умолчанию
    */
    Queue(size_t size);
    /*
    * @brief Деструктор
    */
    ~Queue();
    /*
    * @brief Добавление элемента в конец очереди
    * @param value - значение, которое будет добавлено
    */
    void enqueue(const T& element);
    /*
    * @brief Извлечение элемента из начала очереди
    */
    void dequeue();
    /*
    * @brief Чтение головного элемента
    * @return Головной элемент
    */
    T peek() const;
    /*
    * @brief Проверка, пуста ли очередь
    * @param True - если пуста
    */
    bool isEmpty() const;
    /*
    * @brief Вывод содержимого очереди в строку
    * @return Строку
    */
    std::string toString() const;
    /*
    * @brief Оператор присваивания копированием
    * @param other - очередь
    * @return Ссылка на измененную очередь
    */
    Queue<T>& operator=(const Queue<T>& other);
    /*
    * @brief Оператор присваивания перемещением
    * @param other - очередь
    * @return Ссылка на измененную очередь
    */
    Queue<T>& operator=(Queue<T>&& other) noexcept;
    /**
    * @brief Конструктор с использованием std::initializer_list.
    * @param other Список инициализации, содержащий элементы для добавления в очередь.
    */
    Queue(std::initializer_list<T> other);
    /*
    * @brief Конструктор копирования
    * @param other - очередь
    */
    Queue(const Queue& other);
    /*
    * @brief Конструктор перемещения
    * @param other - очередь
    */
    Queue(Queue&& other) noexcept;
    /*
    * @brief Функция вывода очереди
    */
    void printQueue();
};

template <typename T>
Queue<T>::Queue(size_t size)
    : capacity(size), front(0), rear(-1), count(0)
{
    data = new T[capacity];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] data;
}

template <typename T>
void Queue<T>::enqueue(const T& element)
{
    if (count == capacity)
    {
        throw std::overflow_error("Очередь заполнена");
    }
    rear = rear + 1;
    data[rear] = element;
    count++;
}

template <typename T>
void Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw std::underflow_error("Очередь пуста");
    }
    T item = data[front];
    front = front + 1;
    count--;
}

template <typename T>
T Queue<T>::peek() const
{
    if (isEmpty())
    {
        throw std::underflow_error("Очередь пуста");
    }
    return data[front];
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return count == 0;
}

template <typename T>
std::string Queue<T>::toString() const
{
    std::ostringstream oss;
    oss << "Очередь: ";
    for (size_t i = 0; i < count; i++)
    {
        oss << data[(front + i)] << " ";
    }
    return oss.str();
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this == &other) return *this;
    delete[] data;

    capacity = other.capacity;
    front = other.front;
    rear = other.rear;
    count = other.count;
    data = new T[capacity];

    for (size_t i = 0; i < count; ++i)
    {
        data[(front + i)] = other.data[(front + i)];
    }

    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) noexcept
{
    if (this != &other)
    {
        data = other.data;
        capacity = other.capacity;
        count = other.count;
        front = other.front;
        rear = other.rear;

        other.data = nullptr;
        other.capacity = 0;
        other.count = 0;
        other.front = 0;
        other.rear = 0;
    }
    return *this;
}

template <typename T>
Queue<T>::Queue(std::initializer_list<T> other)
    : Queue(other.size())
{
    for (const T& element : other)
    {
        enqueue(element);
    }
}

template <typename T>
Queue<T>::Queue(const Queue& other)
    : capacity(other.capacity), front(other.front), rear(other.rear), count(other.count)
{
    data = new T[other.capacity];
    for (size_t i = 0; i < other.count; ++i)

    {
        data[i] = other.data[i];
    }
}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept
    : data(other.data), capacity(other.capacity), front(other.front), rear(other.rear), count(other.count)
{
    other.data = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.rear = 0;
    other.count = 0;
}

template <typename T>
void Queue<T>::printQueue()
{
    if (isEmpty())
    {
        std::cout << "Очередь пуста!" << std::endl;
        return;
    }

    for (size_t i = 0; i < count; ++i)
    {
        std::cout << data[front] << std::endl;
        front = front + 1;
    }
}