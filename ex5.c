#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int v[1000], n;

void citire() //functie pentru citirea datelor din fisier
{
	FILE *f = fopen("swp.in.txt", "rt");  //deschiderea fisierului de intrare pentru scriere
	int i;
	char c = ' ';
	fscanf(f, "%d", &n); // se citeste numarul de biti
	fscanf(f, "%c", &c); // se citeste sfarsitul de linie
	for (i = 0; i < n; i++) //se parcurge vectorul
	{
		fscanf(f, "%c", &c); // se citeste bitul in format char
		v[i] = c - '0'; // se converteste char in int si se adauga la vectorul de biti
	}
	fclose(f); //inchiderea fiserului de intrare
}

void afisare(int *swaps[500][2], int n) //functie pentru scrierea in fisier
{
	FILE *g = fopen("swp.out.txt", "wt"); //deschiderea fisierului de iesire pentru scriere
	int i;
	fprintf(g, "%d\n", n); //se scrie numarul de interschimbari
	for (i = 0; i < n; i++) //se parcurge vectorul
		fprintf(g, "%d  %d\n", swaps[i][1], swaps[i][0]); //se scrie in fisier pozitiile elementelor ce s-au schimbat
	fclose(g); //inchiderea fisierului de iesire
}

void swap()
{
	int i, k = 0, j = 0, swaps[500][2];
	for (i = 0; i < n; i++) // se parcurge vectorul pentru a afla numarul de biti cu valoarea 1
		if (v[i] == 1) //daca are valoarea 1
			k++; //creste pozitia
	for (i = n - 1; i >= n - k; i--) // se parcurge ultimele k pozitii pentru a determina unde lipseste bitul cu val 1
		if (v[i] == 0) //daca valoarea este 0
			swaps[j++][0] = i + 1; // se salveaza indicile bitului
	j = 0;
	for (i = 0; i < n - k; i++) // se parcurge primele n - k pozitii pentru a determina bitii cu val 1
		if (v[i] == 1)
			swaps[j++][1] = i + 1; // se salveaza indicile bitului
	afisare(&swaps, j); //se apeleaza functia 
}

int main()
{
	citire();
	swap();
	return 0;
}