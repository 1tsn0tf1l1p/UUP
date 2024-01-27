#include <stdio.h>
#include <math.h>

double rek7(int x, int i, int gornji)
{
    if (gornji < 0)
        return 0;

    return sqrt(1.0 * gornji / x + rek7(x + i, i + 1, gornji - 11));
}

int main()
{

    int n;
    scanf("%d", &n);

    /// printf("%lf\n", rekurzivno(n, 1, 2 * n, 1));
    printf("%lf\n", rek7(n, 1, n * 11 - 1));

    return 0;
}