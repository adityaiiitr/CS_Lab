#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int person;
    struct Node *next;
};

struct Node *head;
struct Node *prev;
int totalPerson;

void createNode(int n)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->person = n;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        prev = head;
        return;
    }

    newNode->next = head;
    head = newNode;
}

struct Node *deletePerson(struct Node *temp, struct Node *n)
{

    temp->next = n->next;
    n->next = NULL;
    free(n);
    return temp->next;
}

void problemFunction(int a, int b)
{
    struct Node *n = head;
    prev = n;
    int p = a, k = b;
    while (p != 1)
    {
        int k = b;
        while (k != 1)
        {
            prev = n;
            n = n->next;
            k--;
        }
        n = deletePerson(prev, n);
        p--;
    }
}

int main()
{
    int n, k;
    printf("Enter The Number Person: ");
    scanf("%d", &totalPerson);
    printf("Enter The Number of skip: ");
    scanf("%d", &k);

    n = totalPerson;
    while (n > 0)
    {
        createNode(n);
        n--;
    }
    prev->next = head;

    problemFunction(totalPerson, k);
    printf("Person %d Won!\n", prev->person);
    return 0;
}