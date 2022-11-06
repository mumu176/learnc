/*有一个分数序列：2/1、3/2、5/3、8/5、13/8、21/13、.... 求这个分数序列的前n项之和。
【输入】
输入一个正整数n。
【输出】
输出分数序列的和，结果保留4位小数。
【输入示例】
99
【输出示例】
160.4849
【提示】
在程序中使用双精度浮点类型（double）变量来记录分子、分母以及和。*/
#include <stdio.h>

#include <stdlib.h>

#include <math.h>



int main()

{

    int i,n;

    double a=1,b=2,t,sum=0;

    double f1;



    scanf("%d",&n);



    for(i=1;i<=n;i++)

    {



        f1=b/a;

        sum+=f1;

        t=a;

        a=b;

        b=b+t;



    }



    printf("%.4lf",sum);





    return 0;

}

