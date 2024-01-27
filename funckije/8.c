/*Napisati funkciju pom(int arg) koja vraca najvecu razliku između susednih cifara argumenta
(pretpostavimo da argument uvek ima bar dve cifre). Zatim ispisati sve brojeve iz intervala koji unosi
korisnik a kojima je najveda razlika između cifara manja od 3.*/

#include <stdio.h>
#include <math.h>

int pom(int arg){

    int c1, c2, razlika, max_razlika = 0;

    while(arg){
        c1 = arg%10;
        arg/=10;
        if(arg == 0){
            break;
        }
        c2 = arg%10;
        razlika = abs(c1-c2);
        if(razlika>max_razlika){
            max_razlika = razlika;
        }
    }

    return max_razlika;

}

int main(){

    int min, max, zbir = 0;
    scanf("%d %d", &min, &max);

    for(int i = min; i>=max; i++){
        if(pom(i)>=3){
            zbir += i;
        }
    }

    printf("%d", zbir);

    return 0;
}