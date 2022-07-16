#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root = NULL;

struct Node *insertion(int data)
{
    struct Node *n = root;
    while (1)
    {
        if (data > n->data)
        {
            n = n->right;
        }
        else if (data < n->data)
        {
            n = n->left;
        }
        else
    }
}

struct Node *createTree()
{
    int data;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data (-1) for No Node: ");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    newNode->data = data;
    printf("The Left Child of %d. ", data);
    newNode->left = createTree();
    printf("The Right Child of %d. ", data);
    newNode->right = createTree();

    return newNode;
}

int main()
{

    root = createTree(root);

    return 0;
}