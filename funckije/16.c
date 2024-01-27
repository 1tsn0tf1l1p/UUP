/*Napisati funkciju int pom(int arg) koja vrada broj koji se dobije kada se iz argumenta arg
izbace sve proste cifre. Za određivanje da li je cifra prosta napisati dodatnu funkciju int prost(int
n) koja vrada 1 ukoliko je broj n prost, ili 0 ukoliko je n složen broj. Zatim korišdenjem funkcije pom
ispisati sve brojeve iz intervala koji unosi korisnik koji imaju sve proste cifre. Napomena: 0 i 1 se ne
ubrajaju u proste brojeve!*/

#include <stdio.h>

int prost(int n){
    for(int i = 2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int pom(int arg){
    int cifra, novi_broj = 0, stepen =1;
    while(arg){
        cifra = arg%10;
        arg/=10;
        if(prost(cifra)){
            continue;
        }
        novi_broj = cifra*stepen +novi_broj;
        stepen*=10;
    }

    return novi_broj;
}


int main(){

    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (pom(i) == 0) printf("%d ", i);
    }

    return 0;
}