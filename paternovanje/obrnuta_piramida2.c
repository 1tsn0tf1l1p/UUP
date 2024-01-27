/*Napisati program koji za unet prirodni broj N iscrtava obrnutu piramidu visine N na standardni izlaz.

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

#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int brz = 2*n-1;

    int brr = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<brr; j++){
            printf(" ");
        }
        for(int k = 0; k<brz; k++){
            printf("*");
        }
        brr++;
        brz-=2;
        printf("\n");
    }

    return 0;
}