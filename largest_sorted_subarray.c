#include <stdio.h>
int main()
{
    int n, count = 1, max_count = 0;
    printf("Enter The size of array: ");
    scanf("%d", &n);
    int arr[n];
    // int start = 0, end = n - 1;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            count++;
        }
        else
        {
            if (count > max_count)
                max_count = count;
            count = 1;
        }
    }
    if (count > max_count)
        max_count = count;
    if (i != n + 1)
        printf("Sorted Subarray Length %d.", max_count);
    else
        printf("Sorted Subarray Length %d.", (max_count + 1));

    return 0;
}