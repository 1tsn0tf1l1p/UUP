/*
Za zadatu matricu velicine n*n i vrednost k, obrnuti svaki prsten matrice u
smeru kazaljke na satu za k puta.
Ulaz:                                    Ulaz:
6 8 Izlaz:                            4 2 Izlaz:

3 2 6 4 5 8    4 2 3 4 9 0    8 1 7 5   7 8 8 1
7 4 3 2 7 1    3 2 9 4 9 0    8 7 4 6   0 4 4 7
0 5 6 9 2 3    2 7 6 9 2 7    7 4 4 9   1 4 7 5
0 7 9 4 9 4    9 2 9 4 2 3    0 1 3 7   3 7 9 6
9 2 2 9 4 9    4 3 4 5 7 2
4 3 2 4 3 2    3 1 8 5 4 6

3 2 6 4 5 8
7 4 3 2 7 1
0 5 6 9 2 3
0 7 9 4 9 4
9 2 2 9 4 9
4 3 2 4 3 2

*/

#define SIZE 100

#include <stdio.h>

void micko_zarotiraj(int *niz, int n, int k)
{
    while (k != 0)
    {

        for (int i = n - 1; i > 0; i--)
        {
            int temp = niz[i];
            niz[i] = niz[i - 1];
            niz[i - 1] = temp;
        }

        k--;
    }
}

void prsten_matrice(int mat[SIZE][SIZE], int n, int k)
{

    int niz[SIZE];

    int offset = 0;
    int trenutni = 0;

    while (offset <= n / 2)
    {
        for (int j = offset; j < n - offset; j++)
        {
            niz[trenutni++] = mat[offset][j];
        }
        for (int i = offset + 1; i < n - offset; i++)
        {
            niz[trenutni++] = mat[i][n - offset - 1];
        }
        for (int j = n - offset - 2; j >= offset; j--)
        {
            niz[trenutni++] = mat[n - offset - 1][j];
        }
        for (int i = n - offset - 2; i >= offset + 1; i--)
        {
            niz[trenutni++] = mat[i][offset];
        }

        micko_zarotiraj(niz, trenutni, k);

        trenutni = 0;

        for (int j = offset; j < n - offset; j++)
            mat[offset][j] = niz[trenutni++];

        for (int i = offset + 1; i < n - offset; i++)
            mat[i][n - offset - 1] = niz[trenutni++];

        for (int j = n - offset - 2; j >= offset; j--)
            mat[n - offset - 1][j] = niz[trenutni++];

        for (int i = n - offset - 2; i >= offset + 1; i--)
            mat[i][offset] = niz[trenutni++];

        trenutni = 0;
        offset++;
    }
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);

    int mat[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    prsten_matrice(mat, n, k);

    printf("\n\n");

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