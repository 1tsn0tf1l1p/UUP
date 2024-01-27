#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 250

/**
Napisati program koji učitava podatke o izmerenim najvišim dnevnim temperaturama po
gradovima i državama. Jedan red u fajlu sadrži prvo naziv države, zatim naziv grada i izmerenu
temperaturu, podaci su razdvojeni spejsom, na primer:
Srbija Beograd 13
Napraviti meni za interakciju preko konzole sa slededim opcijama.

a) (8p) učitavanje podataka, unosi se naziv fajla koji sadrži opisane podatke i učitava se u binarno
stablo uređeno po nazivu grada (abecedno), ovu operaciju je potrebno implementirati na dva načina,
iterativno i rekurzivno

b) (2p) ispis elemenata stabla, ispisuje sve učitane elemente sortirane abecedno po nazivu grada,

c) (6p) najhladniji grad, u stablu pronadi najhladniji grad i ispisati njegov naziv, državu i temperaturu
(ako ima više najhladnijih gradova ispisati bilo koji od njih)

d) (9p) ispis prosečne temperature za državu, unosi se naziv države i izračunava se i ispisuje
prosečna temperatura svih gradova u toj državi, operaciju implementirati nad stablom, ne čitati
ponovo podatke iz fajla
*/

typedef struct Bst{

    char drzava[SIZE];
    char grad[SIZE];
    int temperatura;
    struct BST *left;
    struct BST *right;

}BST;

BST *create_item(char *drzava, char *grad, int temperatura){

    BST *novi = (BST *) malloc(sizeof(BST));

    strcpy(novi->drzava, drzava);
    strcpy(novi->grad, grad);
    novi->temperatura = temperatura;
    novi->left = NULL;
    novi->right = NULL;

    return novi;
}

BST *add_to_tree(BST *root, char *drzava, char *grad, int temperatura){

    BST *novi = create_item(drzava, grad, temperatura);

    if(root == NULL){
        root = novi;
    }
    else if(strcmp(root->grad, grad) >= 0){
        root->left = add_to_tree(root->left, drzava, grad, temperatura);
    }else{
        root->right = add_to_tree(root->right, drzava, grad, temperatura);
    }

    return root;

}

BST *ucitaj(BST *root){

    FILE *fp = fopen("zad1.txt", "r");

    if(fp == NULL) {
        printf("Neuspesno ucitavanje!\n");
    }
    else{
        printf("Uspesno ucitavanje!\n");
    }

    char line[SIZE];

    while(fgets(line, SIZE, fp)){

        char drzava[SIZE];
        char grad[SIZE];
        int temperatura;

        char *token = strtok(line, " ");

        int brojac = 0;

       while(token){

           if(brojac == 0){
               strcpy(drzava, token);
           }
           else if(brojac == 1){
               strcpy(grad, token);
           }
           else if(brojac == 2){
               temperatura = atoi(token);
           }

           brojac++;

           token = strtok(NULL, " ");

       }

       root = add_to_tree(root, drzava, grad, temperatura);

    }

    fclose(fp);
    return root;
}

void printuj(BST *root){
    if(root == NULL){
        return;
    }

    printuj(root->left);

    printf("%s %s %d\n", root->drzava, root->grad, root->temperatura);

    printuj(root->right);
}

int main(){

    BST *root = NULL;

    root = ucitaj(root);
    printuj(root);

    return 0;
}