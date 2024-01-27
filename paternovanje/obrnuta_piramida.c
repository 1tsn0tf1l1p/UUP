#include <stdio.h>

/*apisati program koji za unet prirodni broj N iscrtava obrnutu piramidu visine N na standardni izlaz.

Opis ulaza
Korisnik unosi prirodan broj na standardni ulaz.

Opis izlaza
Obrnuta piramida sastavljena od znakova * i razmaka.

Primer 1
Ulaz
5
Izlaz
*********
 *******
  *****
   ***
    *
Primer 2
Ulaz
3
Izlaz
*****
 ***
  **/

int main(){

    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<2*n-1; j++){
            if((i>j) || ((i+j-n+1)>(n-1))){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }

    printf("\n\n\n");

    int brr = 0, brz = 2*n-1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<brr; j++){
            printf(" ");
        }
        for(int j = 0; j<brz; j++){
            printf("*");
        }
        brr++;
        brz-=2;
        printf("\n");
    }

    return 0;
}