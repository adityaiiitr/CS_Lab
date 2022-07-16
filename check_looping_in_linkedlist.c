#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

int detectLoop()
{
    struct Node *slow_p = head, *fast_p = head;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return 1;
        }
    }
    return 0;
}

void push(int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int main()
{

    push(20);
    push(4);
    push(15);
    push(10);
    head->next->next->next->next = head;
    int n = detectLoop(head);
    if (n)
        printf("Loop found");
    else
        printf("No Loop");
    return 0;
}