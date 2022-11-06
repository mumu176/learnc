/*如果一个整数逆序后得到的数值和原数值相同，则称之为幸运数。输入一个整数N（N＜10000）判断是否为幸运数，是的话输出“yes”，否则输出“no”。
【输入】
输入一个整数。
【输出】
输出为字符串。
【输入示例】
1234
【输出示例】
no*/
#include<stdio.h>
int main()
{
    int n1,n2,n3,n4,N,nx;
    scanf("%d",&N);
    n4=N/1000;
    n3=N%1000/100;
    n2=N%100/10;
    n1=N%10;
    if(n4==0&&n3!=0)
    nx=n1*100+n2*10+n3;
    else if(n4!=0)
    nx=n1*1000+n2*100+n3*10+n4;
    if(nx==N||n1==n2)
    printf("yes");
    else
    printf("no");
    return 0;
}