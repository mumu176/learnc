#include <stdio.h>
#define N 255
int main()
{
    int counten = 0, countnum = 0, count = 0, i;
    char str[N];
    gets(str);//除了回车
    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            counten++;
        else if ((str[i] >= '0' && str[i] <= '9'))
            countnum++;
        else
            count++;
    }
    printf("%d\n%d\n%d", counten, countnum, count);
    return 0;
}