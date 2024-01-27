/*Napisati funkciju int pom(int arg) koja vrada broj koji se dobije kada se iz argumenta izbaci
njegova najveda cifra (ako ima više jednakih najvedih cifara izbaciju se sve). Zatim napisati program u
kome korisnik unosi brojeve, a ispisuje se razlika unetog broja i broja koji se dobije kada se iz unetog
broja izbaci najveda cifra. Program se završava kada korisnik unese 0.*/

#include <stdio.h>

int maxCifra(int n) {
    int cifra, max = 0;
    while (n) {
        cifra = n % 10;
        n = n / 10;
        if (cifra > max) max = cifra;
    }
    return max;
}

int pom(int arg) {
    int cifra, rezultat = 0, p = 1, max = maxCifra(arg);
    while (arg) {
        cifra = arg % 10;
        arg = arg / 10;
        if (cifra == max) continue;
        rezultat = rezultat + p * cifra;
        p *= 10;
    }
    return rezultat;
}

int main()
{
    int x;
    do {
        scanf("%d", &x);
        printf("%d\n", x - pom(x));
    } while (x);
    return 0;
}