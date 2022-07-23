#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    struct Node *next;
};
struct Node *head = NULL;
struct Node *prev = NULL;

void createNode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        prev = head = newnode;
    }
    else
    {
        prev->next = newnode;
        prev = newnode;
    }
}
void push(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->next = head;
    head = newnode;
}
void pop()
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    push(temp->data);
    free(temp);
}

void display()
{
    prev = head;
    while (prev != NULL)
    {
        printf("%d ", prev->data);
        prev = prev->next;
    }
    printf("\n");
}

int main()
{
    int n, data;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    printf("Enter the data: ");
    while (n--)
    {
        scanf("%d", &data);
        createNode(data);
    }
    printf("Original: ");
    display();

    printf("Enter the Roll Number: ");
    scanf("%d", &n);
    n = n % 10;
    while (n--)
    {
        pop();
    }
    printf("After Rotation: ");
    display();
    return 0;
}