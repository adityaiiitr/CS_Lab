#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node* front=NULL;
  struct Node*rear=NULL;

void enqueue(int data)
{
   
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;

    if(rear==NULL)
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

void dequeue()
{
    if(front==NULL)
    {
        printf("Underflow! Queue is Empty.\n");
    }
    else
    {
       printf("%d is Dequeue from Queue.\n",front->data);
        front = front->next;
    }

}
void isEmpty()
{
    if(front==NULL)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Queue is Not Empty\n");
    }
}

void isFront()
{
    printf("%d is Front Element in Queue.\n",front->data);
}

void isRear()
{
    printf("%d is Rear Element in Queue.\n",rear->data);
}

void display()
{
   struct Node* temp=front;
    if(temp==NULL)
   {
         printf("Nothing To Display. Queue is Empty\n");
         return;
   }
   
    printf("Queue Elements: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
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
           enqueue(data);
            break;
        case 2:
           dequeue();
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