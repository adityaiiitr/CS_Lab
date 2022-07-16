#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

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

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    struct Node *root = NULL;
    root = createTree();
    printf("\nInorder: ");
    inOrder(root);
    printf("\nPreorder: ");
    preOrder(root);
    printf("\nPostorder: ");
    postOrder(root);

    return 0;
}