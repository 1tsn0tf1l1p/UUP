/*Napisati funkciju test koja izračunava broj koji se dobija od svih neparnih cifara
argumenta. Napraviti zbir brojeva koji se dobijaju primenom funkcije na brojeve
koje unosi korisnik ( korisnik unosi brojeve dok ne unese nula).*/

#include <stdio.h>

int test(int n){
    int cf, stepen = 1, novi_broj = 0;
    while(n){
        cf = n%10;
        n/=10;
        if(cf%2 != 0){
            novi_broj = novi_broj + cf*stepen;
            stepen*=10;
        }
    }
    return novi_broj;
}


int main(){

    int x, zbir = 0;
    do{
    scanf("%d", &x);

    zbir = zbir + test(x);
    }
    while(x);

    printf("%d", zbir);

    return 0;
}