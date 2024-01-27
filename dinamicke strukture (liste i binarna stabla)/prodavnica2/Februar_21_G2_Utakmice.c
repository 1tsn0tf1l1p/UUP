#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 100

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

typedef struct Utakmica{
    char datum[12];
    char tim1;
    char tim2;
    int gol1;
    int gol2;
    struct Utakmica *sledeci;
}UTAKMICA;

typedef struct Poeni{
    char tim;
    int bodovi;
    int dati;
    int primljeni;
    struct Poeni *sledeci;
}POENI;

UTAKMICA *napravi(char *datum, char tim1, char tim2, int gol1, int gol2) {
    UTAKMICA *novi = (UTAKMICA*)malloc(sizeof(UTAKMICA));
    strcpy(novi->datum, datum);
    novi->tim1 = tim1; novi->tim2 = tim2;
    novi->gol1 = gol1; novi->gol2 = gol2;
    novi->sledeci = NULL;
    return novi;
}

POENI *kreiraj(char tim, int bodovi, int dati, int primljeni) {
    POENI *novi = (POENI*)malloc(sizeof(POENI));
    novi->tim = tim;
    novi->bodovi = bodovi;
    novi->dati = dati; novi->primljeni = primljeni;
    novi->sledeci = NULL;
    return novi;
}

UTAKMICA *ubaci(UTAKMICA *glava, char *datum, char tim1, char tim2, int gol1, int gol2) {
    UTAKMICA *novi = napravi(datum, tim1, tim2, gol1, gol2);
    if (glava == NULL) {
        glava = novi;
        return glava;
    }
    UTAKMICA *privremeni = glava;
    if (strcmp(datum, privremeni->datum) < 0) {
        novi->sledeci = privremeni;
        glava = novi;
        return glava;
    }
    while (privremeni->sledeci && strcmp(privremeni->sledeci->datum, datum) < 0) {
        privremeni = privremeni->sledeci;
    }
    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;
    return glava;
}

POENI *dodaj(POENI *glava, char tim, int bodovi, int dati, int primljeni) {
    POENI *novi = kreiraj(tim, bodovi, dati, primljeni);
    if (glava == NULL) {
        glava = novi;
        return glava;
    }
    POENI *privremeni = glava;
    if (bodovi > privremeni->bodovi || (bodovi == privremeni->bodovi && (abs(dati-primljeni) > abs(privremeni->dati-privremeni->primljeni)))) {
        novi->sledeci = privremeni;
        glava = novi;
        return glava;
    }
    while (privremeni->sledeci && ((privremeni->sledeci->bodovi > bodovi) ||
                                   (privremeni->sledeci->bodovi == bodovi && abs(privremeni->sledeci->dati-privremeni->sledeci->primljeni) >
                                   abs(dati-primljeni)))) {
        privremeni = privremeni->sledeci;
    }
    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;
    return glava;
}

void print(POENI *glava) {
    if (glava == NULL) {printf("\n"); return;}
    printf("Tim: %c|Dati: %d|Primljeni: %d|Bodovi: %d\n", glava->tim, glava->dati, glava->primljeni, glava->bodovi);
    print(glava->sledeci);
}

void printuj(UTAKMICA *glava) {
    if (glava == NULL) {printf("\n"); return;}
    printf("%s %c %c %d %d\n", glava->datum, glava->tim1, glava->tim2, glava->gol1, glava->gol2);
    printuj(glava->sledeci);
}

void meni() {
    printf("1. Ucitaj podatke\n");
    printf("2. Broj golova odredjenog tima (Iterativno)\n");
    printf("3. Broj golova odredjenog tima (Rekurzivno)\n");
    printf("4. Obracun poena i generisanje tabele\n");
    printf("7. Izlaz\n");
}

