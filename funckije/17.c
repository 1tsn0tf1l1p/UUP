/*Napisati funkciju int pom(int n) koja vrada kvadrat proizvoda prve i poslednje cifre broja, i
dodatnu funkciju int obilan(int n) koja vrada 1 ukoliko je broj n obilan broj, ili 0 ukoliko nije. Broj
n je obilan ako mu je zbir svih pravih delilaca strogo vedi od n. Korišdenjem napisanih funkcija ispisati sve
obilne brojeve iz intervala koji unosi korisnik koji su manji od kvadrata proizvoda svoje prve i poslednje
cifre.*/

#include <stdio.h>
#include <math.h>

int reverse(int n){
    int digit, novi_broj = 0;
    while(n){
        digit = n%10;
        n/=10;
        novi_broj = novi_broj*10+digit;
    }
    return novi_broj;
}

int first_digit(int n){
    int prva_cifra, obrnut = reverse(n);
    prva_cifra = obrnut%10;
    
    return prva_cifra;
}


int pom(int n){
    int proizvod, poslednja, prva = first_digit(n);
    poslednja = n%10;
    proizvod = pow((poslednja*prva), 2);

    return proizvod;
}

int obilan(int n){
    int zbir = 0;
    for(int i = 1; i<=n; i++){
        if(n%i==0){
            zbir+=i; 
        }
    }
    
    if(zbir>n){
        return 1;
    }
    return 0;
}

int main(){

    int min, max;
    scanf("%d %d", &min, &max);

    for(int i = min; i<=max; i++){
        if(obilan(i)==1 && (i<pom(i))){
            printf("%d ", i);
        }
    }

    return 0;
}