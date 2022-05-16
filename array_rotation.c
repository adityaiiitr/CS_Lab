#include <stdio.h>
int main()
{
    int n;
    printf("Enter Size of Array: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements of Array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int d;
    printf("Rotate Array By: \n");
    scanf("%d", &d);
    int temp[d];
    int i = 0, j = 0;
    for (; i < n; i++)
    {
        if (i < d)
            temp[i] = arr[i];

        if (i >= d)
            arr[j++] = arr[i];
    }
    i = 0;
    while (i < d)
    {
        arr[j++] = temp[i++];
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}