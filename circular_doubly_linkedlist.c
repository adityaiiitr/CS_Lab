#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *insertion_beg(struct Node *n, int new_data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = new_data;

    newnode->next = n;
    newnode->prev = NULL;

    n->prev->next = newnode;
    newnode->prev = n->prev;
    n->prev = newnode;

    return newnode;
}

// Printing
void printing(struct Node *head)
{
    struct Node *temp = head;
    do
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    } while (temp != head);

    while (temp != head)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = first;

    first->prev = fifth;
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
    fifth->next = first;

    printing(head);
    head = insertion_beg(head, 1000);
    printf("Printing After Adding 1000\n");
    printing(head);

    return 0;
}