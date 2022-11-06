/*输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出“fu”字。十个数字对应的拼音如下：
0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
【输入】
输入在一行中给出一个整数，如：1234。
【输出】
在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如yi er san si。
【输入示例】
-600
【输出示例】
fu liu ling ling*/
#include <stdio.h>

#include <stdlib.h>

#include <math.h>



int main()

{

    int num,nx,a,n=1,i,j=1,m;



    scanf("%d",&num);



    a=num;

    if(a<0)

    {

        printf("fu ");

        a=-a;

        num=a;

    }





    //

    while(a)

    {

        a/=10;

        if(a>0){n++;}



    }



    for(m=1;m<n;m++,j*=10){;}

    for(i=0;i<n;i++,j/=10)

    {



        nx=num/j;

        num-=nx*j;

        switch(nx){

        case 0:printf("ling");break;

        case 1:printf("yi");break;

        case 2:printf("er");break;

        case 3:printf("san");break;

        case 4:printf("si");break;

        case 5:printf("wu");break;

        case 6:printf("liu");break;

        case 7:printf("qi");break;

        case 8:printf("ba");break;

        case 9:printf("jiu");break;

        default:break;

        }

        printf(" ");

    }







    return 0;

}

