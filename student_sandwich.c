#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int pos;
    int student;
    struct Queue *next;
};

struct Stack{
    int sandwich;
   
    int capacity;
    struct Stack *next;
};
 int size=0;
struct Stack* top=NULL;
struct Queue* front=NULL;
struct Queue* rear=NULL;

void enQueue(int data)
{
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->student=data;
   
    queue->next=NULL;

    if(front==NULL)
    {
        front=queue;
        rear=queue;
    }
    else
    {
        rear->next=queue;
        rear=queue;
    }
}

void deQueue()
{
    front=front->next;
       
      /*
    if(front==NULL || top->size==0)
    {
        
    }
    else
    {   
        
    }*/
}

void shiftStudent()
{
    
    
        rear->next=front;
        front=front->next;
        rear=rear->next;
        rear->next=NULL;
   
}

void push(int data)
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->sandwich=data;
    stack->next=top;
    top=stack;
}

void pop()
{    
    top=top->next;
   
}
void display()
{
   struct Queue* temp=front;
   
   
    printf("Students Choice: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->student);
        temp=temp->next;
    }
    printf("\n");
    free(temp);
   struct Stack* tem=top;
     printf("Sandwich: ");
    while(tem!=NULL)
    {
        printf("%d ",tem->sandwich);
        tem=tem->next;
    }
    printf("\n");

}

int Check()
{
     int counter=0;
    while(size--)
    {
       
        if(top->sandwich==front->student)
        {
        
            
            deQueue();
            pop();
            
            
           
        }
        else
        {
           size++;
           counter++;
                
            shiftStudent();
            if(counter>size)
            break;
           
        }
        display();
    }
    counter=0;
    while(top!=NULL)
    {
        top=top->next;
        counter++;
    }
   return counter;
}


int main()
{
    int n,choice;
    printf("Enter The Number Of students: ");
    scanf("%d",&size);

   int num=n=size;
    while(n--)
    {
        printf("Enter The Student choice: ");
        scanf("%d",&choice);
        enQueue(choice);
    }
    while(num--)
    {
        printf("Enter The Sandwich: ");
        scanf("%d",&choice);
        push(choice);
    }
    display();
    num=Check();
    printf("%d Number of Students.",num);

    return 0;
}
