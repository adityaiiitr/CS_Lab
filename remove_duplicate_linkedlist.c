#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *n = NULL;

void createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        n = newNode;
        return;
    }
    n->next = newNode;
    n = newNode;
}

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void removeDuplicate()
{

    struct Node *temp = head;
    struct Node *prev = head;
    while (temp != NULL)
    {
        prev = temp;
        n = temp->next;
        while (n != NULL)
        {
            if (n->data == temp->data)
            {
                prev->next = n->next;
            }
            prev = n;
            n = n->next;
        }
        temp = temp->next;
    }
}

int main()
{
    int choice, data;
    printf("1.Add A New Node\n2.Display\n3.Remove Duplicate.\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            printf("Enter The Data: ");
            scanf("%d", &data);
            createNode(data);
            break;
        case 2:
            display();
            break;
        case 3:
            removeDuplicate();
            break;
        default:
            printf("Invalid Choice!. Try Again.");
            break;
        }
        printf("1.Add A New Node\n2.Display\n3.Remove Duplicate.\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }
    return 0;
}