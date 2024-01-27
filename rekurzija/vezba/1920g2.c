#include <stdio.h>

int faktorijel(int n)
{

    int fak = 1;

    for (int i = 2; i <= n; i++)
    {
        fak = i * fak;
    }

    return fak;
}

double iter(int n)
{
    int temp = n;

    
}

int main()
{

    int n;
    scanf("%d", &n);

    /// printf("%lf\n", iter(n));

    printf("%d", faktorijel(n));

    return 0;
}