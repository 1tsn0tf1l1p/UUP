#include <stdio.h>
#include <stdlib.h>

int reverse(int n) {
	int cifra, reversed = 0;
	while (n) {
		cifra = n % 10;
		n = n / 10;
		reversed = reversed * 10 + cifra;
	}
	return reversed;
}

int test(int n) {
	if (n > 0 && n < 100) return 1;
	int reversed = reverse(n), c1, c2, brojac = 0;
	while (n != 0) {
		if (brojac == 2) return 1;
		c1 = n % 10;
		c2 = reversed % 10;
		n /= 10;
		reversed /= 10;
		brojac++;
		if (c2 > c1) continue;
		else return 0;
	}
}

int main()
{
	int x, rezultat = 0;
	do {
		scanf("%d", &x);
		if (test(x) == 1) rezultat = rezultat + x;
	} while (test(x) != 0);
	printf("%d", rezultat);
	return 0;
}