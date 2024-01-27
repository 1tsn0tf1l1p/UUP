#include <stdio.h>
#include <math.h>

int main()
{

    int n, x;
    scanf("%d %d", &n, &x);

    int k = 2 * x;

    for (int ii = 0; ii < k; ii++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int jj = 0; jj < k; jj++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (abs(i - j) == n / 2)
                    {
                        printf("\\");
                    }
                    else if (i + j == n / 2 + n - 1 || i + j == n / 2 - 1)
                    {
                        printf("/");
                    }
                    else if (abs(i - j) < n / 2 && i + j < n / 2 + n - 1 && i + j > n / 2 - 1)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("~");
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}
