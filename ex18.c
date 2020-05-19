#pragma warning(disable:4996)
#include <stdio.h>

int nrElemente()
{
	FILE *f = fopen("in.txt", "rt"); //deschiderea fisierului de intrare
	char c;
	int n = 0;
	while ((c = fgetc(f)) != '\n') //atat timp cat caracterul e diferit de sfarsit de linie
	{
		if (c == ' ') //daca caracterul este spatiu
			n++; //se numara spatiile pentru a afla cate elemente sunt
	}
	fclose(f); //inchiderea fisierului de intrare
	return n + 1; //returneaza numarul de elemente
}

int main()
{
	FILE *f = fopen("in.txt", "rt"); //deschiderea fisierului de intrare
	FILE *g = fopen("out.txt", "wt"); //deschiderea fisierului de iesire

	int v[50], l, index[50], v1[50];
	int i, j, s = 0, k = 0, n, ok = 0;

	n = nrElemente(); //n primeste valoarea numarului de elemente

	for (i = 0; i < n; i++) //se parcurge vectorul
		fscanf(f, "%d", &v[i]); //se citeste din fisierul de intrare vectorul

	fscanf(f, "%d", &l); //se citeste din fisierul de intrare numarul de indexi
	for (i = 0; i < l; i++) //se parcurge vectorul index
		fscanf(f, "%d", &index[i]); //se citeste din fisierul de intrare vectorul index

	for (i = 0; i < l; i++) //se parcurge vectorul index
	{
		s = v[index[i]];
		for (j = index[i] + 1; j < n; j++) //parcurgem vectorul de elemente
		{
			//verificam numarul de elemente consecutive crescatoare
			if (s < v[j])
			{
				k++;  //creste valoarea contorului camd acesta gaseste urmatorul element in ordine crescatoare
				s = v[j];
			}
		}
		fprintf(g, "%d\n", k); //afiseaza numarul de elemente ale secventei maximale
		k = 0; //se trece contorul pe 0 pentru a calcula urmatoarea secventa maximala
	}


	fclose(f); //inchiderea fisierului de intrare
	fclose(g); //inchiderea fisierului de iesire

	return 0;
}