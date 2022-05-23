#include <stdio.h>
void printing(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sorting(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                *(arr + j) = *(arr + j) ^ *(arr + j + 1);
                *(arr + j + 1) = *(arr + j) ^ *(arr + j + 1);
                *(arr + j) = *(arr + j) ^ *(arr + j + 1);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pos[n], neg[n];
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg[j++] = arr[i];
        else
            pos[k++] = arr[i];
    }
    sorting(neg, j);
    sorting(pos, k);
    // printing individula array

    printing(neg, j);
    printing(pos, k);

    merge(neg, j);
    merge(pos, k);

    return 0;
}