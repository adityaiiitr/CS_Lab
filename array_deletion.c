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

    int max = arr[0], s_max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > s_max)
        {
            if (arr[i] > max)
            {
                s_max = max;
                max = arr[i];
            }
            if (arr[i] > s_max && arr[i] != max)
                s_max = arr[i];
        }
    }
    printf("S_max%d \n", s_max);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s_max)
            c++;
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        if (arr[i] == s_max)
            continue;
        arr[j++] = arr[i];
    }

    printf("\n");
    for (int i = 0; i < (n - c); i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}