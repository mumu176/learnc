#include <stdio.h>
#define N 10
int main()
{
    int n, i, j, flag;
    int num[N][N];
    //输入
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &num[i][j]);
        }
    }
    //判断下三角以flag标记
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (num[i][j] == 0)
                flag = 1;
            else
            {
                flag = -1;
                break;
            }
        }
        if (flag == -1)
            break;
    }
    //输出
    if (flag == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}