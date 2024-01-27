/*
Napisati program koji učitava podatke o popisima proizvoda iz fajla `prodavnice.txt` u kom
se u jednom redu nalaze naziv prodavnice, naziv robe, cena i broj komada. Svi podaci razdvojeni
su zapetom. Primer: Maxi,mleko,120,10
Napisati meni za interakciju preko konzole i implementirati sledeće opcije:

a) (8p) Učitavanje podataka. Podaci o proizvodima učitavaju se u listu, sortirano
neopadajuće po nazivu robe, pa po količini.

b) (2p) Ispis svih unosa iz liste.

c) (7p) Brisanje svih unosa robe čija je cena svuda veća od unetog broja. Korisnik unosi
određenu vrednost, na osnovu koje se iz liste uklanjaju svi unosi koji sadrže robu čija je
cena veća od navedene u svim prodavnicama.

d) (7p) Ispis svih prodavnica koje na lageru imaju ukupno robe za manje od 10000 dinara,
sortirano po nazivu prodavnice. Obratiti pažnju da se prodavnice ne ponavljaju.

e) (1p) Izlaz iz programa i brisanje liste.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 250

typedef struct Proizvod
{

    char radnja[SIZE];
    char proizvod[SIZE];
    int cena;
    int komad;
    struct Proizvod *next;

} PROIZVOD;

typedef struct Ukupno{

    char radnja[SIZE];
    int cena;
    struct Ukupno *next;
}UKUPNO;

UKUPNO *create_item_ukupno(char *radnja, int cena)
{

    UKUPNO *new_node = (UKUPNO *)(malloc(sizeof(UKUPNO)));

    strcpy(new_node->radnja, radnja);
    new_node->cena = cena;
    new_node->next = NULL;

    return new_node;
}



PROIZVOD *create_item(char *radnja, char *proizvod, int cena, int komad)
{

    PROIZVOD *new_node = (PROIZVOD *)(malloc(sizeof(PROIZVOD)));

    strcpy(new_node->radnja, radnja);
    strcpy(new_node->proizvod, proizvod);
    new_node->cena = cena;
    new_node->komad = komad;
    new_node->next = NULL;

    return new_node;
}

/*
Učitavanje podataka. Podaci o proizvodima učitavaju se u listu, sortirano
neopadajuće po nazivu robe, pa po količini.
*/

