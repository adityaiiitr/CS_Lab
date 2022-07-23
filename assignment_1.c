// There is Roman Number Printing Limit (Verified Till 5000)

#include <stdio.h>
#include <string.h>
int main()
{
    int roll_number, sum = 0, n;
    char name[10];
    char str[10];
    printf("Enter the Roll Number: ");
    scanf("%d", &roll_number);
    printf("Enter the Name: ");
    scanf("%s", name);

    for (int i = 0; i < strlen(name); i++)
    {
        sum += name[i];
    }
    sum += roll_number;

    int arr[] = {1000, 500, 100, 50, 10, 5, 1};
    char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

    for (int i = 0, j = 0; i < 7; i++)
    {
        n = sum / arr[i];

        if (n != 0)
        {
            while (n--)
            {

                if (n == 3 && roman[i] != 'M')
                {
                    if (str[j - 1] == 'V' || str[j - 1] == 'L' || str[j - 1] == 'D')
                    {
                        j--;
                        str[j++] = roman[i];
                        str[j++] = roman[i - 2];
                    }
                    else
                    {
                        str[j++] = roman[i];
                        if (i != 0)
                            str[j++] = roman[i - 1];
                    }

                    break;
                }
                else
                {
                    str[j++] = roman[i];
                }
            }
            // printf("%d ", sum);
            sum = sum % arr[i];
        }
        str[j] = '\0';
    }
    printf("%s", str);
    return 0;
}
