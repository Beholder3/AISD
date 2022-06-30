#include <iostream>
using namespace std;

void zerowanie_tablicy(int tab[]) // funkcja wypelniajaca tablice 0
{
    for (int i = 0; i < 100; i++)
        tab[i] = 0;
}

void tablica_pierwszych(int tab[]) // wypelnia tablice liczbami pierwszymi
{
    int q = 1;
    tab[0] = 2;
    for (int i = 2; i < 256; i++)
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
            else if (i == j + 1)
            {
                tab[q] = i;
                q++;
            }
        }
}

int czy_k_pierwsza(int k, int tablica_pierwszych[]) // funkcja sprawdzajaca czy podana liczba jest pierwsza
{
    for (int i = 0; i < 100; i++)
    {
        if (k == tablica_pierwszych[i])
            return 1;
        if (k < tablica_pierwszych[i])
            return 0;
    }
    return 0;
}

void tablica_maxa(int tab[], int tab_pierwszych[], int n, int k, int miejsce) // wypelnia tablice maksymalna iloscia wystapien liczby 
{
    int max = n - k;

    for (int i = 0; i <= miejsce; i++)
    {
        tab[i] = max / tab_pierwszych[i];
    }

}

int mniejsze_rowne(int tab[], int k, int n) // zwraca miejsce w tablicy z ostatnia liczba mniejsza badz rowna od podanej
{
    int szukane = k;

    if (n - k < k)
        szukane = n - k;

    for (int i = 0; i < 54; i++)
    {
        if (tab[i] > szukane)
            return i - 1;
    }
    return 0;
}

void sprawdzanie_czy_suma(int n, int k, int wyniki[], int tablica_liczb_pierwszych[], int w) // funkcja sprawdzajaca czy suma liczb rowna jest n-k jesli tak to cout tablice wyniki tyle razy ile ...
{
    int suma = 0;
    for (int i = 0; i <= w; i++)
        suma += (wyniki[i] * tablica_liczb_pierwszych[i]);

    if (suma == n - k)
    {
        cout << k;
        for (int i = w; i >= 0; i--)
        {
            for (int j = 0; j < wyniki[i]; j++)
                cout << "+" << tablica_liczb_pierwszych[i];
        }
        cout << endl;
    }
}

void podzialy(int n, int k, int wyniki[], int tablica_max[], int w, int tablica_liczb_pierwszych[])
{
    wyniki[0]++;
    int ile_razy = 1;
    for (int i = 0; i <= w; i++)
    {
        ile_razy *= (tablica_max[i] + 1);
    }
    for (int az = 0; az < ile_razy; az++)
    {
        for (int i = 0; i <= w; i++)
        {
            if (wyniki[i] == tablica_max[i] + 1)
            {
                wyniki[i] = 0;
                wyniki[i + 1]++;
            }
        }
        sprawdzanie_czy_suma(n, k, wyniki, tablica_liczb_pierwszych, w);
        wyniki[0]++;
    }
}

int tablica_liczb_pierwszych[100];
int wyniki[100];
int tablica_max[100];

int main()
{
    int liczba_lini, n, k;

    tablica_pierwszych(tablica_liczb_pierwszych);

    cin >> liczba_lini;

    for (int i = 0; i < liczba_lini; i++)
    {
        cin >> n >> k;
        if (czy_k_pierwsza(k, tablica_liczb_pierwszych) == 1)
        {
            int w = mniejsze_rowne(tablica_liczb_pierwszych, k, n);

            tablica_maxa(tablica_max, tablica_liczb_pierwszych, n, k, w);

            podzialy(n, k, wyniki, tablica_max, w, tablica_liczb_pierwszych);

            zerowanie_tablicy(wyniki);
        }
    }

    return 0;
}