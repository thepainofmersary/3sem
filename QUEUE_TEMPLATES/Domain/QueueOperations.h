#pragma once
#include "../Domain/queue.h"

template <typename T>
class QueueOperations 
{
public:
    static void enqueue(Queue<T>& queue, const T& element);
    static T dequeue(Queue<T>& queue);
    static T peek(const Queue<T>& queue);
};

// Implementation of QueueOperations methods
template <typename T>
void QueueOperations<T>::enqueue(Queue<T>& queue, const T& element) 
{
    queue.enqueue(element);
}

template <typename T>
T QueueOperations<T>::dequeue(Queue<T>& queue) 
{
    return queue.dequeue();
}

template <typename T>
T QueueOperations<T>::peek(const Queue<T>& queue) 
{
    return queue.peek();
}
