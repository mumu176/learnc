#include <stdio.h>

void guess(int n)
{
    if (n % 2 == 0 && n != 1)
    {
        printf("%d/2=%d\n", n, n / 2);
        n = n / 2;
        guess(n);
    }
    else if (n % 2 == 1 && n != 1)
    {
        printf("%d*3+1=%d\n", n, n * 3 + 1);
        n = n * 3 + 1;
        guess(n);
    }
    else if (n == 1)
        printf("End\n");
}

int main()
{
    int num;
    scanf("%d", &num);
    if (num > 0)
        guess(num);
    return 0;
}