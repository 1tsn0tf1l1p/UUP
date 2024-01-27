/*Napisati funkciju double harmonic(int n) koja za prosledjeni broj racuna Harmonijski red 
(1 + 1/2 + 1/3 + 1/4 + 1/5 ... 1/n). Zatim napisati funkciju pom(int n, int k) koja ce harmonijskom redu
od n clanova uzeti prvih k cifara posle decimale i tako formirati broj, tom broju izbaciti sve proste cifre. 
Funkcija treba da vrati taj broj.  Korisnik unosi interval i treba da se ispisu svi brojevi za koje vazi da 
funkcija pom za k = 4, vraca trocifren broj.
Primer.   Za n = 9 i k = 4  ->  harmonijski red je 2.82896, prve 4 cifre posle decimale su 8289. 
Kada se izbace proste cifre iz tog broja, dobija se 889.
Input: 80 150
Output: 80 87 93 96 120 124 125 126 130 132 150*/

#include <stdio.h>

double harmonic(int n){

    double zbir = 0;

    for(int i = 1; i<=n; i++){
        zbir+=(1/(i*1.0));
    }

    return zbir;
}

int pom(int n, int k){

    double posle_decimale = harmonic(n)
}

int main(){

    printf("%lf", harmonic(9));
    
    return 0;
}