#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
(7p) Nacrtati sledeću figuru za unetu vrednost n.
n = 4
+---+
|\...\
|.\../\
|..\/..+ 
|../\..|
|./..\.|
|/....\|
+------+
*/

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < 2 * n; i++) {
        for(int j = 0; j < 2 * n; j++) {
            if(i < j - n) {
                printf(" ");
            }
            else if((i == 0 && j == 0) || (i == 2 * n - 1 && j == 0) || (i == 2 * n - 1 && j == 2 * n - 1) ||
             (i == 0 && j == n) || (i == n - 1 && j == 2 * n - 1)) {
                printf("+");
            }
            else if((i == j) || (i == j - n)) {
                printf("\\");
            }
            else if((j == 0) || (j == 2 * n - 1)) {
                printf("|");
            }
            else if((i == 0) || (i == 2 * n - 1)) {
                printf("-");
            }
            else if(i + j == 2 * n - 1) {
                printf("/");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}