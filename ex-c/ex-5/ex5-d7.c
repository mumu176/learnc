#include <stdio.h>
#define N 10000
int main()
{
    int n, i, j, t, k = 0,  flag = 0;
    int num[N], out[N];

    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        for (i = 0; i < n; i++) //先输入n个然后统一读取n次
        {
            scanf("%d", &num[i]);
        }

        for (i = 0; i < n - 1; i++) //冒泡排序
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (num[j] > num[j + 1])
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
        if (n % 2)
        {
            out[k] = num[((n + 1) / 2) - 1];
            k++;
        }
        else
        {
            out[k] = (num[n / 2 - 1] + num[n / 2]) / 2;
            k++;
        }
    }

    for (i = 0; i < k; i++)
    {
       printf("%d\n", out[i]);
    }
    

    return 0;
}