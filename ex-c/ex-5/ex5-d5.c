#include <stdio.h>
#define N 100
int main()
{
    int n, i, j, t, k, flag = 0;
    int num[N];

    scanf("%d", &n);
    scanf("%d", &k); //读取nk

    for (i = 0; i < n; i++) //先输入n个然后统一读取n次
    {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < n - 1; i++) //冒泡排序
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (num[j] < num[j + 1])
            {
                t = num[j];
                num[j] = num[j + 1];
                num[j + 1] = t;
                flag = 1;
            }
        }
        if (flag != 1)
        {
            break;
        }
    }


    printf("%d ", num[k - 1]);

    return 0;
}