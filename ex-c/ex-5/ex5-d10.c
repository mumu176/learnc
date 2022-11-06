#include <stdio.h>
#define MAX 100
int main()
{
    int i, j, N, bo, bo1, bo2, count = 0;
    int num[MAX][MAX];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &num[i][j]);
        }
    }

    for (i = 1; i < N-1; i++)
    {
        for (j = 1; j < N-1; j++)
        {
            bo1 = (num[i][j] <= num[i][j + 1]-50 && num[i][j] <= num[i][j - 1]-50);
            bo2 = (num[i][j] <= num[i + 1][j]-50 && num[i][j] <= num[i - 1][j]-50);
            bo = bo1 & bo2;
            if (bo)
            {
                count++;
            }
        }
    }
    printf("%d",count);
   
    return 0;
}