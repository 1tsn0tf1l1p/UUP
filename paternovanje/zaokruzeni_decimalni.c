/*Napisati funkciju koja za zadati realni broj N vraća zaokruzeni broj na X (X <= 6) decimala. Zatim napisati program koji testira tu funkciju.

Opis ulaza
Preko standardnog ulaza se unosi realni broj koji treba da se zaokruži, i broj decimala na koliko se zaokružuje.

Opis izlaza
Na standardni izlaz se ispisuje realni broj, zaokružen na željeni broj decimala.

Primer 1
Ulaz
5.2381 2
Izlaz
5.23
Primer 2
Ulaz
3.14159 3
Izlaz
3.141*/

#include <stdio.h>
#include <math.h>

// Funkcija za zaokruživanje broja na određeni broj decimala
double zaokruzi(double broj, int decimala) {
    double faktor = pow(10, decimala);
    return round(broj * faktor) / faktor;
}

int main() {
    double n;
    int decimala;

    // Unos broja i broja decimala
    scanf("%lf %d", &n, &decimala);

    // Poziv funkcije za zaokruživanje i ispis rezultata
    printf("%.lf\n", zaokruzi(n, decimala));

    return 0;
}