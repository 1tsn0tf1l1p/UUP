#define SIZE 50

#include <stdio.h>

/*
3 6 7 5 3
5 6 2 9 1
2 7 0 9 3
6 0 6 2 6
1 8 7 9 2
*/

void swap_items(int *e1, int *e2)
{
    int res = *e1;
    *e1 = *e2;
    *e2 = res;
}

void sort_matrix(int mat[SIZE][SIZE], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int p = 0; p < n - i - 1; p++)
            {
                if (mat[p][j] > mat[p + 1][j])
                {
                    swap_items(&mat[p][j], &mat[p + 1][j]);
                }
            }
        }
    }

    // Print the sorted matrix
    printf("\nSorted Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int mat[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}