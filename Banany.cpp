#include<iostream>
using namespace std;

void Zerowanie_Tablic(int ileWierzcholkow, int tablica[])
{
	for (int z = 0; z < ileWierzcholkow; z++)
		tablica[z] = 0;
}

void Szukanie_Ojcow_Lisci(int ileWierzcholkow, bool graf[], int ilePolaczen[], int ojcowieLisci[])
{
	for (int i = 0; i < ileWierzcholkow; i++)
	{
		if (ilePolaczen[i] == 1)
		{
			ojcowieLisci[i] = 1;
			for (int j = i * ileWierzcholkow; j < (i + 1) * ileWierzcholkow; j++)
			{
				if (graf[j] == 1)
					ojcowieLisci[j - i * ileWierzcholkow] = 2;
			}
		}
	}
	return;
}

bool Czy_Jeden_Korzen(int ileWierzcholkow, bool graf[], int ilePolaczen[], int ojcowieLisci[])
{
	int korzen = -1;

	for (int i = 0; i < ileWierzcholkow; i++)
	{
		if (ojcowieLisci[i] == 0 && korzen == -1)
			korzen = i;
		
		else if (ojcowieLisci[i] == 0 && korzen != -1)
			return false;
	}

	if (korzen == -1)
		return false;

	return true;
}

bool Czy_Te_Same_Gwiazdy(int ileWierzcholkow, bool graf[], int ilePolaczen[], int ojcowieLisci[])
{
	int stopienGwiazdy = -1;

	for (int i = 0; i < ileWierzcholkow; i++)
	{
		if (ojcowieLisci[i] == 2 && stopienGwiazdy == -1)
			stopienGwiazdy = i;

		else if (ojcowieLisci[i] == 2 && stopienGwiazdy != -1)
			if (ilePolaczen[stopienGwiazdy] != ilePolaczen[i])
				return false;
	}

	if (stopienGwiazdy == -1)
		return false;

	return true;
}

int Ile_Lisci(int ileWierzcholkow, bool graf[], int ilePolaczen[], int ojcowieLisci[])
{
	int iloscLisci = 0;

	for (int i = 0; i < ileWierzcholkow; i++)
		if (ilePolaczen[i] == 1)
			iloscLisci++;

	return iloscLisci;
}

int main() 
{
	int ileLinii;
	int	ileWierzcholkow;
	int liscie;
	bool* graf;
	int* ilePolaczen;
	int* ojcowieLisci;

	scanf_s("%d", &ileLinii);

	while (ileLinii--)
	{
		scanf_s(" %d ", &ileWierzcholkow);

		graf = new bool[ileWierzcholkow * ileWierzcholkow];

		ilePolaczen = new int[ileWierzcholkow];
		Zerowanie_Tablic(ileWierzcholkow, ilePolaczen);

		for (int i = 0; i < ileWierzcholkow * ileWierzcholkow; i++)
		{
			graf[i] = getchar() - '0';

			if (graf[i])
				ilePolaczen[i % ileWierzcholkow]++;
		}

		ojcowieLisci = new int[ileWierzcholkow];
		Zerowanie_Tablic(ileWierzcholkow, ojcowieLisci);

		Szukanie_Ojcow_Lisci(ileWierzcholkow, graf, ilePolaczen, ojcowieLisci);

		liscie = Ile_Lisci(ileWierzcholkow, graf, ilePolaczen, ojcowieLisci);

		if (liscie == ileWierzcholkow - 1)
			printf("%d bananas :)\n", liscie);

		else if (liscie == ileWierzcholkow)
			printf("2 bananas :)\n");

		else if (Czy_Jeden_Korzen(ileWierzcholkow, graf, ilePolaczen, ojcowieLisci) && Czy_Te_Same_Gwiazdy(ileWierzcholkow, graf, ilePolaczen, ojcowieLisci))
			printf("%d bananas :)\n", liscie);

		else
			printf("0 bananas :(\n");
	}

	return 0;
}