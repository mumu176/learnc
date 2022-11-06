#include <stdio.h>
#define MAX 20
int main()
{
    int i, j, M, N, bo, bo1, bo2, flag = 0;
    int num[MAX][MAX];

    scanf("%d%d", &M, &N);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &num[i][j]);
        }
    }

    for (i = 1; i < M-1; i++)
    {
        for (j = 1; j < N-1; j++)
        {
            bo1 = (num[i][j] > num[i][j + 1] && num[i][j] > num[i][j - 1]);
            bo2 = (num[i][j] > num[i + 1][j] && num[i][j] > num[i - 1][j]);
            bo = bo1 & bo2;
            if (bo)
            {
                printf("%d %d %d\n", num[i][j], i+1, j+1);
                flag = 1;
            }
        }
    }
    if (flag == 0)
        printf("None %d %d", M, N);

    return 0;
}