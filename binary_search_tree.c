// This code is not Completed
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root = NULL;
struct Node *n = NULL;

void insertNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;

        return;
    }
    struct Node *temp = root;
    while (temp != NULL)
    {
        n = temp;
        if (temp->data < data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    if (n->data < data)
    {
        n->right = newNode;
    }
    else
    {
        n->left = newNode;
    }
}

void searchNode(int data)
{
    n = root;
    while (n != NULL)
    {
        if (n->data == data)
        {
            printf("%d Found in BST.\n", data);
            return;
        }
        else if (n->data < data)
        {
            n = n->right;
        }
        else
        {
            n = n->left;
        }
    }
    printf("%d Not Found in BST.\n", data);
}
void inOrder(struct Node *toor)
{
    if (toor == NULL)
        return;
    inOrder(toor->left);
    printf("%d ", toor->data);
    inOrder(toor->right);
}

void deleteNode(int data)
{
    // code to work on
}
int main()
{
    int choice, data;
    printf("\nBST OPerations\n1.Insertion\n2.Deletion\n3.Inorder\n4.Search\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            printf("Enter The Node data: ");
            scanf("%d", &data);
            insertNode(data);
            break;
        case 2:
            break;
        case 3:
            printf("Inorder: ");
            inOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Enter The Data To Search in BST: ");
            scanf("%d", &data);
            searchNode(data);
            break;
        deafult:
            break;
        }
        printf("\nBST OPerations\n1.Insertion\n2.Deletion\n3.Inorder\n4.Search\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }

    return 0;
}