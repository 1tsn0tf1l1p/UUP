/*
    n = 4


    *
    *1*
    *121*
    *12321*
    *1234321*
    *12321*
    *121*
    *1*
    *



*/

#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int granica = 0;

    for (int i = 0; i < 2 * n + 1; i++, printf("\n"))
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {

            if (j == 0 || j == granica)
                putchar('*');
            else if ((j <= i && j < granica && i <= n) || (j <= 2 * n - i && j < granica && i > n))
                printf("%d", j);
            else if (j < granica)
                printf("%d", granica - j);
        }
        if (i < n)
            granica += 2;
        else
            granica -= 2;
    }

    return 0;
}