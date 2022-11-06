/*计算如下式子：



的值。
例如a为2，n为5，则式子的值为24690（2+22+222+2222+22222）。
【输入】
输入a和n。
【输出】
输出式子的值。
【输入示例】
2 5
【输出示例】
24690*/

#include <stdio.h>

#include <stdlib.h>

#include <math.h>



int main()

{

    int i,j,sum,a,n,ax=0;

    scanf("%d%d",&a,&n);

    for(i=0,j=1,sum=0;i<n;i++)

    {

        ax=ax+a*j;

        sum+=ax;

        j*=10;

    }

    printf("%d",sum);

    return 0;

}

