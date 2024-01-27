/*Napisati funkciju int pom(int n) koja provera da li je prosleđeni argument Fibonačijev broj,
ako jeste vraća njegovu poziciju u Fibonačijevom nizu (za broj 1 vraća 2, za 2 vraća 3, za 3 vraća
4, itd...) u slučaju da broj nije Fibonačijev funkcija vraca -1. Proveriti za svaki broj iz intervala
[n,m] da li je njegov zbir cifara Fibonačijev broj i ako jeste ispisati njegovu poziciju u
Fibonačijevom nizu.
Primer: 10 50
Ispis: 2 3 4 5 6 3 4 5 6 4 5 6 5 6 7 5*/

#include <stdio.h>

/// 1, 1, 2, 3, 5, 8, 13, 21

int zbir_cifara(int n){

     int zbir = 0;
    
    while (n > 0) {
        zbir += n % 10;
        n /= 10;
    }
    
    return zbir;
}

int pom(int n){

    int pozicija = 2, prvi = 1, drugi = 1, fib, broj = zbir_cifara(n);
    
    for(int i = 1; i<broj; i++){
        fib = prvi + drugi;
        prvi = drugi;
        drugi = fib;
        pozicija++;
        if(broj == 1){
            return 2;
        }
        if(fib == broj){
            return pozicija;
        }
    }

    return -1;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d", zbir_cifara(n));

    for(int i = n; i<=m; i++){
        if(pom(i)!=-1){
            printf("%d ", pom(i));
        }
    }

    return 0;
}