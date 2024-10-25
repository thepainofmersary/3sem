#pragma once
#include <iostream>
#include <stdexcept>
#include <sstream>

template <typename T>
class Queue 
{
private:
    T* data;        // Массив для хранения элементов очереди
    size_t capacity; // Вместимость очереди
    size_t front;    // Индекс переднего элемента
    size_t rear;     // Индекс заднего элемента
    size_t count;    // Количество элементов в очереди

public:
    Queue(size_t size); // Конструктор
    ~Queue();           // Деструктор

    void enqueue(const T& element);
    T dequeue();
    T peek() const;
    bool isEmpty() const;
    std::string toString() const;

    // Операторы
    Queue<T>& operator=(const Queue<T>& other);
    Queue<T>& operator=(Queue<T>&& other) noexcept;

    // Друзья
    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
        os << queue.toString();
        return os;
    }
};

// Реализация методов Queue
template <typename T>
Queue<T>::Queue(size_t size)
    : capacity(size), front(0), rear(0), count(0) 
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
    data[rear] = element;
    rear = (rear + 1) % capacity;
    count++;
}

template <typename T>
T Queue<T>::dequeue() 
{
    if (isEmpty()) 
    {
        throw std::underflow_error("Очередь пуста");
    }
    T item = data[front];
    front = (front + 1) % capacity;
    count--;
    return item;
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
    if (isEmpty()) 
    {
        oss << "Очередь пуста";
    }
    else 
    {
        for (size_t i = 0; i < count; ++i) 
        {
            oss << data[(front + i) % capacity] << " ";
        }
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
        data[(front + i) % capacity] = other.data[(front + i) % capacity];
    }

    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) noexcept 
{
    if (this == &other) return *this;
    delete[] data;

    data = other.data;
    capacity = other.capacity;
    front = other.front;
    rear = other.rear;
    count = other.count;

    other.data = nullptr; // Предотвращаем удаление
    return *this;
}
