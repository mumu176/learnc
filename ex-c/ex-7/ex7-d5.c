#include <stdio.h>

void guess(long long int n)
{
    if (n % 2 == 0 && n != 1)
    {
        printf("%lld/2=%lld\n", n, n / 2);
        n = n / 2;
        guess(n);
    }
    else if (n % 2 == 1 && n != 1)
    {
        printf("%lld*3+1=%lld\n", n, n * 3 + 1);
        n = n * 3 + 1;
        guess(n);
    }
    else if (n == 1)
        printf("End");
}

int main()
{
    long long int num;
    scanf("%lld", &num);
    if (num > 0)
        guess(num);
    return 0;
}