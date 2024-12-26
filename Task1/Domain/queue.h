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
    int capacity;
    int front;
    int rear;
    int count;
    /*
    * @brief Метод для увеличения вместимости массива
    */
    void resize();
public:
    /*
    * @brief Конструктор по умолчанию
    */
    Queue(int size);
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
    Queue<T>& operator=(Queue<T>& other);
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
    * @brief Дружественная функция для перегрузки оператора вывода
    * @param os - поток вывода
    * @param queue - очередь
    * @return поток вывода
    */
    friend std::ostream& operator<<(std::ostream& os, const Queue& queue);
    /*
    * @brief Получение вместимости массива
    * @param queue - очередь
    * @return Вместимость массива
    */
    size_t getCapacity(const Queue& queue);
    /*
    * @brief Обмен параметрами между двумя очередями
    * @param other - очередь
    */
    void swap(Queue& other) noexcept;
};

template <typename T>
Queue<T>::Queue(int size)
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
        resize();
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
        throw std::out_of_range("Очередь пуста");
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
        throw std::out_of_range("Очередь пуста");
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
Queue<T>& Queue<T>::operator=(Queue<T>& other)
{
    swap(other);
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
    data = new T[capacity];
    for (size_t i = 0; i < count; ++i)

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
void Queue<T>::resize()
{
    size_t newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < count; i++)
    {
        newData[i] = data[(front + i)];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
    front = 0;
    rear = count - 1;
}

template <typename T>
size_t Queue<T>::getCapacity(const Queue& queue)
{
    return queue.capacity;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& queue)
{
    os << queue.toString();
    return os;
}

template <typename T>
void Queue<T>::swap(Queue& other) noexcept
{
    std::swap(data, other.data);
    std::swap(capacity, other.capacity);
    std::swap(count, other.count);
    std::swap(front, other.front);
    std::swap(rear, other.rear);
}