UTAKMICA *ucitaj(UTAKMICA *glava) {
    FILE *fp = fopen("utakmice.txt", "r");
    char linija[SIZE];
    while (fgets(linija, sizeof(linija), fp)) {
        if (linija[strlen(linija)-1] == '\n') linija[strlen(linija)-1] = '\0';
        char *token = strtok(linija, " ");
        int brojac = 0, gol1, gol2;
        char datum[12], tim1, tim2;
        while (token) {
            if (brojac == 0) strcpy(datum, token);
            else if (brojac == 1) tim1 = token[0];
            else if (brojac == 2) tim2 = token[0];
            else if (brojac == 3) gol1 = atoi(token);
            else if (brojac == 4) gol2 = atoi(token);
            brojac++;
            token = strtok(NULL, " ");
        }
        glava = ubaci(glava, datum, tim1, tim2, gol1, gol2);
    }
    return glava;
}

int broj_golova(UTAKMICA *glava, char tim) {
    int golovi = 0;
    UTAKMICA *privremeni = glava;
    while (privremeni) {
        if (privremeni->tim1 == tim) golovi += privremeni->gol1;
        else if (privremeni->tim2 == tim) golovi += privremeni->gol2;
        privremeni = privremeni->sledeci;
    }
    return golovi;
}

int broj_golova_rek(UTAKMICA *glava, char tim, int golovi) {
    if (glava == NULL) return golovi;
    if (glava->tim1 == tim) golovi += glava->gol1;
    else if (glava->tim2 == tim) golovi += glava->gol2;
    broj_golova_rek(glava->sledeci, tim, golovi);
}

POENI *generisi(POENI *glava1, UTAKMICA *glava2) {
    for (char i = 'a'; i <= 'z'; i++) {
        int dati = 0, primljeni = 0, bodovi = 0;
        UTAKMICA *privremeni = glava2;
        while (privremeni) {
            if (privremeni->tim1 == i) {
                dati += privremeni->gol1;
                primljeni += privremeni->gol2;
                if (privremeni->gol1 > privremeni->gol2) bodovi += 3;
                else if (privremeni->gol1 < privremeni->gol2);
                else bodovi += 1;
            }
            else if (privremeni->tim2 == i) {
                dati += privremeni->gol2;
                primljeni += privremeni->gol1;
                if (privremeni->gol2 > privremeni->gol1) bodovi += 3;
                else if (privremeni->gol2 < privremeni->gol1);
                else bodovi += 1;
            }
            privremeni = privremeni->sledeci;
        }
        if (dati != 0 && primljeni != 0 && bodovi != 0 )
            glava1 = dodaj(glava1, i, bodovi, dati, primljeni);
            //printf("Tim: %c Dati: %d Primljeni: %d Bodovi: %d\n", i, dati, primljeni, bodovi);
    }
    return glava1;
}

POENI *clear(POENI *glava) {
    POENI *privremeni = glava, *sledeci;
    while (privremeni) {
        sledeci = privremeni->sledeci;
        free(privremeni);
        privremeni = sledeci;
    }
    glava = NULL;
    return glava;
}

UTAKMICA *zbrisi(UTAKMICA *glava) {
    UTAKMICA *privremeni = glava, *sledeci;
    while (privremeni) {
        sledeci = privremeni->sledeci;
        free(privremeni);
        privremeni = sledeci;
    }
    glava = NULL;
    return glava;
}

int main()
{
    UTAKMICA *glava = NULL;
    POENI *glava2 = NULL;
    int opcija;

    while (1) {
        meni();
        printf("\nUnesite opciju: ");
        scanf("%d", &opcija);
        if (opcija == 1) {
            glava = ucitaj(glava);
            printuj(glava);
        }
        else if (opcija == 2) {
            char tim;
            printf("\nUnesite oznaku tima: ");
            scanf(" %c", &tim);
            printf("\nBroj golova: %d\n\n", broj_golova(glava, tim));
        }
        else if (opcija == 3) {
            char tim;
            printf("\nUnesite oznaku tima: ");
            scanf(" %c", &tim);
            printf("\nBroj golova: %d\n\n", broj_golova_rek(glava, tim, 0));
        }
        else if (opcija == 4) {
            glava2 = generisi(glava2, glava);
            print(glava2);
            glava2 = clear(glava2);
        }
        else if (opcija == 7) {
            glava = zbrisi(glava);
            break;
        }
    }

    return 0;
}
