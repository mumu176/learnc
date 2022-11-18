#include <stdio.h>

#include <stdlib.h>

#define N 255



int main()

{

    int i=0,count=0,flag=0;

    char str[N];



    scanf("%s",str);



    while(1)

    {



        if(str[i]!='\0')

        {

            count++;

            i++;

        }

        else

        {

            i=0;

            break;

        }

    }



    while(i!=count/2&&i!=(count+1)/2)

    {

        if(str[i]==str[count-i-1])

        {

            flag=1;

            i++;

        }

        else

        {

            flag=0;

            break;

        }



    }

    if(flag==1)

        printf("Yes");

    else

        printf("No");

    return 0;

}

