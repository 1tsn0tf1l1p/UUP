/**
Napraviti meni za interakciju preko konzole i implementirati sledeće opcije:

a) (4p) učitavanje podataka, podaci o utakmicama učitavaju se u listu uređenu
rastuće po datumu, nakon učitavanja ispisati elemente liste redom.

b) (6p) broj golova određenog tima, unosi se oznaka tima (slovo) i potrebno je sabrati
i ispisati koliko je golova postigao tim ukupno na svim utakmicama. Ovu funkcionalnost
implementirati na dva načina, iterativno i rekurzivno.

c) (14p) obračun poena i generisanje tabele, osmisliti odgovarajuću strukturu koja
sadrži timove zajedno sa obračunatim bodovima, brojem datih i primljenih golova, bodovi
se dodeljuju prema pravilu 3 boda za pobedu, 0 za poraz, 1 bod za nerešen rezultat.
Prikazati tabelu timova sortiranu po broju bodova opadajuće, pa za isti broj bodova
prema većoj gol razlici (razlika između datih i primljenih golova).

d) (1p) izlaz iz programa i brisanje svih struktura
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 250

typedef struct Utakmica {

    char datum[SIZE];
    char tim1[SIZE];
    char tim2[SIZE];
    int gol1;
    int gol2;
    struct Utakmica *next;

}UTAKMICA;

typedef struct Poeni {

    char tim[SIZE];
    int bodovi;
    int dati;
    int primljeni;
    struct Poeni *next;
}POENI;

UTAKMICA *create_list_item_utakmica(char *datum, char *tim1, char *tim2, int gol1, int gol2){

    UTAKMICA *novi = (UTAKMICA *) malloc(sizeof(UTAKMICA));

    strcpy(novi->datum, datum);
    strcpy(novi->tim1, tim1);
    strcpy(novi->tim2, tim2);
    novi->gol1 = gol1;
    novi->gol2 = gol2;
    novi->next = NULL;

    return novi;
}

POENI *create_list_item_poeni(char *tim, int bodovi, int dati, int primljeni){

    POENI *novi = (POENI *) malloc(sizeof(POENI));

    strcpy(novi->tim, tim);
    novi->bodovi = bodovi;
    novi->dati = dati;
    novi->primljeni = primljeni;
    novi->next = NULL;

    return novi;
}

UTAKMICA *add_to_list_utakmica(UTAKMICA *head, char *datum, char *tim1, char *tim2, int gol1, int gol2){

    UTAKMICA *novi = create_list_item_utakmica(datum, tim1, tim2, gol1, gol2);

    if(head == NULL){
        head = novi;
        return head;
    }

    UTAKMICA *temp = head;

    if(strcmp(temp->datum, datum) >= 0){
        novi->next = temp;
        head = novi;
        return head;
    }

    while(temp->next != NULL && strcmp(temp->next->datum, datum) < 0){
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;
}

POENI *add_to_list_poeni(POENI *head, char *tim, int bodovi, int dati, int primljeni){

    POENI *novi = create_list_item_poeni(tim, bodovi, dati, primljeni);

    if(head == NULL){
        head = novi;
        return head;
    }

    POENI *temp = head;

    if(temp->bodovi < bodovi){
        novi->next = temp;
        head = novi;
        return head;
    }

    while(temp->next != NULL && temp->next->bodovi > bodovi){
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;
}

UTAKMICA *ucitaj(UTAKMICA *head){

    FILE *fp = fopen("zad.txt", "r");

    if(fp == NULL){
        printf("Ucitavanje neuspesno.\n");
    }else{
        printf("Ucitavanje uspesno.\n");
    }

    char line[SIZE];

    while(fgets(line, SIZE, fp) != NULL){

        int brojac = 0;
        char datum[SIZE];
        char tim1[SIZE];
        char tim2[SIZE];
        int gol1;
        int gol2;

        char *token = strtok(line, " ");

        while(token){

            if(brojac == 0){
                strcpy(datum, token);
                brojac++;
            }
            else if(brojac == 1){
                strcpy(tim1, token);
                brojac++;
            }
            else if(brojac == 2){
                strcpy(tim2, token);
                brojac++;
            }
            else if(brojac == 3){
                gol1 = atoi(token);
                brojac++;
            }
            else if(brojac == 4){
                gol2 = atoi(token);
                brojac++;
            }

            token = strtok(NULL, " ");

        }

        head = add_to_list_utakmica(head, datum, tim1, tim2, gol1, gol2);

    }

    fclose(fp);
    return head;
}

void printuj(UTAKMICA *head){

    if(head == NULL){
        return;
    }

    printf("%s %s %s %d %d\n", head->datum, head->tim1, head->tim2, head->gol1, head->gol2);

    printuj(head->next);
}

int broj_golova_tima_iterativno(UTAKMICA *head, char tim[SIZE]){

    UTAKMICA *temp = head;

    int golovi = 0;

    while(temp){
        if(strcmp(temp->tim1, tim) == 0){
            golovi+=temp->gol1;
        }
        else if(strcmp(temp->tim2, tim) == 0){
            golovi+=temp->gol2;
        }

        temp = temp->next;
    }

    return golovi;

}

int broj_golova_tima_rekurzivno(UTAKMICA *head, char tim[SIZE], int golovi){

    if(head == NULL){
        return golovi;
    }

    if(strcmp(head->tim1, tim) == 0){
        golovi+=head->gol1;
    }
    else if(strcmp(head->tim2, tim) == 0){
        golovi+=head->gol2;
    }

    broj_golova_tima_rekurzivno(head->next, tim, golovi);

}

int da_li_se_nalazi(char niz[SIZE][SIZE], char *tim, int n){

    for(int i = 0; i<n; i++){
        if(strcmp(niz[i], tim) == 0){
            return 1;
        }
    }
    return 0;
}

POENI *poeni_timova(UTAKMICA *head_utakmica, POENI *head_poeni){

    char niz[SIZE][SIZE];

    int n = 0;

    UTAKMICA *temp = head_utakmica;

    while(temp){
        if(!da_li_se_nalazi(niz, temp->tim1, n)){
            strcpy(niz[n++], temp->tim1);
        }
        temp = temp->next;
    }


    for(int i = 0; i<n; i++){

        int bodovi = 0;
        int dati = 0;
        int primljeni = 0;
        char tim[SIZE];
        UTAKMICA *tempcpy = head_utakmica;

        while(tempcpy){
            if(strcmp(niz[i], tempcpy->tim1) == 0){
                dati = dati + tempcpy->gol1;
                primljeni = primljeni + tempcpy->gol2;

                if(tempcpy->gol1>tempcpy->gol2){
                    bodovi = bodovi + 3;
                }
                else if(tempcpy->gol1<tempcpy->gol2){
                    bodovi = bodovi + 0;
                }
                else if(tempcpy->gol1 == tempcpy->gol2){
                    bodovi = bodovi + 1;
                }
            }
            tempcpy = tempcpy -> next;
        }
        head_poeni = add_to_list_poeni(head_poeni, niz[i], bodovi, dati, primljeni);
    }
    return head_poeni;
}

void printuj_poene(POENI *head){

    if(head == NULL){
        return;
    }

    printf("%s %d %d %d\n", head->tim, head->bodovi, head->dati, head->primljeni);

    printuj_poene(head->next);
}

POENI *clear(POENI *head) {
    POENI *temp = head, *next;
    while (temp) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
    return head;
}

UTAKMICA *zbrisi(UTAKMICA *head) {
    UTAKMICA *temp = head, *next;
    while (temp) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
    return head;
}

void menu() {
    printf("1. Ucitaj podatke\n");
    printf("2. Broj golova odredjenog tima (Iterativno)\n");
    printf("3. Broj golova odredjenog tima (Rekurzivno)\n");
    printf("4. Obracun poena i generisanje tabele\n");
    printf("7. Izlaz\n");
}


int main(){

    UTAKMICA *head = NULL;
    POENI *head2 = NULL;

    int opcija;

    while (1) {
        menu();
        printf("\nUnesite opciju: ");
        scanf("%d", &opcija);
        if (opcija == 1) {
            head = ucitaj(head);
            printuj(head);
        }
        else if (opcija == 2) {
            char tim[SIZE];
            printf("Unesite tim: ");
            scanf("%s", tim);
            printf("%d\n", broj_golova_tima_iterativno(head, tim));
        }
        else if (opcija == 3) {
            char timrek[SIZE];
            int golovi = 0;
            printf("Unesite tim: ");
            scanf("%s", timrek);
            printf("%d\n", broj_golova_tima_rekurzivno(head, timrek, golovi));
        }
        else if (opcija == 4) {
            head2 = poeni_timova(head, head2);
            printuj_poene(head2);
        }
        else if (opcija == 7) {
            head = zbrisi(head);
            head2 = clear(head2);
            break;
        }
    }

    return 0;
}
