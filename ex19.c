#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int a[50][50], n, maxim = 0, sum = 0;

int suma(int l, int c, int a[50][50], int sum) //functia pentru aflarea sumei maxime
{
	sum = sum + a[l][c];//calculeaza suma
	if (sum > maxim)//daca suma este mai mare decat maximul, maximul ia valoarea sumei
		maxim = sum;
	if (l == n)//daca linia curenta este egala cu numarul total de linii
	{
		return maxim;//afiseaza maximul obtinut
	}
	l++; //trece la urmatoarea linie
	if (c > 0)//daca indicele coloanei e mai mare decat 0
		suma(l , c - 1, a, sum);//apelam functia de linie si coloana anterioara
	suma(l, c, a, sum);//apelam functia de linie si aceeasi coloana
	suma(l, c + 1, a, sum);//apelam functia de linie si coloana din dreapta
}

int citire()
{
	FILE* f = fopen("in.txt", "rt");//deschiderea fisierului de intrare
	int l = 1, c = 0;

		while (fscanf(f, "%d", &a[l - 1][c]) != EOF) //cat timp matricea citita difera de sfarsitul fisieului
		{
			c++; //creste numarul coloanei
			if (c == l) //daca coloana este egala cu linia se trece la linia urmatoare,pana se citesc toate elemnentele matriciei
			{
				l++; //trecem la urmatoarea linie
				c = 0; //se reia coloana de la 0
			}
		}

	fclose(f); //inchiderea fisierului de intrare
	return l - 2; //returneaza numarul de linii(l-2 deoarece incepe de la 1)
}

int main()
{
	FILE *g = fopen("out.txt", "w"); //deschiderea fisieului de iesire

	n = citire();//in variabila n se retine numarul de linii
	maxim = suma(0, 0, a, sum);//se apeleaza functia de maxim incepand de la linia 0 si coloana 0
	fprintf(g, "%d ", maxim); //afisarea sumei maxime obtinute din varf pana la baza
	
	fclose(g); //inchoderea fisirului de iesire
	return 0;
}