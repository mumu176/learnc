#include <stdio.h>
#include <math.h>

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

int isPalindrome(int n)
{
    if (n == reverse(n))
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (isPalindrome(n))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return 0;
}