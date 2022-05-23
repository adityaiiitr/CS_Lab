#include <stdio.h>
int main()
{
    int amount;
    printf("Enter Amount: ");
    scanf("%d", &amount);
    int notes[] = {2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int counter = 0;
    for (int i = 0; i < 11; i++)
    {
        if (amount / notes[i] != 0)
        {
            counter = counter + amount / notes[i];
            printf("Minimum Number Of Notes: %d\n", counter);
            amount = amount % notes[i];
            printf("amount: %d\n", amount);
        }
    }
    printf("Minimum Number Of Notes: %d", counter);

    return 0;
}