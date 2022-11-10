#include <stdio.h>
#define N 10000
int main()
{
    int i, j, k, n, flag = 0;
    char str[20][N];
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%s",str[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; str[i][j] != '\0'; j++)
        {
            flag=0;
            for (k = 0; str[i][k] != '\0'; k++)
            {
                if (str[i][j] == str[i][k]&&j!=k)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("%c\n",str[i][j]);
                break;
            }
        }
        if(flag==1)
        {
            printf("no\n");
        }
    }
    return 0;
}