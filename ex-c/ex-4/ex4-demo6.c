/*水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身。例 如：153 = 13 + 53 + 33。 本题要求编写程序,计算所有N位水仙花数。
【输入】
输入在一行中给出一个正整数N（3≤N≤7）。
【输出】
按递增顺序输出所有N位水仙花数，每个数字占一行。
【输入示例】
3
【输出示例】
153
370
371
407*/
#include<stdio.h>
#include<math.h>
int main()
{
    int N;
    scanf("%d",&N);

    int n1,n2,n3,n4,n5,n6,n7,num;
    num=pow(10,N-1);
    n7=num/1000000;
    n6=num%1000000/100000;
    n5=num%100000/10000;
    n4=num%10000/1000;
    n3=num%1000/100;
    n2=num%100/10;
    n1=num%10;
    num=pow(10,N-1);
    while(num<pow(10,N))
    {
        if(num==pow(n7,N)+pow(n6,N)+pow(n5,N)+pow(n4,N)+pow(n3,N)+pow(n2,N)+pow(n1,N))
        {
            printf("%d\n",num);
        }
        num++;
        n7=num/1000000;
        n6=num%1000000/100000;
        n5=num%100000/10000;
        n4=num%10000/1000;
        n3=num%1000/100;
        n2=num%100/10;
        n1=num%10;
    }
    
    
    return 0;
}
