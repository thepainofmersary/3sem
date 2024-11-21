#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <initializer_list>

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
    Queue(size_t size);
    Queue(std::initializer_list<T> other);
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;
    ~Queue();

    void enqueue(const T& element);
    void dequeue();
    T peek() const;
    void removeFront();

    bool isEmpty() const;
    std::string toString() const;

    Queue<T>& operator=(Queue other);

    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue)
    {
        os << queue.toString();
        return os;
    }

    void swap(Queue<T>& other) noexcept;
};

template <typename T>
Queue<T>::Queue(size_t size)
    : data(new T[size]{}), capacity(size), front(0), rear(0), count(0)
{
}

template <typename T>
Queue<T>::Queue(std::initializer_list<T> other)
    : Queue(other.size()) // Делегирование конструктору с размером
{
    for (const T& element : other)
    {
        enqueue(element);
    }
}

template <typename T>
Queue<T>::Queue(const Queue& other)
    : data(new T[other.capacity]{}), capacity(other.capacity), front(0), rear(0), count(0)
{
    for (size_t i = 0; i < other.count; ++i)
    {
        enqueue(other.data[(other.front + i) % other.capacity]);
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
void Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw std::logic_error("Очередь пуста");
    }
    removeFront();
}

template <typename T>
T Queue<T>::peek() const
{
    if (isEmpty())
    {
        throw std::logic_error("Очередь пуста");
    }
    return data[front];
}

template <typename T>
void Queue<T>::removeFront()
{
    if (isEmpty())
    {
        throw std::logic_error("Очередь пуста");
    }
    front = (front + 1) % capacity;
    count--;
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
Queue<T>& Queue<T>::operator=(Queue other)
{
    swap(other);
    return *this;
}

template <typename T>
void Queue<T>::swap(Queue<T>& other) noexcept
{
    std::swap(data, other.data);
    std::swap(capacity, other.capacity);
    std::swap(front, other.front);
    std::swap(rear, other.rear);
    std::swap(count, other.count);
}
