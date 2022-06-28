#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;

    head = temp;

    return head;
}
void peek(struct Node *n)
{
    if (n == NULL)
        printf("Stack is Empty! Can't Peek...\n");
    else
        printf("Top Element of Stack: %d\n", n->data);
}

struct Node *pop(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
        printf("Stack is Empty! Pop not performed.\n");
    else
    {
        printf("%d Poped out of Stack.\n", head->data);
        head = head->next;
        free(temp);
    }
    return head;
}
void isEmpty(struct Node *head)
{
    if (head == NULL)
        printf("Stack is Empty.\n");
    else
        printf("Stack is not Empty.\n");
}

int main()
{
    int choice, data;
    struct Node *head = NULL;
    printf("\nStack Operations:\n1.Push\n2.Pop\n3.isEmpty\n4.Peek\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the Data to be added: ");
            scanf("%d", &data);
            head = push(head, data);
            break;
        case 2:
            head = pop(head);
            break;
        case 3:
            isEmpty(head);
            break;
        case 4:
            peek(head);
            break;

        default:
            printf("Invalid Choice!");
            break;
        }
        printf("\nStack Operations:\n1.Push\n2.Pop\n3.isEmpty\n4.Peek\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }
    return 0;
}