/*编写程序验证下列结论：任何一个自然数n的立方都等于n个连续奇数之和。例如：

要求程序对每个输入的自然数计算并输出相应的连续奇数。
【输入】
输入自然数n为整数。
【输出】
输出n个连续奇数之和，格式如【输出示例】显示。
【输入示例】
5
【输出示例】
5*5*5=125=21+23+25+27+29*/
#include<stdio.h>
int main()
{
    int n,flag;
    scanf("%d", &n);
    flag=(n*n)%2;
    if(flag==1)
    {
        int i,j;
        j=n*n-(n-1);
        printf("%d*%d*%d=%d=%d",n,n,n,n*n*n,j);
        j+=2;
        for(i=0;i<n-1;i++)
        {
            printf("+%d",j);
            j+=2;
        }
    }
    if(flag==0)
    {
        int i,j;
        j=n*n+1-n;
        printf("%d*%d*%d=%d=%d",n,n,n,n*n*n,j);
        j+=2;
        for(i=0;i<n-1;i++)
        {
            printf("+%d",j);
            j+=2;
        }
    }
}