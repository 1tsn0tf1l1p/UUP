/*Napisati funkciju int armstrong(int n) koja proverava da li je zadati broj n
Armstrongov. Broj je armstrongov ako može da se dobije kao zbir svih svojih cifara
stepenovanih na broj cifara.
Na primer, broj 153 je Armstrongov jer .
Takođe, broj 1634 je Armstrongov jer
Napisati program koji pita korisnika da unese ceo broj n, i potom pomoću gore opisane
funkcije ispisuje prvih n Armstrongovih brojeva, počevši od 0. Na primer, za n=12, treba
ispisati:
0 1 2 3 4 5 6 7 8 9 153 370*/

#include <stdio.h>
#include <math.h>

int broj_cifara(int n){
    int brojac = 0;
    while(n){
        brojac++;
        n/=10;
    }

    return brojac;
}

int armstrong(int n){
    int cifra, stepen = broj_cifara(n), armbr = 0, temp = n;
    while(n){
        cifra = n%10;
        n/=10;
        armbr+=pow(cifra, stepen);
    }

    if(armbr == temp){
        return 1;
    }

    return 0;

}

int main(){

    int n;
    scanf("%d", &n);

    for(long long i = 0, brojac = 0; brojac<n; i++){
        if(armstrong(i)){
            printf("%lld\n", i);
            brojac++;
        }
    }

    return 0;
}