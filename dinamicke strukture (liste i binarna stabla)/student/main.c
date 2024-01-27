#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

/**
Napisati program koji učitava sadržaj fajla u kom se nalaze emailovi
studenata prve godine raf-a i osvojeni poeni na kvizu. Podaci su u fajlu razdvojeni
zarezom, a email je u obliku prvo slovo imena, prezime, broj indeksa, dve cifre za
godinu upisa i smer, na primer:
agajic5718ri@raf.rs,1 - a je prvo slovo imena, gajic je prezime, broj indeksa je
57, godina upisa 18, a smer ri, osvojen 1 poen na kvizovima.
Napraviti meni za interakciju preko konzole sa sledećim opcijama:

a) (8p) učitavanje studenata i poena, unosi se naziv fajla i podaci se smeštaju
u listu uređenu prvo po smeru, zatim po godini upisa, pa po broju. Potrebno je
posebno zapamtiti prvo slovo imena, prezime, smer i broj indeksa i godinu upisa.
Nakon učitavanja treba odmah ispisati listu radi provere.

b) (8p) ukupan broj studenata sa više od unetog broja poena, unosi se
broj i program treba da prođe kroz listu i izračuna ukupan broj studenata koji su
osvojili više od unetog broja poena - ovu funkcionalnost je potrebno
implementirati na dva načina - iterativno i rekurzivno

c) (9p) ispisati sortirano po broju poena, ispisati prezime, broj indeksa, smer
i broj poena sortirano po broju poena opadajuće
**/

typedef struct Student
{

    char ime;
    char prezime[SIZE];
    int index;
    int godina;
    char smer[SIZE];
    int poeni;
    struct Student *next;

} STUDENT;

STUDENT *create_student(char ime, char *prezime, int index, int godina, char *smer, int poeni)
{

    STUDENT *new = (STUDENT *)malloc(sizeof(STUDENT));

    new->ime = ime;
    strcpy(new->prezime, prezime);
    new->index = index;
    new->godina = godina;
    strcpy(new->smer, smer);
    new->poeni = poeni;
    new->next = NULL;

    return new;
}

STUDENT *add_student_to_list(STUDENT *head, char ime, char *prezime, int index, int godina, char *smer, int poeni)
{
    STUDENT *novi = create_student(ime, prezime, index, godina, smer, poeni);

    if (head == NULL)
    {
        head = novi;
        return head;
    }

    STUDENT *temp = head;

    if (strcmp(smer, temp->smer) <= 0 && godina <= temp->godina && index < temp->index)
    {
        novi->next = temp;
        head = novi;
        return head;
    }

    while (temp->next != NULL && ((strcmp(temp->next->smer, smer) < 0) ||
                                  (strcmp(temp->next->smer, smer) >= 0 && temp->next->godina < godina) ||
                                  (strcmp(temp->next->smer, smer) >= 0 && temp->next->godina <= godina && temp->next->index < index)))
    {
        temp = temp->next;
    }

    novi->next = temp->next;
    temp->next = novi;
    return head;
}

STUDENT *read(STUDENT *head, char *fajl)
{
    FILE *fp = fopen(fajl, "r");

    if (fp == NULL)
    {
        printf("Doslo je do greske pri unosu!\n");
        return head;
    }

    char line[SIZE];
    while (fgets(line, sizeof(line), fp))
    {
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        char ime = line[0];

        char prezime[SIZE] = "";
        char smer[SIZE];
        int index;
        int godina;

        if (strstr(line, "ri@") != NULL)
        {
            strcpy(smer, "ri");
        }
        else if (strstr(line, "rn@") != NULL)
        {
            strcpy(smer, "rn");
        }
        else
        {
            strcpy(smer, "rm");
        }

        int i = 1;
        char ch[2];
        while (line[i] >= 'a' && line[i] <= 'z')
        {
            ch[0] = line[i];
            ch[1] = '\0';
            strcat(prezime, ch);
            i++;
        }
        /// Broj indeksa
        char pomocni[SIZE] = "";
        while (line[i] >= '0' && line[i] <= '9')
        {
            ch[0] = line[i];
            ch[1] = '\0';
            strcat(pomocni, ch);
            i++;
        }
        index = atoi(pomocni) / 100;
        char godina[3] = "";
        for (int i = strlen(pomocni) - 2; i < strlen(pomocni); i++)
        {
            ch[0] = pomocni[i];
            ch[1] = '\0';
            strcat(godina, ch);
        }

        godina = atoi(godina);
        int poeni = line[stlen(line) - 1] - '0';
        head = add_student_to_list(head, ime, prezime, index, godina, smer, poeni);
    }

    return head;
    fclose(fp);
}

void printuj(STUDENT *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%s %d %s %d\n", head->prezime, head->index, head->smer, head->poeni);
    printuj(head->next);
}

void meni()
{
    printf("1. Ucitaj podatke\n");
    printf("2. Ukupan broj poena (Iterativno)\n");
    printf("3. Ukupan broj poena (Rekurzivno)\n");
    printf("4. Sortirano po poenima\n");
    printf("7. Izlaz\n");
}

int main()
{

    STUDENT *head = NULL;

    int opcija;

    while (1)
    {

        meni();
        printf("Odaberite opciju: ");
        scanf("%d", &opcija);
        if (opcija == 1)
        {
            char fajl[SIZE];
            printf("\nUnesite ime fajla: ");
            scanf("%s", fajl);
            head = ucitaj(head, fajl);
            printuj(head);
        }
        else if (opcija == 2)
        {
        }
        else if (opcija == 3)
        {
        }
        else if (opcija == 4)
        {
        }
        else if (opcija == 7)
            break;
    }

    return 0;
}
