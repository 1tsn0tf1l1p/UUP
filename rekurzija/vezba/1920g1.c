#include <stdio.h>
#include <math.h>

double iter(int n)
{

    int temp = n;

    int x;
    int y;
    int flag = 0;

    if (temp % 2 == 0)
    {
        x = n / 2 + 1;
        y = n / 2;
        flag = 1;
    }
    else
    {
        x = n / 2 + 1;
        y = n / 2 + 1;
    }

    double rez = sqrt(1.0 * x / y);

    int menjac;

    if (flag)
    {
        menjac = x;
        x = y;
        y = menjac;
    }
    else
    {
        x--;
        y++;
        menjac = x;
        x = y;
        y = menjac;
    }

    for (int i = 1; i < temp; i++)
    {

        if (flag && i == 1)
        {
            rez = sqrt(1.0 * x / y);
            x--;
            y++;
            menjac = x;
            x = y;
            y = menjac;
        }
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    printf("%lf\n", iter(n));

    return 0;
}