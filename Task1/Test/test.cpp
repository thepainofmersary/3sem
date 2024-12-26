#include "pch.h"
#include "../Domain/queue.h"
#include <iostream>
#include <locale.h>

TEST(Tostring_Queue_Success)
{
    Queue<int> q(5);
    EXPECT_EQ("Очередь: ", q.toString());

}

TEST(Enqueue_Queue_Success)
{
    Queue<int> q(5);
    q.enqueue(10);
    EXPECT_EQ(q.toString(), "Очередь: 10 ");
}

/*
TEST(Rear_Queue_Success)
{
    Queue<int> q(0);
    EXPECT_EQ(q.rear, -1);
}
*/

TEST(NegativeElement_Queue_Success)
{
    Queue<int> q(5);
    q.enqueue(-5);
    EXPECT_EQ(q.toString(), "Очередь: -5 ");
}

TEST(Dequeue_Queue_Success)
{
    Queue<int> q = { 1, 2, 3 };
    q.dequeue();
    EXPECT_EQ(q.toString(), "Очередь: 2 3 ");
}

TEST(Peek_Queue_Success)
{
    Queue<int> q = { 5, 10, 15 };
    EXPECT_EQ(q.peek(), 5);
}

TEST(IsEmpty_Queue_Success)
{
    Queue<int> q(3);
    EXPECT_TRUE(q.isEmpty());
    q.enqueue(1);
    EXPECT_FALSE(q.isEmpty());
}

TEST(AssignmentOperator_Copy_Success)
{
    Queue<int> q1 = { 1, 2, 3 };
    Queue<int> q2(5);
    q2 = q1;
    EXPECT_EQ(q2.toString(), "Очередь: 1 2 3 ");
}

TEST(AssignmentOperator_Move_Success)
{
    Queue<int> q1 = { 1, 2, 3 };
    Queue<int> q2 = std::move(q1);
    EXPECT_EQ(q2.toString(), "Очередь: 1 2 3 ");
    EXPECT_TRUE(q1.isEmpty());
}

TEST(Constructor_Copy_Success)
{
    Queue<int> q1 = { 1, 2, 3 };
    Queue<int> q2(q1);
    EXPECT_EQ(q2.toString(), "Очередь: 1 2 3 ");
}

TEST(Constructor_Move_Success)
{
    Queue<int> q1 = { 1, 2, 3 };
    Queue<int> q2(std::move(q1));
    EXPECT_EQ(q2.toString(), "Очередь: 1 2 3 ");
    EXPECT_TRUE(q1.isEmpty());
}

TEST(InitializerList_Queue_Success)
{
    Queue<int> q = { 10, 20, 30 };
    EXPECT_EQ(q.toString(), "Очередь: 10 20 30 ");
}

TEST(Enqueue_FullQueueResize_Success)
{
    Queue<int> q(2);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQ(q.getCapacity(q), 4);
}

TEST(Dequeue_EmptyQueue_Throws)
{
    Queue<int> q(2);
    EXPECT_THROW(q.dequeue(), std::out_of_range);
}

TEST(Peek_EmptyQueue_Throws)
{
    Queue<int> q(2);
    EXPECT_THROW(q.peek(), std::out_of_range);
}

TEST(Enqueue_Queue_Double_Success)
{
    Queue<double> q(5);
    q.enqueue(10.23);
    EXPECT_EQ(q.toString(), "Очередь: 10.23 ");
}

TEST(Enqueue_Queue_Char_Success)
{
    Queue<char> q(5);
    q.enqueue('А');
    EXPECT_EQ(q.toString(), "Очередь: А ");
}
