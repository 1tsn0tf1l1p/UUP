#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 250

/*
Napisati program koji učitava podatke o teretanama iz tekstualnog fajla u kom se u
jednom redu nalaze ime opštine, ime teretane, broj sprava, broj sprava za kardio razdvojeni
crticom. Primer: Cukarica-Ahilej-92-21.
Napisati meni za interakciju preko konzole i implementirati sledeće opcije:

a) (6p) Učitavanje podataka. Podaci o teretanama učitavaju se u binarno pretraživačko
stablo. Stablo je alfabetski opadajuće sortirano po opštini.

b) (2p) Ispis svih teretana. Ispisati podatke o svim teretanama sortirane alfabetski rastuće.

c) (8p) Ispis teretana sa spravama. Korisnik unosi broj, ispisati sve teretane čiji je broj
sprava koje nisu kardio sprave veći od unetog broja.

d) (8p) Ispisati sve teretane u određenoj opštini. Korisnik unosi deo naziva opštine,
ukoliko se opština završava sa unetim slovima onda ispisati sve teretane u njoj.

e) (1p) Izlaz iz programa i brisanje stabla.
 */

typedef struct Teretana{

    char opstina[SIZE];
    char teretana[SIZE];
    int broj_sprava;
    int broj_kardio;
    struct Teretana *left;
    struct Teretana *right;

} TERETANA;

TERETANA *create_item(char *opstina, char *teretana, int broj_sprava, int broj_kardio){

    TERETANA *novi = (TERETANA *) malloc(sizeof(TERETANA));

    strcpy(novi->opstina, opstina);
    strcpy(novi->teretana, teretana);
    novi->broj_sprava = broj_sprava;
    novi->broj_kardio = broj_kardio;
    novi->left = NULL;
    novi->right = NULL;

    return novi;
}

TERETANA *add_to_tree_teretana(TERETANA *root, char *opstina, char *teretana, int broj_sprava, int broj_kardio){

    TERETANA *novi = create_item(opstina, teretana, broj_sprava, broj_kardio);

    if(root == NULL){
        root = novi;
    }
    else if(strcmp(root->opstina, opstina) < 0 || (strcmp(root->opstina, opstina) == 0 && root->broj_sprava<broj_sprava)){
        root->left = add_to_tree_teretana(root->left, opstina, teretana, broj_sprava, broj_kardio);
    }else{
        root->right = add_to_tree_teretana(root->right, opstina, teretana, broj_sprava, broj_kardio);
    }

    return root;

}

TERETANA *ucitaj(TERETANA *root){

    FILE *fp = fopen("zad.txt", "r");

    if(fp == NULL){
        printf("Neuspesno!\n");
    }
    else{
        printf("Uspesno!\n");
    }

    char line[SIZE];

    while(fgets(line, SIZE, fp)){

        char opstina[SIZE];
        char teretana[SIZE];
        int broj_sprava;
        int broj_kardio;

        char *token = strtok(line, "-");

        int brojac = 0;

        while(token){

            if(brojac == 0){
                strcpy(opstina, token);
            }
            else if(brojac == 1){
                strcpy(teretana, token);
            }
            else if(brojac == 2){
                broj_sprava = atoi(token);
            }
            else if(brojac == 3){
                broj_kardio = atoi(token);
            }
            brojac++;

            token = strtok(NULL, "-");

        }

        root = add_to_tree_teretana(root, opstina, teretana, broj_sprava, broj_kardio);

    }

    fclose(fp);
    return root;
}

void broj_sprava(TERETANA *root, int broj){

    if(root == NULL){
        return;
    }

    broj_sprava(root->left, broj);

    if((root->broj_sprava - root->broj_kardio) > broj){
        printf("%s-%s-%d-%d\n", root->opstina, root->teretana, root->broj_sprava, root->broj_kardio);
    }

    broj_sprava(root->right, broj);
}

int na_kraju_stringa(char *str, char *unos){

    int index = strlen(unos) - 1;

    for(int i = strlen(str) - 1; i>=0; i--){
        if(str[i] != unos[index--]){
            return 0;
        }
        if(index == -1){
            return 1;
        }
    }

    return 1;
}

void opstina(TERETANA *root, char *unos){

    if(root == NULL){
        return;
    }

    opstina(root->left, unos);

    if(na_kraju_stringa(root->opstina, unos)){
        printf("%s-%s-%d-&d\n", root->opstina, root->teretana, root->broj_sprava, root->broj_kardio);
    }

    opstina(root->right, unos);

}

void printuj(TERETANA *root){

    if(root == NULL){
        return;
    }

    printuj(root->right);

    printf("%s-%s-%d-%d\n", root->opstina, root->teretana, root->broj_sprava, root->broj_kardio);

    printuj(root->left);


}

TERETANA *obrisi(TERETANA *root){

    if(root == NULL){
        return NULL;
    }

    obrisi(root->left);
    obrisi(root->right);
    free(root);

}

int main(){

    TERETANA *root = NULL;

    int opcija;

    while(1){

        printf("\nOdaberite opciju: ");
        scanf("%d", &opcija);
        if (opcija == 7) {
            return 0;
        }
        else if (opcija == 1) {
            root = ucitaj(root);
        }
        else if (opcija == 2) {
            printuj(root);
        }
        else if (opcija == 3) {
            int broj = 0;
            printf("Unesite broj: ");
            scanf("%d", &broj);
            broj_sprava(root, broj);
        }
        else if (opcija == 4) {
            char zavrsetak[SIZE];
            printf("Unesi zavrsetak: ");
            scanf("%s", zavrsetak);

            opstina(root, zavrsetak);
        }
        else if (opcija == 5) {
            root = obrisi(root);
            break;
        }
        else {
        }

    }

    return 0;
}