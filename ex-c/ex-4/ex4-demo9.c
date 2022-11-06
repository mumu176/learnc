/*计算如下式子：
1+(1+2)+(1+2+3)+(1+2+3+4)+…
的前n项之和。
【输入】
输入一个正整数n。
【输出】
输出数列前n项的和。
【输入示例】
3
【输出示例】
10*/
#include<stdio.h>
int main()
{
    int n,i,j,sum=0,sumx=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for (j = 1; j <= i; j++)
        {
            sumx+=j;
        }
        sum+=sumx;
        sumx=0;
    }
    printf("%d",sum);
    return 0;
}