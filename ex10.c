#pragma warning(disable:4996)
#include<stdio.h>

int ct = 0;

int afisare(unsigned long  N, unsigned long  Z, FILE* g) //functia pentru determinarea numerelor naturale Z care satisfac relatia ( N xor Z) > N si contorizarea lor
{
	if (Z < N)
	{
		if ((N^Z) > N)
		{
			fprintf(g, "%lu ", Z); //afiseaza in fisierul de iesire numerele care corespund conditiei
			ct++;  //contorizeaza numerele care satisfac conditia de xor > N
			return afisare(N, Z + 1, g); // returneaza/apeleaza functia de urmator
		}
		else return afisare(N, Z + 1, g);
	}
	else
		return 0; 
}

int main()
{
	
	unsigned long  Z = 0, N, XOR;
	FILE *f = fopen("in.txt", "rt"); //deschiderea fisierului de intrare pentru scriere
	FILE *g = fopen("out.txt", "wt");//deschiderea fisierului de iesire

	fscanf(f, "%lu", &N); //se citeste din fisierul de intrare numarul natural
	fprintf(g, "Numerele sunt: ");

	XOR = afisare(N, Z, g); //se apeleaza functia pentru a afisa rezultatele in fisierul de iesire

	fprintf(g, "\nNumarul de numere care corespund operatiei xor este: %d", ct); //se afiseaza in fisierul de iesire numarul numerelor contorizare

	fclose(f);//inchiderea fisierului de intrare
	fclose(g);//inchiderea fisierului de iesire

	return 0;
}
