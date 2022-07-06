#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int rear, front, size, capacity;
    int *array;
};

struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0, queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(sizeof(queue->capacity * sizeof(int)));
    return queue;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}
int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue is Full. Can't Enqueue.\n");
        return;
    }
       
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    queue->size = queue->size + 1;
    printf("%d is enqueued to queue.\n", data);
}
void dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty. Can't Queue!\n");
    }
    else
    {
        int data = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size = queue->size - 1;
        printf("%d Dequeued from Queue!\n", data);
    }
}
void display(struct Queue *queue)
{
    
    if (isEmpty(queue))
    {
        printf("Queue is Empty Can't Display\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = queue->front; i < queue->size; i++)
        printf("%d ", queue->array[i]);
    printf("\n");
}

int main()
{
    int n, choice, data, check;
    printf("Enter The Capacity Of Queue: ");
    scanf("%d", &n);
    struct Queue *queue = createQueue(n);
    printf("\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.isFull\n4.isEmpty\n5.display\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);

    while (choice)
    {

        switch (choice)
        {
        case 1:
            printf("Enter The Data to be Added: ");
            scanf("%d", &data);
            enqueue(queue, data);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            check = isFull(queue);
            if (check)
                printf("Queue is Full.\n");
            else
                printf("Queue Not Full.");
            break;
        case 4:
            check = isEmpty(queue);
            if (check)
                printf("Queue is Empty.\n");
            else
                printf("Queue Not Empty.");
            break;
        case 5:
            display(queue);

            break;

        default:
            printf("Invalid Choice!");
        }
        printf("\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.isFull\n4.isEmpty\n5.display\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }
    return 0;
}
