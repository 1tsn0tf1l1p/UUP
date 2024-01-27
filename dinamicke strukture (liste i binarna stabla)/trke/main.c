#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 250

/**
Napisati program koji učitava podatke o rezultatima trka za više trkača. U jednom
redu u fajlu nalaze se podaci o rezultatu jednog trkača na jednoj trci i to redom brojčana
oznaka trke, slovna oznaka igrača i postignuti rezultat trkača na trci.
Primer
10 c 11.09 - na trci pod brojem 10 trkač sa oznakom c postigao je rezultat 11.09 sekundi.
Napraviti meni za interakciju preko konzole i implementirati sledeće opcije:

a) (7p) učitavanje podataka, podaci o rezultatima trka učitavaju se u listu uređenu
prvo po brojčanoj oznaci trke rastuće, a zatim za istu trku po vremenu trkača opadajuće,
nakon učitavanja ispisati listu.

b) (8p) redni broj na trci za igrača, unosi se oznaka trke i oznaka igrača i treba
izračunati koje mesto je uneti igrač osvojio na unetoj trci (iskoristiti način na koji je lista
uređena), ovu funkcionalnost je potrebno uraditi na dva načina iterativno i rekurzivno.

c) (9p) generisanje ukupnih rezultata, osmisliti strukturu u koju će se smestiti igrači i
ukupan broj osvojenih poena na trkama, poeni se dodeljuju po formuli 20-mesto, gde je
mesto pozicija koju je igrač zauzeo na trci. Ispisati trkače i za svakog trkača osvojeni broj
poena u opadajućem redosledu po broju poena.

d) (1p) izlaz iz programa i brisanje svih struktura
**/

typedef struct Trka{

    int broj_trke;
    char trkac;
    float rez;
    struct Trka *next;

}TRKA;

typedef struct Ukupno{



}UKUPNO;

TRKA *create_item(int broj_trke, char trkac, float rez){

    TRKA *novi = (TRKA *) malloc(sizeof(TRKA));

    novi->broj_trke = broj_trke;
    novi->trkac = trkac;
    novi->rez = rez;
    novi->next = NULL;

    return novi;
}

TRKA *add_trka(TRKA *head, int broj_trke, char trkac, float rez){

    TRKA *novi = create_item(broj_trke, trkac, rez);

    if(head == NULL){
        head = novi;
        return head;
    }

    TRKA *temp = head;

    if(broj_trke < temp->broj_trke  || (broj_trke == temp->broj_trke && temp->rez < rez)){
        novi->next = temp;
        head = novi;
        return head;
    }

    while(temp->next != NULL && (broj_trke > temp->next->broj_trke ||
                                (broj_trke == temp->next->broj_trke && temp->next->rez > rez))){
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;

}

float konverzija(char *str){

    float rez;
    int brojac = 0;
    char *token = strtok(str, ".");
    while(token!=NULL){
        if(brojac == 0){
            rez = atoi(token);
        }else if(brojac == 1){
            rez = rez + atoi(token)/100.0;
        }
        brojac++;
        token = strtok(NULL, ".");
    }

    return rez;
}

TRKA *ucitaj(TRKA *head){

    FILE *fp = fopen("trka.txt", "r");

    if(fp == NULL){
        printf("Ucitavanje neuspesno!\n");
    }else{
        printf("Ucitavanje uspesno!\n");
    }

    char line[SIZE];

    while(fgets(line, SIZE, fp)){

        int broj_trke;
        char trkac;
        float rez;

        int brojac = 0;

        char *token = strtok(line, " ");

        while(token){

            if(brojac == 0){
                broj_trke = atoi(token);
            }
            else if(brojac == 1){
                trkac = token[0];
            }
            else if(brojac == 2){
                rez = konverzija(token);
            }
            brojac++;

            token = strtok(NULL, " ");

        }

        head = add_trka(head, broj_trke, trkac, rez);

    }

    fclose(fp);
    return head;
}

int mesto_trkaca_rek(TRKA *head, char trkac, int broj_trke, int brojac){

    if(head == NULL || (head->trkac == trkac && head->broj_trke == broj_trke)){
        return brojac;
    }

    if(head->broj_trke == broj_trke){
        return mesto_trkaca_rek(head->next, trkac, broj_trke, brojac+1);
    }
    else{
        return mesto_trkaca_rek(head->next, trkac, broj_trke, brojac);
    }

}

void printuj(TRKA *head){

    if(head == NULL){
        return;
    }

    printf("%d %c %.2f\n", head->broj_trke, head->trkac, head->rez);

    printuj(head->next);

}

void meni() {
    printf("1. Ucitaj podatke\n");
    printf("2. Prikazi podatke\n");
    printf("3. Prikazi redni broj igraca na trci (Iterativno)\n");
    printf("4. Prikazi redni broj igraca na trci (Rekurzivno)\n");
    printf("5. Generisi rezultate\n");
    printf("7. Izlaz\n");
}

int main(){

    TRKA *head = NULL;

    int opcija;
    char trkac;
    int broj_trke;

    while (1) {
        meni();
        printf("\nOdaberite opciju: ");
        scanf("%d", &opcija);
        if (opcija == 7) {
            printf("\nExited!\n");
            return 0;
        }
        else if (opcija == 1) {
            head = ucitaj(head);
        }
        else if (opcija == 2) {
            printuj(head);
        }
        else if (opcija == 3) {
            int broj;
            char oznaka;
            printf("Unesite oznaku trke i oznaku igraca: ");
            scanf("%d %c", &broj, &oznaka);
            printf("%d", mesto_trkaca_rek(head, broj, oznaka, 0));

        }
        else if (opcija == 4) {

        }
        else if (opcija == 5) {

        }
        else {

            return 0;
        }

    }


    return 0;
}