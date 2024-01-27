/*Napisati funkciju int swap(int arg, int x, int y) koja vraća ceo broj koji se dobije
kada se celom broju arg zamene cifre na pozicijama x i y. Pozicije se gledaju od
poslednje cifre i počinju od 1. Ispisati sve brojeve iz intervala koje unosi korisnik takve da
su strogo veći od broja koji se dobije zamenom cifre jedinica i cifre stotina.
Napomena: funkcija swap(7683, 1, 2) vraća broj 7638, u broju 7683 cifra 3 je na poziciji
1, a cifra 8 je na poziciji 2
Primer: 4270 4320
Ispis: 4270 4271 4280 4281 4290 4291 4300 4301 4302 4310 4311 4312 4320*/

#include <stdio.h>
#include <math.h>

int swap(int arg, int x, int y){
    int c, c1, c2, r = 0, brojac = 1, p = 1;
    int temp = arg;
    while (temp != 0) {
        c = temp % 10;
        temp = temp / 10;
        if (brojac == x) c1 = c;
        if (brojac == y) c2 = c;
        brojac++;
    }
    int brojacc = 1;
    while (arg != 0) {
        c = arg % 10;
        arg = arg / 10;
        if (brojacc == x) c = c2;
        if (brojacc == y) c = c1;
        r = r + p * c;
        p = p * 10;
        brojacc++;
    }
    return r;
}

int main(){
    int min, max;
    scanf("%d %d", &min, &max);

    for(int i = min; i<=max; i++){
        if(i>swap(i, 1, 3)){
            printf("%d ", i);
        }
    }

    return 0;
}