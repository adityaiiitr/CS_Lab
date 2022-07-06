#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data, priority;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enQueue(int data, int priority)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->priority = priority;

    if (front == NULL)
    {

        front = temp;
        rear = temp;
        return;
    }
    if (front->priority <= priority)
    {
        temp->next = front;
        front = temp;
        return;
    }
    struct Node *n = front->next;
    struct Node *pre = front;
    while (n != NULL)
    {

        if (priority > n->priority)
        {
            pre->next = temp;
            temp->next = n;
            return;
        }
        pre = n;
        n = n->next;
    }
    if (n == NULL)
    {
        pre->next = temp;
        temp->next = n;
    }

    printf("%d is enQueue to Queue!\n", data);
}

void deQueue()
{
    if (front == NULL)
    {
        printf("UnderFlow!\n");
    }
    else
    {
        printf("%d is deQueue from Queue!\n", front->data);
        front = front->next;
    }
}

void display()
{
    struct Node *temp = front;
    if (temp == NULL)
    {
        printf("Nothing To Display. Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data, priority;
    printf("\nPriority Queue Operations:\n1.Enqueue\n2.Dequeue\n3.display\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            printf("Enter The Data to be Added: ");
            scanf("%d", &data);
            printf("Enter The Priority of %d: ", data);
            scanf("%d", &priority);
            enQueue(data, priority);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid Choice!\n");
            break;
        }
        printf("\nPriority Queue Operations:\n1.Enqueue\n2.Dequeue\n3.display\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }
    return 0;
}