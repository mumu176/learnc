#include <stdio.h>
#define N 255

int main()
{
    int i, count[26] = {0};
    char str[N];
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
            count[str[i]-65]++;
    }
    for (i = 'A'-65; i <= 'Z'-65; i++)
    {
        if (count[i] == 0)
            continue;
        else
            printf("%c:%d\n", i+65+('a'-'A'), count[i]);
    }
}