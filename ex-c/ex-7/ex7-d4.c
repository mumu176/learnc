#include <stdio.h>

int gcd(int m, int n)
{
    int i, t;
    if (n < m)
    {
        t = m;
        m = n;
        n = t;
    }
    for (i = m; i >= 1; i--)
    {
        if (n % i == 0 && m % i == 0)
            break;
    }
    return i;
}

int main()
{
    int m, n;
    scanf("%d/%d", &m, &n);
    printf("%d/%d", m / gcd(m, n), n / gcd(m, n));
    return 0;
}