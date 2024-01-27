/*Napisati program koji za zadatu dimenziju N, (N > 0) crta jednakokraki pravougli trougao pomoću znakova * i praznog prostora.

Opis ulaza
Prirodan broj koji će označavati dimenziju trougla.

Opis izlaza
Troguao veličine N koji je poravnat udesno.

Primer 1
Ulaz
5
Izlaz
    *
   **
  ***
 ****
*****
Primer 2
Ulaz
3
Izlaz
  *
 **
****/

#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i<j && (i+j)<(n-1)){
                printf("-");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
