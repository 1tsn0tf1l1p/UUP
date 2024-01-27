#include <stdio.h>

/*Implementirati program koji za dva uneta broja, N i M, ispisuje tablicu množenja.

Opis ulaza
Prvi red standardnog ulaza sadrži dva prirodna broja, 
N
 i 
M
, razdvojena razmakom, koja predstavljaju dimenzije tablice množenja.

Opis izlaza
Tablica množenja će na x-osi imati brojeve od 1 do N, a na y-osi imati brojeve od 1 do M, kao i njihove proizvode na odgovarajućim mestima u tabeli. Svaki broj treba da zauzme širinu od 4 mesta u tabeli, i da je uvučen uz desnu ivicu. Posle svake linije je potreban znak za novi red ('\n').

Primer 1
Ulaz
4 5
Izlaz
   1   2   3   4
   2   4   6   8
   3   6   9  12
   4   8  12  16
   5  10  15  20
Primer 2
Ulaz
6 6
Izlaz
   1   2   3   4   5   6
   2   4   6   8  10  12
   3   6   9  12  15  18
   4   8  12  16  20  24
   5  10  15  20  25  30
   6  12  18  24  30  36*/

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            printf("%4d", i*j);
        }
        printf("\n");
    }

    return 0;
}