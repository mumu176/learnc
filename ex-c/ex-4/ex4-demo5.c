/*输入若干个整数，如果输入0，输入即终止。判定读入的整数中有多少个正整数、多少个负整数，并计算这些整数的总和和平均值（0不计算在内）。平均值结果保留2位小数。
【输入】
输入若干个整数，如果输入0，输入即终止。
【输出】
分行输出这些整数中的正整数个数、负整数个数、总和、平均值（0不计算在内）。
若只输入0，则输出：No input。
【输入示例】
-1 -2 -3 -4 -5 6 7 8 9 0
【输出示例】
4
5
15
1.67*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,nn=0,np=0,sum=0;
    do
    {
        scanf("%d",&num);
        sum+=num;
        if(num<0)
        nn++;
        else if(num>0)
        np++;
    } while (num!=0);
    if(nn+np==0)
    {
        printf("No input");
    }
    else
        printf("%d\n%d\n%d\n%d",np,nn,sum,sum/(nn+np));
    return 0;


}
