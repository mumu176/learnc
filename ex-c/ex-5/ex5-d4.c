#include<stdio.h>
#define N 1000
int main()
{
    int n,k,i,j,flag=0;
    int num[N];
    
    scanf("%d%d",&n,&k);//读取nk
    
    for(i=0;i<n;i++)//先输入n个然后统一读取n次
    {
        scanf("%d",&num[i]);
    }
    
    for(i=0;i<n-1;i++)//双下标ij选取判断
    {
        for(j=i+1;j<n;j++)
        {
            if(num[i]+num[j]==k)
            {
                flag=1;
            }
        }
    }
    
    if(flag==1)//标记传输
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}