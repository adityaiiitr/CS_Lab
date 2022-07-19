#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];

int front, rear = -1;

int enqueue(int x)
{
    if (front == -1 &&rear = -1)
    {
        front = rear = 0;
        queue[front] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("Queue is Full");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty");
    }
    else if (front == rear)
    {
        front = rear - 1;
    }
    else
    {
        printf("%d", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue: ");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d ", queue[rear]);
    }
}
void main()
{
    enqueue(2);
    enqueue(2);
    enqueue(2);
    enqueue(40);
    enqueue(20);
    enqueue(10);
    display();
    dequeue();
}