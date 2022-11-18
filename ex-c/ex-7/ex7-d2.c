#include <stdio.h>
#include <stdbool.h>

bool wanshu(int num)
{
    int j, sum = 0;
    for (j = 1; j < num; j++)
    {
        if (num % j == 0)
            sum += j;
    }
    if (num == sum)
        return true;
    else
        return false;
}

int main()
{
    int i, n, m;
    scanf("%d%d", &n, &m);
    for (i = n; i <= m; i++)
    {
        if (wanshu(i))
            printf("%d ", i);
    }

    return 0;
}