#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

/*Napraviti meni za interakciju preko konzole i implementirati sledeće opcije:

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

typedef struct Ocene
{

    int broj;
    char predmet[SIZE];
    int ocena;
    char datum[SIZE];
    struct Ocene *next;

} OCENE;

OCENE *create(int broj, char *predmet, int ocena, char *datum)
{

    OCENE *novi = (OCENE *)malloc(sizeof(OCENE));

    novi->broj = broj;
    strcpy(novi->predmet, predmet);
    novi->ocena = ocena;
    strcpy(novi->datum, datum);
    novi->next = NULL;

    return novi;
}

OCENE *add_to_list(OCENE *head, int broj, char *predmet, int ocena, char *datum)
{

    OCENE *novi = create(broj, predmet, ocena, datum);

    if (head == NULL)
    {
        head = novi;
        return head;
    }

    OCENE *temp = head;

    if (broj < temp->broj || (broj == temp->broj && strcmp(datum, temp->datum) > 0))
    {
        novi->next = temp;
        head = novi;
        return head;
    }

    while (temp->next != NULL && ((temp->next->broj > 0) ||
                                  ((temp->next->broj == broj && strcmp(temp->datum, datum) < 0))))
    {
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;
}

OCENE *ucitaj(OCENE *head)
{

    FILE *fp = fopen("ocene1.txt", "r");

    if (fp == NULL)
    {
        printf("Ucitavanje nije uspelo!\n");
    }

    char line[SIZE];

    while (fgets(line, SIZE, fp))
    {
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        char *token = strtok(line, " ");

        int brojac = 0;
        int broj;
        int ocena;
        char predmet[SIZE];
        char datum[SIZE];

        while (token)
        {
            if (brojac == 0)
            {
                broj = atoi(token);
            }
            else if (brojac == 1)
            {
            }
        }
    }
}

void menu()
{

    printf("1. Ucitavanje podataka.\n");
    printf("2. Printovanje podataka\n");
    printf("3. Brisanje svih ocena za datum.\n");
    printf("4. Zakljucivanje ocena.\n");
    printf("5. Izlaz.\n");
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            izlaz = 1;
            break;
        default:
            printf("Uneli ste nepostojecu opciju!\n");
            break;
        }
    }

    return 0;
}