/*------------A. Yogurt Sale-----------------*/

#include <stdio.h>

int main()
{
    long long int t;
    int n, a, b, price;
    scanf("%lld", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &n, &a, &b);

        if (a * 2 > b)
        {
            price = b * (n / 2) + a * (n % 2);
        }
        else if (a * 2 < b)
        {
            price = n * a;
        }
        else
        {
            price = (n / 2) * b + (n % 2) * a;
        }

        printf("%d\n", price);
        price = 0;
    }

    return 0;
}

/*--------------A. Spy Detected!----------------*/

#include <stdio.h>

int main()
{

    int t, n, val, index;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }

        index = 0;
        for (int j = 1; j < n; j++)
        {
            if (a[j] != a[j - 1] && a[j] != a[j + 1])
            {
                index = j;
                break;
            }
        }

        printf("%d\n", index + 1);
    }

    return 0;
}

//-------------------A.Minimize------------------------------

#include <stdio.h>
#include <stdlib.h> // For abs() function

int main()
{
    int t; // Number of test cases
    scanf("%d", &t);

    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        // The minimum value of |x - a| + |x - b| is |a - b|
        printf("%d\n", abs(a - b));
    }

    return 0;
}

//---------------------------A. Alice's Adventures in "Chess"--------------------------

#include <stdio.h>
#include <stdbool.h>

bool willMeet(int n, int a, int b, const char *s)
{
    int x = 0, y = 0;
    int dx = 0, dy = 0;
    bool visited[21][21] = {false};

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
            y++;
        else if (s[i] == 'E')
            x++;
        else if (s[i] == 'S')
            y--;
        else if (s[i] == 'W')
            x--;

        if (x == a && y == b)
        {
            return true;
        }

        visited[x + 10][y + 10] = true;
    }

    dx = x;
    dy = y;

    if (dx == 0 && dy == 0)
    {
        return visited[a + 10][b + 10];
    }

    int current_x = 0, current_y = 0;
    for (int cycle = 0; cycle < 40; ++cycle)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N')
                current_y++;
            else if (s[i] == 'E')
                current_x++;
            else if (s[i] == 'S')
                current_y--;
            else if (s[i] == 'W')
                current_x--;

            if (current_x == a && current_y == b)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, a, b;
        char s[11];
        scanf("%d %d %d", &n, &a, &b);
        scanf("%s", s);

        if (willMeet(n, a, b, s))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
