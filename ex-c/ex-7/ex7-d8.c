#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    if (n == 1)
        return 0;
    else
        return 1;
}

int reverse(int n)
{
    int i, j, sum = 0;
    int nn[7];
    nn[6] = 0;
    nn[5] = n / 100000;
    nn[4] = n / 10000 % 10;
    nn[3] = n / 1000 % 10;
    nn[2] = n / 100 % 10;
    nn[1] = n / 10 % 10;
    nn[0] = n % 10;
    for (i = 6;; i--)
    {
        if (nn[i - 1] != 0)
            break;
    }

    for (j = 0; j < 6 && i - j - 1 != -1; j++)
    {
        sum += nn[j] * pow(10.0, i - j - 1);
    }
    return sum;
}

int main()
{
    int i, n, count = 0;
    scanf("%d", &n);
    for (i = 2;; i++)
    {
        if (isPrime(i) && isPrime(reverse(i)))
        {
            count++;
            printf("%5d", i);
            if (count % 5 == 0)
                printf("\n");
        }

        if (count == n)
            break;
    }
    return 0;
}