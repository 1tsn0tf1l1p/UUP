#include <stdio.h>

/*Uneti od n od m, i da ispisuje proste brojeve*/

int prost(int n){
    for(int i = 2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }

    return 1;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = n; i<=m; i++){
        if(!prost(i) || i == 1 || i == 2){
            continue;
        }
        printf("%d ", i);
    }

    return 0;
}