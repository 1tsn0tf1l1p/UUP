/*Napisati funkciju int sumaSimetricnih(int n) koja proverava da li za zadati broj n važi
da mu je suma svim simetričnih cifara (prve i poslednje, druge i pretposlednje,...)
jednaka broju cifara.
Na primer, za sledeće brojeve važi traženi uslov: 1, 11, 132, 3221, 2132
Ispisati sve brojeve iz intervala koje unosi korisnik takve da važi da im je zbir simetričnih
cifara jednak broju cifara, na primer za interval 10 i 350 treba ispisati:
11, 20, 132, 231, 330*/

#include <stdio.h>

int broj_cifara(int n) {
    int brojac = 0;
    while (n) {
        brojac++;
        n /= 10;
    }

    return brojac;
}

int sumaSimetricnih(int n) {
    int cifra, dig = broj_cifara(n), brojac = 1, suma = 0;
    int n_copy = n;

    while (n) {
        cifra = n % 10;
        n /= 10;
        if (brojac <= dig / 2) {
            suma += cifra;
        } else {
            suma -= cifra;
        }
        brojac++;
    }

    return (suma == 0) ? 1 : 0;
}

int main() {
    int min, max;
    scanf("%d %d", &min, &max);

    for (int i = min; i <= max; i++) {
        if (sumaSimetricnih(i)) {
            printf("%d, ", i);
        }
    }

    return 0;
}
