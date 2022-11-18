#include<stdio.h>

void guss(int n)
{
    if(n%2==0&&n!=1&&n!=0)
    {
        printf("%d/2=%d\n",n,n/2);
        n=n/2;
        guss(n);
    }
    else if(n%2==1&&n!=1&&n!=0)
    {
        printf("%d*3+1=%d\n",n,n*3+1);
        n=n*3+1;
        guss(n);
    }
    else if(n==1)
    printf("End");
}

int main()
{
    int num;
    scanf("%d",&num);
    guss(num);
    return 0;
}