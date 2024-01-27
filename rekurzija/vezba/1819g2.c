#include <stdio.h>
#include <math.h>

int fib(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

double rekurzivno(int n, int i, int gornji)
{
    if (i == n)
    {
        return fib(i);
    }

    if (i % 2 != 0)
    {
        /// printf("fib = %d, i = %d, gornji = %d\n", fib(i), i, gornji);
        return fib(i) + 1.0 * gornji / rekurzivno(n, i + 1, gornji - 3);
    }
    else
    {
        /// printf("fib = %d, i = %d, gornji = %d\n", fib(i), i, gornji);
        return fib(i) - 1.0 * gornji / rekurzivno(n, i + 1, gornji - 3);
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    printf("%lf\n", rekurzivno(n, 1, 3 * n));

    return 0;
}