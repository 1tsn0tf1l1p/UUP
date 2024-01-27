/*Napisati funkciju fun koja vraca da li broj ima paran broj neparnih cifara
argumenta. Napraviti zbir brojeva koji ispunjavaju uslov ( korisnik unosi brojeve
dok ne unese nula).
primer: 11 22 421 1357 0
rezultat: 1368 (DA, NE, NE, DA)*/

#include <stdio.h>

int fun(int arg){

    int cifra, brojac = 0;

    while(arg){
        cifra = arg%10;
        arg/=10;
        if(cifra%2!=0){
            brojac++;
        }
    }

    if(brojac%2==0 && brojac!=0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    int x, zbir = 0;
    do{
        scanf("%d", &x);
        if(fun(x)==1){
            zbir += x;
        }
    }
    while(x);

    printf("%d", zbir);

    return 0;
}