PROIZVOD *add_to_list_proizvod(PROIZVOD *head, char *radnja, char *proizvod, int cena, int komad)
{

    PROIZVOD *novi = create_item(radnja, proizvod, cena, komad);

    if (head == NULL)
    {
        head = novi;
        return head;
    }

    PROIZVOD *temp = head;

    if (strcmp(temp->proizvod, proizvod) >= 0 && (temp->komad >= komad))
    {
        novi->next = temp;
        head = novi;
        return head;
    }

    while (temp->next != NULL && ((strcmp(proizvod, temp->next->proizvod) > 0) ||
                                  (strcmp(proizvod, temp->next->proizvod) == 0 && (komad > temp->next->komad))))
    {
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;
}

UKUPNO *add_to_list_ukupno(UKUPNO *head, char *radnja,int cena)
{

    UKUPNO *novi = create_item_ukupno(radnja, cena);

    if (head == NULL)
    {
        head = novi;
        return head;
    }

    UKUPNO *temp = head;

    if (strcmp(temp->radnja, radnja) >= 0)
    {
        novi->next = temp;
        head = novi;
        return head;
    }

    while (temp->next != NULL && ((strcmp(temp->next->radnja, radnja) < 0)))
    {
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;
}

PROIZVOD *ucitaj(PROIZVOD *head, char *fajl)
{

    FILE *fp = fopen("prodavnica.txt", "r");

    if (fp != NULL)
    {
        printf("Ucitavanje uspelo!!\n");
    }
    else
    {
        printf("Ucitavanje neuspesno :(((\n");
    }

    char line[SIZE];

    while (fgets(line, SIZE, fp) != NULL)
    {

        char radnja[SIZE];
        char proizvod[SIZE];
        int cena;
        int komad;

        int brojac = 0;
        char *token = strtok(line, ",");

        while (token)
        {
            if (brojac == 0)
            {
                strcpy(radnja, token);
                brojac++;
            }
            else if (brojac == 1)
            {
                strcpy(proizvod, token);
                brojac++;
            }
            else if (brojac == 2)
            {
                cena = atoi(token);
                brojac++;
            }
            else if (brojac == 3)
            {
                komad = atoi(token);
                brojac++;
            }

            token = strtok(NULL, ",");
        }

        head = add_to_list_proizvod(head, radnja, proizvod, cena, komad);
    }

    fclose(fp);
    return head;
}

PROIZVOD *obrisi_iz_liste(PROIZVOD *head, int broj)
{

    PROIZVOD *temp = head;

    while (temp->next != NULL)
    {

        if (temp->next->cena >= broj)
        {
            PROIZVOD *garbage = temp->next;
            temp->next = temp->next->next;
            free(garbage);
        }
        else
        {
            temp = temp->next;
        }
    }

    temp = head;

    if (temp->cena > broj)
    {
        PROIZVOD *garbage = temp;
        head = temp->next;
        free(garbage);
    }

    return head;
}

void printuj(PROIZVOD *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%s %s %d %d\n", head->radnja, head->proizvod, head->cena, head->komad);

    printuj(head->next);
}

void obrisi(PROIZVOD *head)
{
    if (head == NULL)
    {
        return;
    }

    obrisi(head->next);

    free(head);
}

int da_li_se_nalazi(char niz[SIZE][SIZE], char *radnja, int n){

    for(int i = 0; i<n; i++){
        if(strcmp(niz[i], radnja) == 0){
            return 0;
        }
    }

    return 1;

}

/*Ispis svih prodavnica koje na lageru imaju ukupno robe za manje od 10000 dinara,
sortirano po nazivu prodavnice. Obratiti pažnju da se prodavnice ne ponavljaju.*/

UKUPNO *dodaj_u_listu_ukupno(UKUPNO *head_ukupno, PROIZVOD *head_proizvod){

    char niz_radnji[SIZE][SIZE];

    int n = 0;

    PROIZVOD *temp = head_proizvod;

    while(temp != NULL){
        if(da_li_se_nalazi(niz_radnji, temp->radnja, n)){
            strcpy(niz_radnji[n++], temp->radnja);
        }
        temp = temp->next;
    }

    for(int i = 0; i<n; i++){
        int zbir = 0;
        PROIZVOD *tempcpy = head_proizvod;
        while(tempcpy != NULL){
            ///printf("%s, %s\n", niz_radnji[i], tempcpy->radnja);
            if(strcmp(niz_radnji[i], tempcpy->radnja) == 0){
                zbir = zbir + tempcpy->cena*tempcpy->komad;
            }
            tempcpy =tempcpy->next;
        }
        ///printf("%d ", zbir);
        if(zbir<10000) {
            head_ukupno = add_to_list_ukupno(head_ukupno, niz_radnji[i], zbir);
        }
    }

    return head_ukupno;
}

void printuj_ukupno(UKUPNO *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%s %d\n", head->radnja, head->cena);

    printuj_ukupno(head->next);
}


void menu()
{

    printf("1. Ucitavanje podataka.\n");
    printf("2. Ispisivanje podataka.\n");
    printf("3. Brisanje unosa robe.\n");
    printf("4. Ispis svih prodavnica koje na lageru imaju:\n");
    printf("5. Izlaz.\n");
}

int main()
{
    PROIZVOD *head = NULL;
    UKUPNO *head2 = NULL;

    int opcija;
    int izlaz = 0;

    int broj;

    while (1)
    {

        if (izlaz)
        {
            break;
        }

        menu();

        printf("Unesi opciju: ");
        scanf("%d", &opcija);

        switch (opcija)
        {
        case 1:
            head = ucitaj(head, "prodavnica.txt");
            break;
        case 2:
            printuj(head);
            break;
        case 3:
            printf("Unesi broj: ");
            scanf("%d", &broj);
            head = obrisi_iz_liste(head, broj);
            break;
        case 4:
            head2 = dodaj_u_listu_ukupno(head2, head);
                printuj_ukupno(head2);
            break;
        case 5:
            obrisi(head);
            izlaz = 1;
            break;
        default:
            printf("Uneli ste pogresnu opciju!\n");
            break;
        }
    }

    return 0;
}