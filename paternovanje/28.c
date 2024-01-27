/*


\.\.\.\.
.\.\.\.\
././././
/./././.
\.\.\.\.
.\.\.\.\
././././
/./././.

*/

#include <stdio.h>

int main()
{

    int n = 10;

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 == 0 && (flag == 0 || flag == 1))
            {
                printf("\\");
            }
            else if ((i + j) % 2 != 0 && (flag == 2 || flag == 3))
            {
                printf("/");
            }
            else
            {
                printf(".");
            }
        }
        flag = (flag + 1) % 4;
        printf("\n");
    }

    return 0;
}