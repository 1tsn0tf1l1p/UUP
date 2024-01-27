/*Napisati funkciju int pom(int arg, int delilac) koja vrada broj koji se dobije kada se iz argumena
arg izbace sve cifre koji nisu deljive argumentom delilac (delilac је u opsegu *2,9+). Zatim korišdenjem
funkcije pom ispisati sve brojeve iz intervala koji unosi korisnik kojima su cve cifre deljive sa 3.*/

#include <stdio.h>

int pom(int arg, int delilac){

    int cifra, novi_broj = 0, stepen = 1;
    while(arg){
        cifra = arg%10;
        arg/=10;
        if(cifra%delilac==0){
            novi_broj = cifra*stepen+novi_broj;
            stepen*=10;
        }
    }

    return novi_broj;
}

int main(){

    int min, max, k;
    scanf("%d %d %d", &min, &max, &k);

    if(k<2 && k>9){
        printf("Pogresan unos!");
    }

    int cifra, flag;

    for(int i = min; i<=max; i++){
        flag = 1;
        while(i){
            cifra = i%10;
            i/=10;
            if(cifra%3==0){
                continue; 
            }
            else{
                flag = 0;
                break;
            }
            }

        if(flag == 1){
            printf("%d ", pom(i, k));
        }

        }

    return 0;
}