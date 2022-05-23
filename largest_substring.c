#include <stdio.h>
#include <string.h>

int counter(char arr[100], char ch)
{
    for (int i = 0; i < strlen(arr) - 1; i++)
    {
        if (arr[i] == ch)
            return 1;
    }
    return 0;
}
int main()
{
    char str[500], nstr[100];
    char substr[100];
    int max_length = 0;
    printf("Enter a String: ");
    scanf("%[^\n]s", &str);
    scanf("%c");
    nstr[0] = str[0];
    for (int i = 0, j = 1; i < strlen(str); i++)
    {
        int check = counter(nstr, str[i]);
        if (check == 1)
        {
            j = 0;
        }
        nstr[j++] = str[i];
        nstr
    }

    return 0;
}