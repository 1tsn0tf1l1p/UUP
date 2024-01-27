#include <stdio.h>

/*Napisati funkciju int pom(int n) koja vrada proizvod pravih prostih delilaca broja, i dodatnu
funkcijuint prost(int n) koja vrada 1 ukoliko je broj nprost broj, ili 0 ukoliko nije.Korišdenjem
napisanih funkcija ispisati sve brojeve koji su jednaki proizvodu svojih pravih prostih delilacaiz intervala
koji unosi korisnik.*/

int prost(int n){

    for(int i = 2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    
    return 1;
}

int pom(int n){

    int proizvod = 1;

    for(int i = 1; i<n; i++){
        if(prost(i)){
            if(n%i==0){
                proizvod*=i;
            }
        }
    }

    return proizvod;

}

int main(){
    
    int min, max;
    scanf("%d %d", &min, &max);

    for(int i = min; i<=max; i++){
        if(i == pom(i)){
            printf("%d ", i);
        }
    }

    return 0;

}