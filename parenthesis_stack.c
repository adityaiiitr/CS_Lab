#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *push(struct Node *head, char ch)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = ch;
    temp->next = head;
    head = temp;

    return head;
}
struct Node *pop(struct Node *head)
{

    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Parenthesis Not Balanced");
        exit(0);
    }
    head = head->next;
    free(temp);

    return head;
}

int parenthesis_check(struct Node *head, char arr[])
{

    for (int i = 0; i < strlen(arr); i++)
    {

        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
            head = push(head, arr[i]);
        if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {

            if (head == NULL)
                return 1;

            else if (arr[i] == '}' && head->data == '{')
                head = pop(head);
            else if (arr[i] == ']' && head->data == '[')
                head = pop(head);
            else if (arr[i] == ')' && head->data == '(')
                head = pop(head);
            else
                return 1;
        }
    }
    if (head == NULL)
        return 0;
}

int main()
{
    struct Node *head = NULL;
    char str[100];
    printf("Enter The expression: ");
    gets(str);
    // scanf("%s", &str);

    if (parenthesis_check(head, str))
        printf("Parenthesis Not Balanced");
    else
        printf("Parenthesis Balanced");
    return 0;
}