/*计算正整数m 到 n（包括m和n）之间的所有奇数的和，m<n<300。
【输入】
输入两个正整数m 和 n，两个正整数以空格间隔。
【输出】
输出m到 n（包括m和 n ）之间的所有奇数的和。
【输入示例】
3 12
【输出示例】
35*/
#include <stdio.h>

#include <stdlib.h>

#include <math.h>



int main()

{

    int sum=0,m,n,p;

    scanf("%d%d",&m,&n);

    if(m%2==0){

        p=m+1;

        while(p<=n)

        {

            sum+=p;

            p+=2;

        }

    }

    else{

        p=m;

        while(p<=n)

        {

            sum+=p;

            p+=2;

        }

    }

    printf("%d",sum);

    return 0;

}

