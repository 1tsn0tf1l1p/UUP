/*Napisati funkciju pom(int arg, int k) koja vrada broj dobijen kada se iz argumenta arg uklone sve
cifre manje od k (vratiti nula ako se izbace sve cifre). Sabrati brojeve koje vrada ova funkcija za 3
broja koja korisnik unese, i za k=5.*/

#include <stdio.h>

int pom(int arg, int k){
    int cifra, novi_broj = 0, stepen = 1;
    while(arg){
        cifra = arg%10;
        arg/=10;
        if(cifra>k){
            novi_broj = cifra*stepen + novi_broj;
            stepen*=10;
        }
    }

    return novi_broj;
}

int main(){

    int x, k = 5, zbir = 0, brojac = 1;

    while(brojac<=3){
        scanf("%d", &x);
        zbir+=pom(x, 5);
        brojac++;
    }

    printf("%d", zbir);
    

    return 0;
}