//Code is Incomplete!


#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int rear,front,size,capacity;
    int*arr;
};

struct Queue * createQueue(int n)
{
    struct Queue*queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity=n;
    queue->front=queue->size=-1;
    queue->rear=capacity-1;
    queue->array=(struct Queue*)malloc(sizeof(int)*queue->capacity);
    return queue;
}
void enQueue
void isEmpty()
{

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
            enQueue(queue, data);
            break;
        case 2:
            deQueue(queue);
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

