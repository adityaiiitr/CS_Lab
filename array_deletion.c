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

    int max = -1, s_max;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            s_max = max;
            max = arr[i];
        }
    }

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