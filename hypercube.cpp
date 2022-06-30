#include <stdio.h>

unsigned long long Potega2(int n)
{
    unsigned long long pow = 1;
    for(int i = 0; i < n; i++)
    pow = pow << 1;
    return pow;
}

unsigned long long Dwumian_Newtona(int n, int k)
{
    unsigned long long s = 1;
    if (k >= n - k)
    {
        for (int i = k + 1; i <= n; i++)
            s *= i;
        for (int i = 2; i <= n - k; i++)
            s /= i;
    }
    else
    {
        for (int i = n - k + 1; i <= n; i++)
            s *= i;
        for (int i = 2; i <= k; i++)
            s /= i;
    }
    
    return s;
}

int main()
{
    int iloscLini;
    int n, d;
    scanf("%i", &iloscLini);
    while(iloscLini--)
    {
        scanf("%i", &n);
        scanf("%i", &d);

        if (d > n)
            printf("%i \n", 0);

        else if (d == n)
            printf("%llu \n", Potega2(n - 1));

        else
            printf("%llu \n", (Potega2(n - 1) * Dwumian_Newtona(n, d)));
    }
    return 0;
}
