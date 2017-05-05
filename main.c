#include "cows_bulls.h"

int     count_cows(int for_cows[4], int for_guess[4])
{
    int i;
    int j;
    int cow;

    i = 0;
    cow = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (for_cows[i] == for_guess[j] && i != j)
                cow++;
            j++;
        }
        i++;
    }
    return(cow);
}

void    compare_nums(int num, int guess)
{
    int cow;
    int bull;
    int for_cows[4];
    int for_guess[4];
    int i;

    bull = 0;
    i = 3;
    while (i >= 0)
    {
        for_cows[i] = num % 10;
        num = num / 10;
        for_guess[i] = guess % 10;
        guess = guess / 10;
        if (for_cows[i] == for_guess[i])
            bull++;
        i--;
    }
    cow = count_cows(for_cows, for_guess);
    printf("%d bulls and %d cows\n", bull, cow);
}

int     num_check(int num)
{
    int for_check[4];
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    if (num < 1000 || num > 9999)
        return(1);
    while (num > 0)
    {
        for_check[i] = num % 10;
        num = num / 10;
        i++;
    }
    while (j < i)
    {
        k = (j == 0) ? 1 : 0;
        while (k < i)
        {
            if (for_check[j] == for_check[k] && k != j)
                return(1);
            k++;
        }
        j++;
    }
    return(0);
}

int     input_and_check(int flag)
{
    char buf[1000];
    int num;

    if (flag == 1)
    {
        scanf("%s", buf);
        if (strcmp(buf, "rand") == 0)
        {
            srand (time(NULL));
            num = rand() %9877 + 1233;
            while (num_check(num) == 1) {
                printf("WRONG INPUT!!! Please, enter number with 4 different digits\n");
                scanf("%s", buf);
                num = rand() %9877 + 1233;
            }
        }
        else
        {
            num = atoi(buf);
            while (num_check(num) == 1) {
                printf("WRONG INPUT!!! Please, enter number with 4 different digits\n");
                scanf("%s", buf);
                num = atoi(buf);
            }
        }
    }
    else
    {
        scanf("%s", buf);
        num = atoi(buf);
        while (num <= 0)
        {
            printf("WRONG INPUT!!! Please, enter 1 or more tries\n");
            scanf("%s", buf);
            num = atoi(buf);
        }
    }
    return (num);
}


int main()
{
    int num;
    int try;
    int guess;
    int i;
    char new_try;

    new_try = 'y';

    while (new_try == 'y')
    {
        i = 0;
        printf("Enter number with 4 different digits or enter \"rand\" for random number\n");
        num = input_and_check(1);
        printf("%s", CLEAR);
        printf("%s", RETUR);
        printf("Enter amount of tries\n");
        try = input_and_check(0);
        printf("Enter your guess:\n");
        while (i < try && new_try == 'y')
        {
            guess = input_and_check(1);
            if (num == guess)
            {
                printf("CONGRATULATIONS!!! YOU GUESS THE NUMBER!!!\nAmount of tries: %d\n", i);
                printf("One more game?(y|n)");
                scanf(" %c", &new_try);
                i = -1;
                break;
            }
            else
            {
                compare_nums(num, guess);
                printf("Tries left: %d\n", try - i - 1);
            }
            if (i < try -1)
                printf("Enter your guess:\n");
            i++;
        }
        if (i != -1)
        {
            printf("YOU LOOSE!!!\nNumber to guess was - %d\nOne more game?(y|n)", num);
            scanf(" %c", &new_try);
        }
    }
    return 0;
}