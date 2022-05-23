#include <stdio.h>
int main()
{
    int n;
    printf("Enter The Size Of Array: ");
    scanf("%d", &n);
    int arr[n][n];
    int product[n][n];
    printf("Enter Elements of Array: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            product[i][j] = arr[i][0] * arr[0][j] + // which one to write first decide for 2x2 or 3x3?
        }
    }

    return 0;
}