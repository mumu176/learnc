#include <stdio.h>
int main()
{
    int n, i, j,s1=0,s2=0,s3=0;
    int num[4][4];

for(i=0; i<4; i++)
{
    for(j=0; j<4; j++)
    {
        scanf("%d",&num[i][j]);

        if(i==0||j==0||i==3||j==3)
        {
            s1+=num[i][j];
        }
        if(i==j)
        {
            s2+=num[i][j];
        }
        if(i+j==3)
        {
            s3+=num[i][j];
        }
    }
}

    printf("%d\n%d\n%d\n",s1,s2,s3);
    return 0;
}