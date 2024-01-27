#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

/*
(25p) Napisati program koji učitava podatke o cenama artikala iz prodavnica u uređenu listu. U fajlu se
nalazi u jednom redu naziv prodavnice i podaci o artiklu iz te prodavnice - naziv artikla i cena razdvojeni
zarezom (na primer maxi,mleko,50). Napraviti meni za interakciju preko konzole sa sledećim opcijama:
1) (6p) Učitavanje artikala - unose se naziv fajla koji sadrži cene artikala u dve prodavnice, i učitavaju se
u listu, svaki čvor sadrži naziv artikla i njegovu cenu u obe prodavnice (ako postoje), lista je sortirana
opadajuće po nazivu artikla,
2) (2p) Ispis svih artikala - ispisati artikle sortirane rastuće po nazivu artikla.
3) (8p) Prikaz najjeftinije radnje za artikle - unosi se string koji sadrži spisak artikala razdvojenih zarezom
i ispisuje se prodavnica u kojoj bi ukupna cena artikala bila najjeftinija. Ukoliko neki od unetih artikala
postoje samo u jednoj prodavnici, ispisati cenu za tu prodavnicu. Ukoliko u unetim artiklima postoji neki
artikal koji postoji samo u jednoj prodavnici, a drugi artikal koji postoji samo u drugoj prodavnici, ispisati
„Nije moguce pronaci sve artikle u jednoj prodavnici“.
4) (8p) Prikaz posebnih artikala iz radnje - unosi se radnja i ispisuju se artikli koji postoje samo u toj
radnji. Ovu funkcionalnost je potrebno implementirati i iterativno i rekurzivno.
5) (1p) Izlaz i brisanje liste.
*/

typedef struct Hrana
{

    char prodavnica[SIZE];
    char artikal[SIZE];
    int cena;
    struct Hrana *next;

} HRANA;

HRANA *create(char *prodavnica, char *artikal, int cena)
{

    HRANA *knot = (HRANA *)malloc(sizeof(HRANA));

    strcpy(knot->prodavnica, prodavnica);
    strcpy(knot->prodavnica, prodavnica);
    knot->cena = cena;
    knot->next = NULL;

    return knot;
}

HRANA *add_to_list_hrana(HRANA *head, char *prodavnica, char *artikal, int cena)
{

    HRANA *new = create(prodavnica, artikal, cena);

    if (head == NULL)
    {
        head = new;
        return head;
    }

    HRANA *temp = head;

    if (strcmp(temp->artikal, artikal) <= 0)
}

void menu()
{

    printf("1. Ucitavanje artikala\n");
    printf("2. Ispis svih artikala (sortirane rastuce po nazivu artikla)\n");
    printf("3. Prikaz najjeftinije radnje za artikle\n");
    printf("4. Prikaz posebnih artikala iz radnje (iterativno)\n");
    printf("5. Prikaz posebnih artikala iz radnje (rekurzivno)\n");
    printf("6. Izlaz\n");
}

int main()
{

    HRANA *head = NULL;

    int option;
    int izlaz = 0;

    while (1)
    {
        if (izlaz)
        {
            break;
        }

        menu();

        printf("Unesi opciju: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // zad1
            break;
        case 2:
            // zad2
            break;
        case 3:
            // zad3
            break;
        case 4:
            // zad4
            break;
        case 5:
            // zad5
            break;
        case 6:
            izlaz = 1;
            break;
        default:
            printf("Upisi validnu opciju!\n");
            break;
        }
    }

    return 0;
}