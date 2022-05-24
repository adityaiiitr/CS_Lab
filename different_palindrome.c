#include <stdio.h>
#include <string.h>
int check(char arr1[], char arr2[])
{
    if (strlen(arr1) != strlen(arr2))
        return 0;
    for (int i = 0, j = strlen(arr2) - 1; i < strlen(arr1); i++, j--)
    {
        if (arr1[j] != arr2[i])
            return 0;
    }
    return 1;
}
int main()
{
    char str[][10] = {"ram", "mar", "lol", "karan", "narak", "saran"};

    int n = 6, counter = 0;
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {
            counter += check(str[i], str[j]);
        }
    }
    if (counter % 2 == 0)
        printf("%d ", counter / 2);
    else
        printf("%d ", counter / 2 + 1);

    return 0;
}