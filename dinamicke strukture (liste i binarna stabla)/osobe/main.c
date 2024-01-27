/*Napisati program koji učitava podatke o osobama iz tekstualnog fajla u kom se u jednom
redu nalaze ime, visina i težina osobe razdvojeni zapetom. Primer: Marko,182,79
Napisati meni za interakciju preko konzole i implementirati sledeće opcije:

a) (10p) Učitavanje podataka. Podaci o osobama učitavaju se u binarno pretraživačko
stablo. Stablo je alfabetski rastuće sortirano.

b) (2p) Ispis svih osoba. Ispisati podatke o svim osoba sortirane alfabetski rastuće.

c) (4p) Ispis najviše i najniže osobe. Ispisati podatke o najvišoj, a zazim o najnižoj osobi.

d) (8p) Ispisati osobe lakše od određene težine. Korisnik unosi određenu težinu, na
osnovu koje se ispisuju imena i težine svih osoba lakših od navedene vrednosti, sortirane
po težini u nerastućem poretku.

e) (1p) Izlaz iz programa i brisanje stabla.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 250

typedef struct Osobe{

    char ime[SIZE];
    int visina;
    int tezina;
    struct Osobe *left;
    struct Osobe *right;
}OSOBE;

typedef struct Weight{

    char ime[SIZE];
    int visina;
    int tezina;
    struct Weight *left;
    struct Weight *right;

}WEIGHT;

WEIGHT *create_item_weight(char *ime, int visina, int tezina){

    WEIGHT *novi = (WEIGHT *) malloc(sizeof(WEIGHT));

    strcpy(novi->ime, ime);
    novi->visina = visina;
    novi->tezina = tezina;
    novi->left = NULL;
    novi->right = NULL;

    return novi;

}

WEIGHT *add_list_item_weight(WEIGHT *root, char *ime, int visina, int tezina){

    WEIGHT *novi = create_item_weight(ime, visina, tezina);

    if(root == NULL){
        root = novi;
    }
    else if(root->tezina > novi->tezina){
        root->left = add_list_item_weight(root->left, ime, visina, tezina);
    }
    else{
        root->right = add_list_item_weight(root->right, ime, visina, tezina);
    }

    return root;

}


OSOBE *create_item(char *ime, int visina, int tezina){

    OSOBE *novi = (OSOBE *) malloc(sizeof(OSOBE));

    strcpy(novi->ime, ime);
    novi->visina = visina;
    novi->tezina = tezina;
    novi->left = NULL;
    novi->right = NULL;

    return novi;

}

OSOBE *add_to_list_item(OSOBE *root, char *ime, int visina, int tezina){

    OSOBE *novi = create_item(ime, visina, tezina);

    if(root == NULL){
        root = novi;
    }
    else if(strcmp(root->ime, novi->ime) >= 0){
        root->left = add_to_list_item(root->left, ime, visina, tezina);
    }else{
        root->right = add_to_list_item(root->right, ime, visina, tezina);
    }

    return root;

}

OSOBE *ucitaj(OSOBE *root){

    FILE *fp = fopen("zad.txt", "r");

    if(fp == NULL){
        printf("GRESKA!\n");
    }
    else{
        printf("USPESNO!\n");
    }

    char line[SIZE];

    while(fgets(line, SIZE, fp)){

        char ime[SIZE];
        int visina;
        int tezina;

        int brojac = 0;

        char *token = strtok(line, ",");

        while(token){

            if(brojac == 0){
                strcpy(ime, token);
            }
            else if(brojac == 1){
                visina = atoi(token);
            }
            else if(brojac == 2){
                tezina = atoi(token);
            }

            brojac++;
            token = strtok(NULL, ",");

        }

        root = add_to_list_item(root, ime, visina, tezina);

    }

    fclose(fp);

    return root;

}

void find_najvisi_najnizi(OSOBE *root, int *max, int *min, char ime_najvisi[SIZE], char ime_najnizi[SIZE], int *tezina_najvisi, int *tezina_najnizi){

    if(root == NULL){
        return;
    }

    find_najvisi_najnizi(root->left, max, min, ime_najvisi, ime_najnizi, tezina_najvisi, tezina_najnizi);

    if(root->visina>*max){
        *max = root->visina;
        strcpy(ime_najvisi, root->ime);
        *tezina_najvisi = root->tezina;

    }
    if(root->visina<*min){
        *min = root->visina;
        strcpy(ime_najnizi, root->ime);
        *tezina_najnizi = root->tezina;
    }

    find_najvisi_najnizi(root->right, max, min, ime_najvisi, ime_najnizi, tezina_najvisi, tezina_najnizi);

}

void printuj_weight(WEIGHT *root){

    if(root == NULL){
        return;
    }

    printuj_weight(root->left);
    printf("%s %d %d\n", root->ime, root->visina, root->tezina);
    printuj_weight(root->right);

}

WEIGHT *uporedi(OSOBE *root_osobe, WEIGHT *root_weight, int tezina){

    if(root_weight == NULL){
        return root_weight;
    }

    uporedi(root_osobe->left, root_weight, tezina);

    if(root_osobe->tezina < tezina){
        printf("\n");
        root_weight = add_list_item_weight(root_weight, root_osobe->ime, root_osobe->visina, root_osobe->tezina);
        printuj_weight(root_weight);
    }

    uporedi(root_osobe->right, root_weight, tezina);

    return root_weight;

}


void printuj(OSOBE *root){

    if(root == NULL){
        return;
    }

    printuj(root->left);
    printf("%s %d %d\n", root->ime, root->visina, root->tezina);
    printuj(root->right);

}

int main(){

    OSOBE *root = NULL;
    WEIGHT *root2 = NULL;
    int max = INT_MIN;
    int min = INT_MAX;

    char ime_najvisi[SIZE];
    char ime_najnizi[SIZE];
    int tezina_najvisi;
    int tezina_najnizi;

    int weight = 0;

    int opcija;
    while (1) {
        printf("\nUnesite opciju: ");
        scanf("%d", &opcija);
        if (opcija == 1) {
            root = ucitaj(root);
        }
        else if (opcija == 2) {
            printuj(root);
        }
        else if (opcija == 3) {
            find_najvisi_najnizi(root, &max, &min, ime_najvisi, ime_najnizi, &tezina_najvisi, &tezina_najnizi);
            printf("%s,%d,%d\n", ime_najvisi, max, tezina_najvisi);
            printf("%s,%d,%d\n", ime_najnizi, min, tezina_najnizi);

        }
        else if (opcija == 4) {
            printf("Unesi tezinu: ");
            scanf("%d", &weight);
            root2 = uporedi(root, root2, weight);
            printuj_weight(root2);
        }
        else if (opcija == 5) {

        }
        else if (opcija == 7) {
            break;
        }
    }

    return 0;
}