/*Napisati program kojim se određuju i ispisuju svi savršeni brojevi od 2 do N. Broj je savršen ako je jednak sumi svojih delitelja isključujući njega samog. 28 je savršen broj, jer je: 28 = 1 + 2 + 4 + 7 + 14

Opis ulaza
Korisnik unosi prirodan broj N, kao granica do koje se ispisuju savršeni brojevi.

Opis izlaza
Redom ispisani savršeni brojevi, razmaknuti jednim razmakom.

Primer 1
Ulaz
100
Izlaz
6 28
Primer 2
Ulaz
1500
Izlaz
6 28 496*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        int suma = 0;

        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                suma += j;
            }
        }

        if (suma == i) {
            printf("%d ", i);
        }
    }

    return 0;
}
