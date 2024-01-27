/*Napisati funkciju pom koja izračunava broj koji se dobija uklanjanjem prve i
poslednje cifre argumenta. Napraviti zbir brojeva koji se dobijaju primenom
funkcije na brojeve koje unosi korisnik ( korisnik unosi brojeve dok ne unese
nula).*/

#include <stdio.h>

int broj_cifara(int n) {
	int cifra = 0;
	while (n) {
		n = n / 10;
		cifra++;
	}
	return cifra;
}

int pom(int n) {
	int cifra, rezultat = 0, brojCifara = broj_cifara(n), brojac = 0, p = 1;
	while (n != 0) {
		cifra = n % 10;
		n = n / 10;
		brojac++;
		if (brojac == 1) continue;
		if (brojac == brojCifara) break;
		rezultat = rezultat + p * cifra;
		p = p * 10;
	}
	return rezultat;
}

int main()
{
	int x, rezultat = 0;
	do {
		scanf("%d", &x);
		rezultat = rezultat + pom(x);
	} while (x);
	printf("%d", rezultat);
	return 0;
}