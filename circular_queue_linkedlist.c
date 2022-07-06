#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *rear;
    struct Node *front;
    struct Node *next;
};
struct Node*rear=NULL;
struct Node*front=NULL;

void isFront()
{
    if(front==NULL)
        printf("Queue is Empty!\n");
    else
        printf("%d is in Front of Queue.\n",front->data);
}
void isEmpty()
{
    if(rear==NULL)
        printf("Queue is Empty!\n");
    else
        printf("Queue is not Empty!\n");
}
void isRear()
{
    if(rear==NULL)
        printf("Queue is Empty!\n");
    else
        printf("%d is in Rear of Queue.\n",rear->data);
}
void display()
{
    if(rear==NULL)
        printf("Nothing to Display. Queue is Empty.\n");
    else
        {
            printf("Queue: ");
            struct Node* i=front;
            do{
                printf("%d ",i->data);
                i=i->next;
            }while(i!=front);       
            printf("\n");
        }
}

void enQueue(int data)
{
    struct Node*temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=front;
    if(front==NULL)
    {
        rear=temp;
        front=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }   
    printf("%d is enqueued to queue.\n", data);
}

void deQueue()
{
    if(front==NULL)
    {
        printf("Underflow!\n");
    }
    else
    {
        printf("%d is Dequeue from Queue.\n",front->data);
        if(front==rear)
        {
            front=NULL;
            rear=NULL;
        }
        else
        {
            front=front->next;
        }
        
    }
}

int main()
{
    int  choice, data;
    printf("\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.Front\n4.isEmpty\n5.display\n6.Rear\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);
    while (choice)
    {

        switch (choice)
        {
        case 1:
            printf("Enter The Data to be Added: ");
            scanf("%d", &data);
           enQueue(data);
            break;
        case 2:
           deQueue();
            break;
        case 3:
            isFront();
         
            break;
        case 4:
            isEmpty();
           
            break;
        case 5:
            display();
            break;
        case 6:
            isRear();
            break;

        default:
            printf("Invalid Choice!\n");
        }
        printf("\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.Front\n4.isEmpty\n5.display\n6.Rear\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }
    return 0;
}