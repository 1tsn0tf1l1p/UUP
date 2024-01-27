#include <stdio.h>

void draw_pattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                printf("^");
            }
            else if ((i < j && i + j < n - 1) || (i > j && i + j > n - 1)) {
                printf(" ");
            }
            else if ((i % 2 == 0 && j == 0 && i != 0 && i != n) || (i % 2 == 0 && j == n - 1 && i != 0 && i != n)) {
                printf("*");
            }
            else if ((i % 2 != 0 && j == 0 && i != 0 && i != n) || (i % 2 != 0 && j == n - 1 && i != 0 && i != n)) {
                printf("-");
            }
            else if (j < n / 2 - 1) {
                printf("(");
            }
            else if (j > n / 2 - 1) {
                printf(")");
            }
        }
        printf("\n");
    }
}

int main() {
    int n = 7;
    draw_pattern(n);
    return 0;
}