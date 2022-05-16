#include <stdio.h>
int main()
{
    int n, count = 0, max_count = 0;
    printf("Enter The size of array: ");
    scanf("%d", &n);
    int arr[n];
    int start = 0, end = n - 1;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
        }
    }

    printf("Sorted Subarray Length %d.", max_count);

    return 0;
}