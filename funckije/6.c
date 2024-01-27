/*Napisati funkciju pom koja vraca koliko broj ima parnih cifara. Sabrati sve
neparne rezultate koje vraca funkcija za brojeve koje unosi korisnik ( korisnik
unosi brojeve dok ne unese nula).
primer: 12 22 426 0
rezultat: 4 (1+0+3)*/

#include <stdio.h>

int pom(int n){

    int cifra, rezultat = 0;

    while(n){
        cifra = n%10;
        n/=10;
        if(cifra%2==0){
            rezultat++;
        }
    }

    return rezultat;
}

int main(){

    int x, zbir = 0;

    do{
        scanf("%d", &x);
        if(pom(x)%2!=0){
            zbir+=pom(x);
        }
    }
    while(x);

    printf("%d", zbir);

    return 0;
}