#include<stdio.h>
#include<string.h>


int main()
{
    char str[100];
    char p[100]={'\0'};
    int i,j,N;
    gets(str);
    scanf("%d",&N);
    for(i=N;str[i]!='\0';i++)
    {
        p[i-N]=str[i];
    }
    for(i=0;i<N&&str[i]!='\0';i++)
    {
        p[strlen(str)-N+i]=str[i];
    }
    printf("%s",p);
    return 0;

}