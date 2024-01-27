#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 250

/*Napisati program koji iz fajla učitava podatke efektima dijete na određene osobe. U svakom
redu se nalaze ime osobe, naziv dijete i broj kilograma koje je osoba izgubila, razdvojene zapetom.
Primer: Vladimir,paleo,5. Napraviti meni za interakciju preko konzole sa sledećim opcijama:
a) (10p) Učitavanje podataka – unosi se naziv fajla, a podaci se učitavaju u binarno pretraživačko stablo,
sortirani rastuće po nazivu dijete.
b) (2p) Ispis podataka. Nakon učitavanja ispisati podatke iz stabla sortirano rastuce.
c) (4p) Ispis najefikasnije dijete – ispisati naziv dijete sa najvećom prosečnom izgubljenom masom po
osobi i odgovarajuću prosečnu vrednost na dve decimale. Ukoliko ima više najboljih, ispisati bilo koju.
d) (8p) Pronalaženje podataka o osobi – unosi se string – deo imena osobe, ispisuju se podaci o svim
osobama čije ime sadrži uneti string. Pretraga treba da bude neosetljiva na mala i velika slova.
e) (1p) Izlaz iz programa i brisanje stabla.
 * */

typedef struct BST_drvce{

    char ime[SIZE];
    char dijeta[SIZE];
    int kilogrami;
    struct BST_drvce *left;
    struct BST_drvce *right;

}BST;

BST *create_item(char *ime, char *dijeta, int kilogrami){

    BST *novi = (BST *) malloc(sizeof(BST));

    strcpy(novi->ime, ime);
    strcpy(novi->dijeta, dijeta);
    novi->kilogrami = kilogrami;
    novi->left = NULL;
    novi->right = NULL;

    return novi;
}

BST *add_item(BST *root, char *ime, char *dijeta, int kilogrami){

    BST *novi = create_item(ime, dijeta, kilogrami);

    if(root == NULL){
        root = novi;
    }
    else if(strcmp(root->dijeta, dijeta) >= 0){
        root->left = add_item(root->left, ime, dijeta, kilogrami);
    }
    else{
        root->right = add_item(root->right, ime, dijeta, kilogrami);
    }

    return root;
}

BST *ucitaj(BST *root){

    FILE *fp = fopen("micko.txt", "r");

    if(fp == NULL){
        printf("GRESKA\n");
    }else{
        printf("USPELO\n");
    }

    char line[SIZE];

    while(fgets(line, SIZE, fp)){

        char ime[SIZE];
        char dijeta[SIZE];
        int kilogrami;

        int brojac = 0;

        char *token = strtok(line, ",");

        while(token){

            if(brojac == 0){
                strcpy(ime, token);
            }
            else if(brojac == 1){
                strcpy(dijeta, token);
            }
            else if(brojac == 2){
                 kilogrami = atoi(token);
            }

            brojac++;
            token = strtok(NULL, ",");

        }

        root = add_item(root, ime, dijeta, kilogrami);

    }

    fclose(fp);
    return root;
}

int da_li_se_nalazi(char niz[SIZE][SIZE], int n, char dijeta[SIZE]){

    for(int i = 0; i<n; i++){
        if(strcmp(niz[i], dijeta) == 0) {
            return 1;
        }
    }

    return 0;
}

void pronadji_sve_dijete(BST *root,char niz_dijeta[SIZE][SIZE], int *n){

    if(root == NULL){
        return;
    }

    pronadji_sve_dijete(root->left, niz_dijeta, n);

    if(!da_li_se_nalazi(niz_dijeta, *n, root->dijeta)){
        strcpy(niz_dijeta[*n], root->dijeta);
        *n = *n + 1;
    }

    pronadji_sve_dijete(root->right, niz_dijeta, n);


}

void efikasnost_dijeta(BST *root, char niz_dijeta[SIZE][SIZE], int *n, int *trenutni_zbir, int *brojac){

    efikasnost_dijeta(root->left, niz_dijeta, n, trenutni_zbir, brojac);

    if(strcmp(niz_dijeta[*n], root->dijeta) == 0){
        *trenutni_zbir = *trenutni_zbir + root->kilogrami;
        *brojac = *brojac + 1;
    }

    efikasnost_dijeta(root->right, niz_dijeta, n, trenutni_zbir, brojac);

}

void ispisi(BST *root){

    if(root == NULL){
        return;
    }

    ispisi(root->left);

    printf("%s %s %d\n", root->ime, root->dijeta, root->kilogrami);

    ispisi(root->right);
}


int main(){

    BST *root = NULL;

    int opcija;
    int izlaz = 0;

    while(1) {
        if(izlaz) break;
        printf("Unesi opciju\n");
        scanf("%d", &opcija);

        char niz_dijeta[SIZE][SIZE];
        int n = 0;

        int brojac = 0;
        int zbir_kilograma = 0;
        float maks = 0;
        char pomocni[SIZE] = "";

        switch(opcija) {
            case 1:
                root = ucitaj(root);
                break;
            case 2:
                ispisi(root);
                break;
            case 3:
                pronadji_sve_dijete(root, niz_dijeta, &n);

                break;
            case 4:
                efikasnost_dijeta(root, niz_dijeta, &n, &zbir_kilograma, &brojac);

                for(int i = 0; i<n; i++) {
                    if (zbir_kilograma * 1.0 / brojac > maks) {
                        maks = zbir_kilograma * 1.0 / brojac;
                        strcpy(pomocni, niz_dijeta[i]);

                    }
                }

                printf("%s %f\n", pomocni, maks);


                break;
            case 5:

                break;
            default:
                izlaz = 1;
                break;
        }
    }

    return 0;
}
