/*Napisati funkciju pom(int arg) koja vrada najmanju razliku između susednih cifara argumenta
(pretpostavimo da argument uvek ima bar dve cifre). Zatim ispisati sve brojeve iz intervala koji unosi
korisnik a kojima je najmanja razlika između cifara veda od 5.*/

#include <stdio.h>
#include <limits.h>
#include <math.h>

int pom(int arg) {
    int c1, c2, r, razlika = 0;
    while (arg) {
        c1 = arg % 10;
        arg /= 10;
        if (arg == 0) break;
        c2 = arg % 10;
        r = abs(c1 - c2);
        if (razlika < r) razlika = r;
    }
    return razlika;
}

int main(){

    int min, max;
    scanf("%d %d", &min, &max);
    for(int i = min; i<=max; i++){
        if(pom(i)>=5){
            printf("%d ", i);
        }
    }
    
    return 0;
}
