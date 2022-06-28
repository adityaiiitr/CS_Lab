#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

void isFull(struct Stack *stack)
{
    if (stack->top == stack->capacity - 1)
        printf("Stack isFull.\n");
    else
        printf("Stack is Not Full.\n");
}
void isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
        printf("Stack is Empty.\n");
    else
        printf("Stack is Not Empty.\n");
}

struct Stack *push(struct Stack *stack, int data)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack is Full. No Push Performed!\n");
    }
    else
    {
        stack->top += 1;
        stack->array[stack->top] = data;
        printf("%d pushed to stack\n", data);
    }
    return stack;
}

struct Stack *pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is Empty. No Pop Performed!\n");
    }
    else
    {
        int data = stack->array[stack->top--];

        printf("%d poped out of stack\n", data);
    }
    return stack;
}

void peek(struct Stack *stack)
{
    if (stack->top == -1)
        printf("Stack is Empty! Can't Peek...\n");
    else
        printf("Top Element of Stack: %d\n", stack->array[stack->top]);
}

int main()
{
    int n, choice, data;
    printf("Enter The Size of Stack: ");
    scanf("%d", &n);
    struct Stack *stack = createStack(n);
    printf("Stack Operations:\n1.Push\n2.Pop\n3.isFull\n4.isEmpty\n5.Peek\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);

    while (choice)
    {

        switch (choice)
        {
        case 1:
            printf("Enter The Data to be Added: ");

            scanf("%d", &data);
            stack = push(stack, data);
            break;
        case 2:
            stack = pop(stack);
            break;
        case 3:
            isFull(stack);

            break;
        case 4:
            isEmpty(stack);

            break;
        case 5:
            peek(stack);
            break;

        default:
            printf("Invalid Choice!");
        }
        printf("\nStack Operations:\n1.Push\n2.Pop\n3.isFull\n4.isEmpty\n5.Peek\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }
    return 0;
}