#include <stdio.h>
#define N 100
int main()
{
    int n,i,flag=0;
    int num[N];
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);//先输入n个然后统一读取n次
    }

    for(i=0;i<n;i++)
    {
        if(num[i]==i)
        {
            printf("%d",num[i]);
            flag=1;
            break;
        }
    }
    if(flag==0)
    printf("No");
    return 0;
}