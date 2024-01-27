#include <stdio.h>
#include <math.h>

double rek(int n, int temp, int donji, int granica, int brojac)
{
    if (brojac > temp)
    {
        return 0;
    }

    if (brojac < granica)
    {
        return sqrt(1.0 * n / pow(donji, 2) + rek(n - 1, temp, donji + 1, granica, brojac + 1));
    }
    else if (brojac > granica)
    {
        return sqrt(1.0 * n / pow(donji, 2) + rek(n + 1, temp, donji + 1, granica, brojac + 1));
    }
    else if (brojac == granica)
    {
        if (temp % 2 != 0)
        {
            return sqrt(1.0 * n / pow(donji, 2) + rek(n + 1, temp, donji + 1, granica, brojac + 1));
        }
        else
        {
            return sqrt(1.0 * (n + 1) / pow(donji, 2) + rek(n + 2, temp, donji + 1, granica, brojac + 1));
        }
    }
}

double iter(int n)
{
    int granica;

    if (n % 2 != 0)
    {
        granica = n / 2;
    }
    else
    {
        granica = n / 2 - 1;
    }

    int temp = n;
    int duzina_iter = n;
    int gornji = n;
    double rez = sqrt(1.0 * n / pow(n, 2));

    gornji--;
    n--;

    for (int i = 1; i < duzina_iter; i++)
    {
        if (i < granica)
        {
            rez = sqrt(1.0 * gornji / pow(n, 2) + rez);
            gornji--;
            n--;
        }
        else if (i > granica)
        {
            rez = sqrt(1.0 * gornji / pow(n, 2) + rez);
            gornji++;
            n--;
        }
        else if (i == granica)
        {
            if (temp % 2 != 0)
            {
                rez = sqrt(1.0 * gornji / pow(n, 2) + rez);
                gornji++;
                n--;
            }
            else
            {
                rez = sqrt(1.0 * gornji / pow(n, 2) + rez);
                n--;
            }
        }
    }

    return rez;
}

int main()
{

    int n;
    scanf("%d", &n);

    printf("%lf\n", rek(n, n, 1, n / 2 + 1, 1));
    printf("%lf\n", iter(n));

    return 0;
}