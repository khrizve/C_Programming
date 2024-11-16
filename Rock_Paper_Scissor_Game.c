#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerenateRandomNum(int n)
{
    srand(time(NULL));
    return rand() % n;
}

char compare(char char_p, char char_c)
{
    if (char_p == char_c)
    {
        return -1;
    }

    else if (char_p == 'r' && char_c == 's')
    {
        return 1;
    }
    else if (char_p == 's' && char_c == 'r')
    {
        return 0;
    }
    if (char_p == 's' && char_c == 'p')
    {
        return 1;
    }
    else if (char_p == 'p' && char_c == 's')
    {
        return 0;
    }

    if (char_p == 'p' && char_c == 'r')
    {
        return 1;
    }
    else if (char_p == 'r' && char_c == 'p')
    {
        return 0;
    }
}

int main()
{

    int temp, playerScore = 0, comScore = 0;
    char dictonary[] = {'r', 'p', 's'};
    char p_char, c_char;
    printf("\n*****Welcome To the 'Rock-Paper-Scissor' Game*****\n");

    for (int i = 0; i < 3; i++)
    {
        printf("\n***Player's Turn***\n");
        printf("Enter --> 1 for 'rock' 2 for 'paper' 3 for 'scissor': ");
        scanf("%d", &temp);
        getchar();
        p_char = dictonary[temp - 1];
        printf("Player Choose: %c\n", p_char);

        printf("\n***Computer's Turn***\n");
        temp = gerenateRandomNum(3) + 1;
        c_char = dictonary[temp - 1];
        printf("Compter Choose: %c\n", c_char);

        if (compare(p_char, c_char) == 1)
        {
            playerScore += 1;
            printf("\n*Player Got it*\n");
        }
        else if (compare(p_char, c_char) == -1)
        {
            playerScore += 1;
            comScore += 1;
            printf("\n*Draw*\n");
        }
        else
        {
            comScore += 1;
            printf("\n*Computer Got it*\n");
        }

        printf("\nPlayer: %d Computer: %d\n", playerScore, comScore);
    }

    if (playerScore > comScore)
    {
        printf("***Player won the Game***\n");
    }
    else if (playerScore == comScore)
    {
        printf("***It's a Draw***\n");
    }
    else
    {
        printf("***Computer won the Game***\n");
    }

    return 0;
}
