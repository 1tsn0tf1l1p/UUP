/*Napisati program koji za unet prirodni broj 
N
 crta sledeću figuru (u primeru N=4):

1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
Opis ulaza
Korisnik unosi prirodan broj na standardni ulaz.

Opis izlaza
Kvadrat sadrži cifre 1...N redom po sporednim dijagonalama.

Primer 1
Ulaz
3
Izlaz
1 2 3
2 3 1
3 1 2
Primer 2
Ulaz
5
Izlaz
1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = (i + j) % n + 1;
            printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}