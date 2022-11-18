#include <stdio.h>
#include <stdbool.h>

int isPrime(int n)
{
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        return 0;
    }
    if(n==1)
    return 0;
    else 
    return 1;
}

int main()
{
    int i, n, m,count=0,sum=0;
    scanf("%d%d", &n, &m);
    for (i = n; i <= m; i++)
    {
        if (isPrime(i))
        {
            count++;
            sum+=i;
        }
    }
    printf("%d %d",count,sum);

    return 0;
}