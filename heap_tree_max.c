#include <stdio.h>
#include <stdlib.h>

struct Heap
{
    int size, pos, n;
    int *array;
};

struct Heap *heap = NULL;

void display()
{
    printf("Heap Elements: ");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

void createHeap(int capacity)
{
    heap = malloc(sizeof(struct Heap));
    heap->size = capacity;
    heap->n = -1;
    heap->array = (int *)malloc(heap->size * sizeof(int));
}

void swap(int parent, int i)
{

    heap->array[parent] = heap->array[parent] ^ heap->array[i];
    heap->array[i] = heap->array[parent] ^ heap->array[i];
    heap->array[parent] = heap->array[parent] ^ heap->array[i];
}

void heapify_max()
{
    int i = heap->n;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap->array[parent] > heap->array[i])
        {
            return;
        }
        else
        {
            swap(parent, i);
        }
        i = (i - 1) / 2;
    }
}

void delete_max()
{

    swap(0, heap->n);

    heap->size--;
    heap->n--;
    int i = 0;
    while (i < heap->n - 2)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (heap->array[i] >= heap->array[leftChild] && heap->array[i] >= heap->array[rightChild])
        {
            return;
        }
        else if (heap->array[rightChild] >= heap->array[leftChild])
        {
            swap(rightChild, i);
            i = rightChild;
        }
        else
        {
            swap(leftChild, i);
            i = leftChild;
        }
    }
    if (heap->n == 2)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if (heap->array[rightChild] >= heap->array[leftChild])
        {
            swap(rightChild, i);
            i = rightChild;
        }
        else
        {
            swap(leftChild, i);
            i = leftChild;
        }
    }
}

void insertHeap(int data)
{
    heap->n = heap->n + 1;
    heap->pos = heap->n;
    heap->array[heap->n] = data;
}

int main()
{
    int capacity, data, choice;
    printf("Enter The Capacity Of Heap: ");
    scanf("%d", &capacity);
    createHeap(capacity);

    printf("Enter The Elements in Heap: ");
    for (int i = 0; i < capacity; i++)
    {
        scanf("%d", &data);
        insertHeap(data);
        heapify_max();
    }

    display();
    printf("1.Delete Max Element Of Heap?\n0.Exit\nEnter Your Choice: ");
    scanf("%d", &choice);

    while (choice)
    {
        delete_max();
        display();
        printf("1.Delete Max Element Of Heap?\n0.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
    }

    return 0;
}