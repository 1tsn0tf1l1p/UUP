#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

/*
Napisati program koji učitava podatke o broju rođenih beba po datumima u jednom gradu i
smešta ih u listu. Podaci se u fajlu nalaze u obliku: dan mesec godina broj beba, svi podaci su
razdvojeni spejsom. Primer: 23 2 2018 12 (23. februara 2018. rođeno je 12 beba).
Napraviti meni za interakciju preko konzole sa slededim opcijama.

a) (7p) učitavanje podataka, unosi se naziv fajla koji sadrži opisane podatke i učitava se u listu
uređenu nerastude po broju rođenih beba,

b) (8p) ispis broja rođenih beba u jednoj godini, unosi se godina i treba ispisati broj rođenih u toj
godini, ovu funkcionalnost je potrebno implementirati na dva načina, iterativno i rekurzivno,

c) (10p) ispis broja rođenih beba po mesecima sortirano rastude po godini i mesecu, posmatra se
broj rođenih beba u konkretnom mesecu (na primer 2.2018.) i ispisuje se mesec, godina i broj
rođenih u tom mesecu, sortirano rastude po mesecu (dozvoljeno je praviti nove strukture podataka).
*/

typedef struct Beba
{

    int dan;
    int mesec;
    int godina;
    int broj_beba;
    struct Beba *next;

} BEBA;

typedef struct Mesec
{
    int mesec;
    int godina;
    int broj_beba;
    struct Mesec *next;

} MESEC;

BEBA *create(int dan, int mesec, int godina, int broj_beba)
{
    BEBA *new_node = (BEBA *)malloc(sizeof(BEBA));
    new_node->dan = dan;
    new_node->mesec = mesec;
    new_node->godina = godina;
    new_node->broj_beba = broj_beba;
    new_node->next = NULL;

    return new_node;
}

MESEC *create_mesec(int mesec, int godina, int broj_beba)
{
    MESEC *new_node = (MESEC *)malloc(sizeof(MESEC));
    new_node->mesec = mesec;
    new_node->godina = godina;
    new_node->broj_beba = broj_beba;
    new_node->next = NULL;

    return new_node;
}

BEBA *add_to_list(BEBA *head, int dan, int mesec, int godina, int broj_beba)
{
    BEBA *new = create(dan, mesec, godina, broj_beba);
    if (head == NULL)
    {
        head = new;
        return head;
    }
    BEBA *temp = head;
    if (broj_beba >= temp->broj_beba)
    {
        new->next = temp;
        head = new;
        return head;
    }
    while (temp->next != NULL && broj_beba < temp->next->broj_beba)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    return head;
}

MESEC *add_to_list_mesec(MESEC *head, int mesec, int godina, int broj_beba)
{

    MESEC *novi = create_mesec(mesec, godina, broj_beba);

    if (head == NULL)
    {
        head = novi;
        return head;
    }

    MESEC *temp = head;

    if (novi->godina <= temp->godina && novi->mesec <= temp->mesec)
    {
        novi->next = temp;
        head = novi;
        return head;
    }

    while (temp->next != NULL && ((novi->godina > temp->next->godina) || (novi->godina == temp->next->godina && novi->mesec > temp->next->mesec)))
    {
        temp = temp->next;
    }
    novi->next = temp->next;
    temp->next = novi;
    return head;
}

void ispisiMesece(MESEC *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d %d %d\n", head->mesec, head->godina, head->broj_beba);
    ispisiMesece(head->next);
}

BEBA *insert_data(BEBA *head, char *f)
{

    FILE *fp = fopen(f, "r");

    if (fp == NULL)
    {
        printf("Ucitavanje neuspesno!\n");
    }

    char line[SIZE];

    while (fgets(line, sizeof(line), fp))
    {
        char *token = strtok(line, " ");

        int dan, mesec, godina, broj_beba;
        int brojac = 0;

        while (token)
        {
            if (brojac == 0)
            {
                dan = atoi(token);
            }
            else if (brojac == 1)
            {
                mesec = atoi(token);
            }
            else if (brojac == 2)
            {
                godina = atoi(token);
            }
            else if (brojac == 3)
            {
                broj_beba = atoi(token);
            }
            brojac++;
            token = strtok(NULL, " ");
        }

        head = add_to_list(head, dan, mesec, godina, broj_beba);
    }

    printf("Ucitavanje je uspesno izvrseno!\n");
    fclose(fp);
    return head;
}

MESEC *napuniMesece(BEBA *head1, MESEC *head2)
{
    for (int i = 2010; i <= 2020; i++)
    {
        for (int j = 1; j < 12; j++)
        {
            int ukupno = 0;
            BEBA *tmp = head1;
            while (tmp != NULL)
            {
                if (tmp->godina == i && tmp->mesec == j)
                {
                    ukupno += tmp->broj_beba;
                }
                tmp = tmp->next;
            }
            if (ukupno != 0)
            {
                head2 = add_to_list_mesec(head2, j, i, ukupno);
            }
        }
    }
    return head2;
}

void print_list(BEBA *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d %d %d %d\n", head->dan, head->mesec, head->godina, head->broj_beba);
    print_list(head->next);
}

int broj_rodjenih_iter(BEBA *head, int godina)
{
    int ukupno = 0;

    BEBA *temp = head;
    while (temp != NULL)
    {
        if (temp->godina == godina)
        {
            ukupno = ukupno + temp->broj_beba;
        }
        temp = temp->next;
    }

    return ukupno;
}

int broj_rodjenih_rek(BEBA *head, int godina, int zbir)
{

    if (head == NULL)
    {
        return zbir;
    }

    if (head->godina == godina)
    {
        zbir += head->broj_beba;
    }

    broj_rodjenih_rek(head->next, godina, zbir);
}

void menu()
{
    printf("1. Ucitaj podatke\n");
    printf("2. Ispisi podatke\n");
    printf("3. Broj rodjenih beba u godini (Iterativno)\n");
    printf("4. Broj rodjenih beba u godini (Rekurzivno)\n");
    printf("5. Generisi broj rodjenih beba\n");
    printf("7. Izlaz\n");
}

int main()
{

    BEBA *head = NULL;
    MESEC *head2 = NULL;

    int option;
    int izlaz = 0;

    while (1)
    {
        if (izlaz)
        {
            break;
        }

        menu();
        printf("Unesi opciju:\n");
        scanf("%d", &option);

        switch (option)
        {

        case 1:
            printf("Unesite naziv fajla:\n");
            char f[SIZE];
            scanf("%s", f);
            head = insert_data(head, f);
            break;

        case 2:
            print_list(head);
            break;
        case 3:
            printf("Unesi godinu: \n");
            int godina1;
            scanf("%d", &godina1);
            int ukupno1 = broj_rodjenih_iter(head, godina1);
            printf("%d\n", ukupno1);
            break;
        case 4:
            printf("Unesi godinu: \n");
            int godina2;
            scanf("%d", &godina2);
            int ukupno2 = broj_rodjenih_iter(head, godina2);
            printf("%d\n", ukupno2);
            break;
        case 5:
            head2 = napuniMesece(head, head2);
            ispisiMesece(head2);
            break;
        default:
            izlaz = 1;
            break;
        }
    }

    return 0;
}