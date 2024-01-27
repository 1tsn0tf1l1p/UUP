#include <stdio.h>

void myswap(int *a, int *b)
{
    int rez = *a;
    *a = *b;
    *b = rez;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Sorting the entire 2D array
    for (int col = 0; col < m; col++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j][col] > a[j + 1][col])
                {
                    myswap(&a[j][col], &a[j + 1][col]);
                }
            }
        }
    }

    // Printing the sorted array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}