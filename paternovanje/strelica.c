/*
    .....^.....
.../*\... ..../*\....
../***\.. .../***\...
./*****\. ../*****\..
---***--- ./*******\.
..|***|.. ----***----
..|***|.. ...|***|...
..|***|.. ...|***|...
..-----.. ...|***|...
...|***|...
...-----...


*/

#include <stdio.h>
#include <math.h>

int main()
{

    int n = 8;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (j == n - 1 && i == 0)
            {
                printf("^");
            }
            else if (i < n - 1 && (i + j) == n / 2 + 2)
            {
                printf("/");
            }
            else if (i < n - 1 && abs(i - j) == n / 2 + 2)
            {
                printf("\\");
            }
            else if (i < n - 1 && (((i + j) > n / 2 + 2) && abs(i - j) < n / 2 + 2))
            {
                printf("*");
            }
            else if (i == n - 1 && (j < (n - 2) || j > n))
            {
                printf("-");
            }
            else if (i == 2 * n - 2 && j >= n / 2 && j <= n + 1)
            {
                printf("-");
            }
            else if ((j == n / 2 || j == n + 1) && i > n - 1)
            {
                printf("|");
            }
            else if ((j > n / 2 && j < n + 1) && i > n - 1)
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}