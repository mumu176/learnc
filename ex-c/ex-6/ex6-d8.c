#include <stdio.h>
#include <string.h>

int main()
{
    char str[5][100];
    char st[100]={'\0'};
    int i,k;
    for(i=0;i<5;i++)
    {
        scanf("%s",str[i]);
    }
    for (i = 0; i < 5; i++)
    {
        if (strcmp(str[i],st)==1)
        {
            strcpy(st,str[i]);
            k = i;
        }
    }
    printf("%s", str[k]);
    return 0;
}