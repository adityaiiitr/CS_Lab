// Code is Incomplete

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printing(struct Node *n)
{
    struct Node *head = n;
    do
    {
        printf("%d\n", n->data);
        n = n->next;
    } while (n != head);
}

struct Node *nodeCreation(struct Node *head, int new_data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newnode->data = new_data;
    newnode->next = NULL;

    if (temp == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    return head;
}

// Insertion At Beginning
void insertion_beg(struct Node *head, int new_data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = new_data;
    struct Node *n = head;
    while (n->next != head)
    {
        n = n->next;
    }
    newnode->next = head;

    head = newnode;
    n->next = head;
    printing(head);
}

// Insertion At Mid Positions
void insertion_mid(struct Node *n, int new_data, int position)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = new_data;
    newnode->next = NULL;
    position--;
    if (n != NULL)
    {
        for (; position; position--)
        {
            n = n->next;
        }
    }
    else
    {
        printf("Empty List!...");
    }
    /*while (position--)
    {
        n = n->next;
    }*/
    newnode->next = n->next;
    n->next = newnode;
}

// Insertion At End
void insertion_end(struct Node *n, int new_data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = new_data;
    newnode->next = NULL;
    struct Node *head = n;
    while (n->next != head)
    {
        n = n->next;
    }

    newnode->next = n->next;
    n->next = newnode;
}

int main()
{
    struct Node *head = NULL;
    int data, t = 1;
    printf("|| Node Creation Begins ||\n");
    while (t)
    {
        printf("Enter The Data to be added: ");
        scanf("%d", &data);
        head = nodeCreation(head, data);
        printf("Want To Add More Data?\n1.Yes\n0.No\n");
        scanf("%d", &t);
    }
    printf("\n|| Node Creation Ends ||\n\n");
    printf("|| Linked List Formed ||\n");

    printing(head);

    printf("|| Linked List Insertion Operations ||\n");
    int choice, position;
    printf("Enter The Data to be added: ");
    scanf("%d", &data);
    printf("Deletion At \n1.Beg \n2.Mid\n3.End\nEnter The Choice:  ");

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
        printf("\n|| New Linked List Formed ||\n");
        printing(head);
        break;

    case 3:
        insertion_end(head, data);
        printf("\n|| New Linked List Formed ||\n");
        printing(head);
        break;
    default:
        printf("Invalid Choice! Exiting...");
        break;
    }

    return 0;
}
