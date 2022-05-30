#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// Printing
void printing(struct Node *n)
{

    while (n != NULL)
    {
        printf("%d \n", n->data);
        n = n->next;
    }
}

struct Node *deletion_beg(struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

void deletion_mid(struct Node *n, int position)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    position--; // This line is needed!
    if (n != NULL)
    {
        while (position--)
        {
            temp = n;
            n = n->next;
            if (n == NULL)
            {
                printf("Invalid Position. No Deletion Done!\n");
                return;
            }
        }
        temp->next = n->next;
        n->next = NULL;
        free(n);
    }
    else
        printf("Empty List.");
}

void deletion_end(struct Node *n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (n != NULL)
    {
        while (n->next != NULL)
        {
            temp = n;
            n = n->next;
        }
        temp->next = NULL;
        free(n);
    }
    else
        printf("Empty List.");
}

int main()
{

    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = first;

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    printing(head);
    int choice, position;

    printf("Deletion At \n1.Beg \n2.Mid\n3.End\nEnter The Choice:  ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        head = deletion_beg(head);
        printing(head);
        break;

    case 2:
        printf("Enter The Position: ");
        scanf("%d", &position);
        deletion_mid(head, position);
        printing(head);
        break;

    case 3:
        deletion_end(head);
        printing(head);
        break;
    default:
        printf("Invalid Choice! Exiting...");
        break;
    }

    return 0;
}