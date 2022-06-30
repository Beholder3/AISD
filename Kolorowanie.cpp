#include <stdio.h>
using namespace std;

int Stopien_Wierzcholka(int numerWierzcholka, int iloscWierzcholkow, bool graf[])
	int stopienWierzcholka = 0;
	for (int i = numerWierzcholka * iloscWierzcholkow; i < (numerWierzcholka + 1) * iloscWierzcholkow; i++)
		if (graf[i])
			stopienWierzcholka++;
		
	return stopienWierzcholka;
}

bool Stopien_Wszystkich_Wierzcholkow(int stopien, int iloscWierzcholkow,bool graf[])
	for (int i = 0; i < iloscWierzcholkow; i++)
		if (!(Stopien_Wierzcholka(i, iloscWierzcholkow, graf) == stopien))
			return false;
		
	return true;
}

bool Pelnosc(int iloscWierzcholkow, bool graf[]) 
{
	if (Stopien_Wszystkich_Wierzcholkow(iloscWierzcholkow - 1, iloscWierzcholkow, graf))
		return true;

	else
		return false;
}

bool Cykl(int iloscWierzcholkow, bool graf[]) 
{
	if (Stopien_Wszystkich_Wierzcholkow(2, iloscWierzcholkow, graf))
		return true;
		
	else 
		return false;
}

bool Nieparzysta_Dlugosc(int numerWierzcholka, int iloscWierzcholkow, bool graf[]) 
{
	if (Cykl(iloscWierzcholkow, graf) == true && numerWierzcholka % 2 == 1)
		return true;
		
	return false;
}

int main() {

	int iloscLinii;
	int iloscWierzcholkow;
	bool* graf;

	scanf_s("%d", &iloscLinii);

	for (int i = 0; i < iloscLinii; i++) 
	{
		scanf_s(" %d ", &iloscWierzcholkow);

		graf = new bool[iloscWierzcholkow * iloscWierzcholkow];

		for (int j = 0; j < iloscWierzcholkow * iloscWierzcholkow; j++)
			graf[j] = getchar()-'0';

		if (Nieparzysta_Dlugosc(iloscWierzcholkow, iloscWierzcholkow, graf) == true || Pelnosc(iloscWierzcholkow, graf) == true)
			printf("True\n");
		
		else 
			printf("False\n");
	}
	return 0;
}
