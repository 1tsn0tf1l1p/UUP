/*Napisati program koji odredjuje K-ti prost broj.

Opis ulaza
Preko standardnog ulaza se unosi prirodan broj K (K <= 5000).

Opis izlaza
Ispisuje se prirodan prost broj koji je k-ti po redu u nizu prostih brojeva.

Primer 1
Ulaz
40
Izlaz
173
Primer 2
Ulaz
10
Izlaz
29*/

#include <stdio.h>

int prost(int n){

    for(int i = 2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }

    return 1;
}

int main(){

    int k;
    scanf("%d", &k);

    int prostbr = 0;

    for(int i = 0; i<k; i++){
        for(int j = 2; ; j++){
            if(prost(j)){
                prostbr = j;
            }
        }
    }

    printf("%d", prostbr);

    return 0;
}