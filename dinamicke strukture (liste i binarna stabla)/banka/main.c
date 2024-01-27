#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 300

/*Napisati program koji učitava podatke o bankovnim računima iz tekstualnog fajla u kom se u
jednom redu nalaze ime banke, puno ime osobe, novac i grad. Svi podaci razdvojeni su zapetom.
Primer: Raiffeisen,Pera Peric,7000,Kraljevo
Napisati meni za interakciju preko konzole i implementirati sledeće opcije:
a) (8p) Učitavanje podataka. Podaci o bankovnim računima učitavaju se u listu, sortirano
neopadajuće po imenu banke.
b) (2p) Ispis svih bankovnih računa.
c) (7p) Ispis svih gradova u kojima je ukupno uplaćeno više od 10000 (Obratiti pažnju na
duplikate).

d) (7p) Brisanje svih računa sa manje od navedene svote novca. Korisnik unosi određenu
vrednost, na osnovu koje se iz liste uklanjaju računi sa svotom novca manjom od navedene.
e) (1p) Izlaz iz programa i brisanje liste.*/

typedef struct Podaci{

    char banka[SIZE];
    char ime[SIZE];
    int stanje;
    char grad[SIZE];
    struct Podaci *next;

}PODACI;

PODACI *create_item(char *banka, char *ime, int stanje, char *grad){

    PODACI *novi = (PODACI *)malloc(sizeof(PODACI));

    strcpy(novi->banka, banka);
    strcpy(novi->ime, ime);
    novi->stanje = stanje;
    strcpy(novi->grad, grad);
    novi->next = NULL;

    return novi;
}

PODACI *add_to_list_podaci(PODACI *head, char *banka, char *ime, int stanje, char *grad){

    PODACI *novi = create_item(banka, ime, stanje, grad);

    if(head == NULL){
        head = novi;
        return head;
    }

    PODACI *temp = head;

    if(strcmp(temp->banka, banka) > 0){
        novi->next = temp;
        head = novi;
        return head;
    }

    while(temp->next != NULL && strcmp(temp->next->banka, banka) < 0){
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;
}

PODACI *ucitaj(PODACI *head){

    FILE *fp = fopen("racuni.txt", "r");

    if(fp == NULL){
        printf("Neuspesno ucitavanje\n");
    }else{
        printf("Uspesno ucitavanje\n");
    }

    char line[SIZE];

    while(fgets(line, SIZE, fp)){

        if(line[strlen(line) - 1] == '\n'){
            line[strlen(line) - 1] = '\0';
        }

        char banka[SIZE];
        char ime[SIZE];
        int stanje;
        char grad[SIZE];

        int brojac = 0;

        char *token = strtok(line, ",");

        while(token){
            if(brojac == 0){
                strcpy(banka, token);
            }
            else if(brojac == 1){
                strcpy(ime, token);
            }
            else if(brojac == 2){
                stanje = atoi(token);
            }
            else if(brojac == 3){
                strcpy(grad, token);
            }

            brojac++;
            token = strtok(NULL, ",");
        }

        head = add_to_list_podaci(head, banka, ime, stanje, grad);

    }

    fclose(fp);

    return head;

}

void printuj(PODACI *head){

    if(head == NULL){
        return;
    }

    printf("%s,%s,%d,%s\n", head->banka, head->ime, head->stanje, head->grad);

    printuj(head->next);

}

int pronadji_gradove(char niz[SIZE][SIZE], int n, char grad[SIZE]){

    for(int i = 0; i<n; i++){
        if(strcmp(niz[i], grad) == 0){
            return 0;
        }
    }

    return 1;

}

void gradovi(PODACI *head){

    char niz_gradova[SIZE][SIZE];

    int n = 0;

    PODACI *temp = head;

    while(temp != NULL){
        if(pronadji_gradove(niz_gradova, n, temp->grad)){
            strcpy(niz_gradova[n++], temp->grad);
        }
        temp = temp->next;
    }



    for(int i = 0; i<n; i++){
        PODACI *tempcpy = head;
        int ukupno = 0;
        while(tempcpy != NULL){
            if(strcmp(niz_gradova[i], tempcpy->grad) == 0){
                ukupno = ukupno + tempcpy->stanje;
            }
            tempcpy = tempcpy->next;
        }

        if(ukupno>10000){
            printf("%s\n", niz_gradova[i]);

        }

    }

}

PODACI *obrisi_racune(PODACI *head, int svota_novca){

    PODACI *temp = head;

    while(temp->next != NULL){
        if(temp->next->stanje < svota_novca){
            PODACI *garbage = temp->next;
            temp->next = temp->next->next;
            free(garbage);
        }else{
            temp = temp->next;
        }

    }

    temp = head;

    if(temp->stanje < svota_novca){
        PODACI *garbage = temp;
        head = temp->next;
        free(garbage);
    }

    return head;
}

void delete_list(PODACI *head){

    if(head == NULL){
        return;
    }

    delete_list(head->next);

    free(head);

}


void menu(){

    printf("1. Ucitavanje podataka.\n");
    printf("2. Ispis podataka.\n");
    printf("3. Ispis svih gradova u kojima je ukupno uplaceno vise od 10000.\n");
    printf("4. Brisanje svih računa sa manje od navedene svote novca.\n");
    printf("5. Izlaz.\n");


}

int main(){

    PODACI *head = NULL;

    int opcija;
    int izlaz = 0;

    int svota_novca;

    while(1){

        menu();

        printf("Unesi opciju: ");
        scanf("%d", &opcija);

        if(izlaz){
            break;
        }

        switch (opcija) {

            case 1:
                head = ucitaj(head);
                break;
            case 2:
                printuj(head);
                break;
            case 3:
                gradovi(head);
                break;
            case 4:
                printf("Unesite odredjenu svotu novca: ");
                scanf("%d", &svota_novca);
                head = obrisi_racune(head, svota_novca);
                break;
            case 5:
                delete_list(head);
                izlaz = 1;
                break;
            default:
                printf("Pogresan unos!\n");
                break;

        }

    }

    return 0;
}