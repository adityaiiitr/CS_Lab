#include <stdio.h>
#include <stdlib.h>
int length = 0;
struct node
{
    int data;
    struct node *next;
};

void printing(struct node *n)
{
    while (n != NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }
}

struct node *nodeCreation(struct node *head, int new_data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = new_data;
    newnode->next = NULL;
    length++;
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

int main()
{
    struct node *head = NULL;
    int data, t = 1;
    while (t)
    {
        printf("Enter The Data to be added: ");
        scanf("%d", &data);
        head = nodeCreation(head, data);
        printf("Want To Add More Data?\n1.Yes\n0.No\n");
        scanf("%d", &t);
    }

    printing(head);
    return 0;
}