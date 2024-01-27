/*Napisati funkciju int pom(int arg) koja vrada broj koji se dobije kada se iz argumenta izbaci
njegova najmanja cifra (ako ima više jednakih najmanjih cifara izbaciju se sve). Zatim napisati
program u kome korisnik unosi brojeve, a ispisuje se zbir unetog broja i broja koji se dobije kada se iz
unetog broja izbaci najmanja cifra. Program se završava kada korisnik unese 0.*/

#include <stdio.h>
#include <limits.h>

int najmanja_cifra(int n){
    int cifra, najmanja = __INT_MAX__;
    while(n){
        cifra = n%10;
        n/=10;
        if(cifra<najmanja){
            najmanja = cifra;
        }
    }
    
    return najmanja;
}

int pom(int arg){
    int cifra,najmanja = najmanja_cifra(arg), novi_broj = 0, stepen = 1;
    while(arg){
        cifra = arg%10;
        arg/=10;
        if(cifra != najmanja){
            novi_broj = cifra*stepen+novi_broj;
            stepen*=10;
        }
    }

    return novi_broj;
}

int main(){

    int x;

    do{
        scanf("%d", &x);
        printf("%d\n", x + pom(x));
    }while(x);
    
    return 0;
}