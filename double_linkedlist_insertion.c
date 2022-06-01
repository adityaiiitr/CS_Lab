#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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

void replace(struct Node *n, int newdata, int position) // replace
{
    position--; // This line is needed!
    if (n != NULL)
    {
        while (position--)
        {
            n = n->next;
            if (n == NULL)
            {
                printf("Invalid Position. No Deletion Done!\n");
                return;
            }
        }
        n->data = newdata;
    }
}
// Insertion At Beginning
void insertion_beg(struct Node *head, int new_data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = new_data;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else
    {
        newnode->next = head;
        newnode->prev = NULL;
    }

    head = newnode;
    printing(head);
}
// Insertion At Mid Positions
void insertion_mid(struct Node *n, int new_data, int position)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = new_data;
    newnode->next = NULL;
    position--; // This line is needed!
    if (n != NULL)
    {
        while (position--)
        {
            n = n->next;
            if (n == NULL)
            {
                printf("Invalid Position. No Insertion Done!\n");
                return;
            }
        }
        newnode->next = n->next;
        n->next = newnode;
        newnode->prev = n;
    }
    else
        printf("Empty List.");
}
// Insertion At End
void insertion_end(struct Node *n, int new_data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = new_data;
    newnode->next = NULL;
    if (n != NULL)
    {
        while (n->next != NULL)
        {
            n = n->next;
        }

        newnode->next = n->next;
        n->next = newnode;
        newnode->prev = n;
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

    first->prev = NULL;
    first->data = 10;
    first->next = second;

    second->prev = first;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 40;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 50;
    fifth->next = NULL;

    printing(head);
    int data, choice, position;
    printf("Enter The Data to be added: ");
    scanf("%d", &data);
    printf("Insertion At \n1.Beg \n2.Mid\n3.End\n4.Replace\nEnter The Choice:  ");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insertion_beg(head, data);
        break;

    case 2:
        printf("Enter The Position: ");
        scanf("%d", &position);
        insertion_mid(head, data, position);
        printing(head);
        break;

    case 3:
        insertion_end(head, data);
        printing(head);
        break;
    case 4:
        printf("Enter The Position: ");
        scanf("%d", &position);
        replace(head, data, position);
        printing(head);
        break;
    default:
        printf("Invalid Choice! Exiting...");
        break;
    }

    return 0;
}