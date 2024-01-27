/**
Napraviti meni za interakciju preko konzole i implementirati sledeće opcije:

a) (10p) učitavanje podataka, podaci o ocenama učitavaju se u listu tako da jedan
element liste sadrži podatke iz jednog reda u fajlu (radi bržeg testiranja naziv fajla se
može staviti direktno u programu, ne mora se učitavati).
Lista treba da bude sortirana rastuće po rednom broju učenika a zatim za svakog učenika
opadajuće po datumu (od najskorije do najdavnije unete ocene). Funkcionalnost učitavanja je potrebno
implementirati na dva načina, iterativno i rekurzivno. Nakon učitavanja ispisati listu.

b) (4p) brisanje svih ocena za datum, unosi se datum i potrebno je obrisati iz liste sve
ocene unete tog datuma, posle izvršene operacije brisanja ispisati listu.

c) (10p) zaključivanje ocena, osmisliti odgovarajuću strukuturu i u nju prepisati sve
potrebne podatke, tako da se za svakog učenika može za svaki predmet zaključiti ocena
(na osnovu proseka svih ocena na predmetu, ako je prosek 4.5 i više zaključuje se 5, ako
je 3.5-4.49 4, itd), ispisati za svakog učenika prvo njegov redni broj, zatim zaključene
ocene po predmetima i na kraju ukupnu prosečnu ocenu (opšti uspeh).

d) (1p) izlaz iz programa i brisanje svih struktura.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 250

typedef struct Ocene
{

    int ucenik;
    char predmet[SIZE];
    int ocena;
    char datum[SIZE];
    struct Ocene *next;

} OCENE;

OCENE *create_list_item_ocene(int ucenik, char *predmet, int ocena, char *datum)
{

    OCENE *novi = (OCENE *)malloc(sizeof(OCENE));

    novi->ucenik = ucenik;
    strcpy(novi->predmet, predmet);
    novi->ocena = ocena;
    strcpy(novi->datum, datum);
    novi->next = NULL;

    return novi;
}

OCENE *add_item_to_list_ocene(OCENE *head, int ucenik, char *predmet, int ocena, char *datum)
{

    OCENE *novi = create_list_item_ocene(ucenik, predmet, ocena, datum);

    if (head == NULL)
    {
        head = novi;
        return head;
    }

    OCENE *temp = head;

    if (temp->ucenik > ucenik || (temp->ucenik == ucenik && strcmp(temp->datum, datum) >= 0))
    {
        novi->next = temp->next;
        head = novi;
        return head;
    }

    while (temp->next != NULL && (temp->next->ucenik < ucenik || (temp->next->ucenik == ucenik && strcmp(temp->next->datum, datum) < 0)))
    {
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;
}

OCENE *ucitaj(OCENE *head)
{

    FILE *fp = fopen("zad.txt", "r");

    if (fp == NULL)
    {
        printf("Ucitavanje neuspesno.\n");
    }
    else
    {
        printf("Ucitavanje je uspelo.\n");
    }

    char line[SIZE];

    while (fgets(line, SIZE, fp))
    {
        if(line[strlen(line) - 1] == '\n'){
            line[strlen(line) - 1] = '\0';
        }

        int brojac = 0;

        int ucenik;
        char predmet[SIZE];
        int ocena;
        char datum[SIZE];

        char *token = strtok(line, " ");

        while (token)
        {
            if (brojac == 0)
            {
                ucenik = atoi(token);
            }
            else if (brojac == 1)
            {
                strcpy(predmet, token);
            }
            else if (brojac == 2)
            {
                ocena = atoi(token);
            }
            else if (brojac == 3)
            {
                strcpy(datum, token);
            }

            brojac++;

            token = strtok(NULL, " ");
        }

        head = add_item_to_list_ocene(head, ucenik, predmet, ocena, datum);
    }

    fclose(fp);
    return head;
}

void printuj_ocene(OCENE *head)
{

    if (head == NULL)
    {
        return;
    }

    printf("%d %s %d %s\n", head->ucenik, head->predmet, head->ocena, head->datum);

    printuj_ocene(head->next);
}

void menu()
{

    printf("1. Ucitavanje podataka i printovanje podataka.\n");
    printf("2. Brisanje svih ocena za datum.\n");
    printf("3. Zakljucivanje ocena.\n");
    printf("4. Izlaz.\n");
}

int main()
{

    OCENE *head = NULL;

    int opcija;
    int izlaz = 0;

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
            head = ucitaj(head);
            printuj_ocene(head);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            izlaz = 1;
            break;
        default:
            printf("Uneli ste pogresnu opciju!\n");
            break;
        }
    }

    return 0;
}