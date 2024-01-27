/*
4 6
1 2 3 4 1 3
3 1 4 1 5 9
2 4 1 7 6 8
5 5 3 1 9 2
*/

#define SIZE 69

#include <stdio.h>

void podmatrice(int mat[SIZE][SIZE], int n, int m)
{

    for (int x = 3; x <= n; x++)
    {
        for (int y = 3; y <= m; y++)
        {
            if (x != y)
            {
                continue;
            }

            for (int i = 0; i < n - x + 1; i++)
            {
                for (int j = 0; j < m - y + 1; j++)
                {
                    int brojac = 0;

                    int gl = mat[i][j];
                    int gd = mat[i][j + y - 1];
                    int dl = mat[i + x - 1][j];
                    int dd = mat[i + x - 1][j + y - 1];

                    for (int p = i; p < i + x; p++)
                    {
                        for (int q = j; q < j + y; q++)
                        {
                            if (mat[p][q] == gl || mat[p][q] == gd || mat[p][q] == dl || mat[p][q] == dd)
                            {
                                brojac++;
                            }
                            ///  printf("%d ", mat[p][q]);
                        }
                        /// printf("\n");
                    }
                    /// printf("\n");

                    if (brojac == 4)
                    {
                        printf("(%d, %d) dimenzija %d x %d\n", i, j, x, y);
                    }
                }
            }
        }
    }
}

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    int mat[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n");

    podmatrice(mat, n, m);

    return 0;
}