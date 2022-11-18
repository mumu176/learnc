#include <stdio.h>

long sequence(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return (sequence(n - 1) + sequence(n - 2) + sequence(n - 3));
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("%6d", sequence(i));
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
    return 0;
}