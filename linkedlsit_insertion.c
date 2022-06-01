#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// Printing also the middle One
void printing(struct Node *n)
{
    int arr[100], i = 0;

    while (n != NULL)
    {
        arr[i++] = n->data;
        printf("%d \n", n->data);
        n = n->next;
    }
    printf("Middle Elements: %d \n\n", arr[i / 2]);
}
// Node Creation
struct Node *nodeCreation(struct Node *head, int new_data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newnode->data = new_data;
    newnode->next = NULL;
    if (temp == NULL)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}
// Insertion At Beginning
void insertion_beg(struct Node *head, int new_data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = new_data;
    if (head == NULL)
        newnode->next = NULL;
    else
        newnode->next = head;
    head = newnode;
    printf("\n|| New Linked List Formed ||\n");
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
    }
    else
        printf("Empty List.");
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
    printf("Insertion At \n1.Beg \n2.Mid\n3.End\nEnter The Choice:  ");

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