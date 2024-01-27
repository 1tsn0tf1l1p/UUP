/*Napisati program koji za uneto n=5 ispisuje sledeću figuru:

///\\
\///\
\\///
\\\//
/\\\/
Opis ulaza
Preko standardnog ulaza se unosi prirodan broj N.

Opis izlaza
Ispisuje se tražena figura na standardni izlaz.

Primer 1
Ulaz
5
Izlaz
///\\
\///\
\\///
\\\//
/\\\/
Primer 2
Ulaz
8
Izlaz
///\\\//
/\\\///\
\\///\\\
///\\\//
/\\\///\
\\///\\\
///\\\//
/\\\///\*/

#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int brojac = 1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(brojac > 0 && brojac <= 3){
                printf("/");
            }
            else if(brojac > 3 && brojac <=6){
                printf("\\");
            }
            else{
                printf("\\");
            }
            brojac = (brojac+1)%6;
        }
        printf("\n");
    }

    return 0;
}