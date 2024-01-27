/*

*
*1*
*121*
*12321*
*1234321*
*12321*
*121*
*1*
*

*/

#include <stdio.h>

int main(){

    int n = 10;

    int granica = 0;

    int brojac = -1;

    for(int i = 0; i<2*n+1; i++){
        for(int j = 0; j<2*n+1; j++){
            if(j == granica){
              printf("*");  
            }
            else if(j == 0){
                printf("*");
            }
            else if(i > j - 1 && i <= n){
                printf("%d", j);
                brojac++;
            }
            else if(i < j && i <=n && j < granica){
                printf("%d", brojac);
                brojac--;
            }
            else if(((i+j)>(2*n-1)) && i > n && j < granica){
                printf("%d", brojac+2);
                brojac--;
            }
            else if(((i+j)<=(2*n-1)) && i >n && j < granica){
                printf("%d", j);
                brojac++;
            }
            else{
                printf(" ");
            }
            
        }
        if(i<n){
            granica+=2;
            }
        else{
            granica-=2;
            }

        brojac = -1;

        printf("\n");
    }

    return 0;
}