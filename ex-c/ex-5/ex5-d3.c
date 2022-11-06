#include <stdio.h>

//交换函数
int swap(int array[5][5], int n, int m)
{
    int j, t;
    if ((n >= 0 && n <= 4) && (m >= 0 && m <= 4))
    {
        for (j = 0; j < 5; j++)
        {
            t = array[n][j];
            array[n][j] = array[m][j];
            array[m][j] = t;
        }
        return 1;
    }
    else
        return 0;

}

int main()
{
    int i, j, n, m, flag;
    int num[5][5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &num[i][j]);
        }
    }
    scanf("%d%d", &n, &m);
    flag = swap(num, n, m); //判断是否交换
    if (flag == 1)
    {
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                printf("%4d", num[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("error");

    return 0;
}