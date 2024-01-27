/*Napisati funkciju izbaciVeceCifre(int a, int k) koja vraća broj koji se dobija kada se iz broja a izbace sve cifre koje su vece od k.

Napomene
Potrebno je implementirati isključivo funkciju izbaciVeceCifre(int a, int k) i ova funkcija vraća int.
Primer 1
Ulaz
a=12345 k=2

Izlaz
funkcija vraća 12*/

#include <stdio.h>

int izbaciVeceCifre(int a, int k){

    int novi_broj = 0;
    int stepen = 1;

    while(a){
        int cifra = a%10;
        a/=10;
        if(cifra<=k){
            novi_broj = cifra*stepen + novi_broj;
            stepen*=10;
        }

    }

    return novi_broj;
}

int main(){

    int x, k;
    scanf("%d %d", &x, &k);

    printf("%d", izbaciVeceCifre(x, k));

    return 0;
}