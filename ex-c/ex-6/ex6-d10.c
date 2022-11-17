#include <stdio.h>

int main()
{
    int n, i, j, max;
    char maxch;
    char str[10][1000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }
    for (i = 0; i < n; i++)
    {
        int countalph[26]={0};
        for (j = 0; str[i][j] != '\0'; j++)
        {
            countalph[str[i][j] - 97]++;
        }
        for (j = 0, max = 0; j < 26; j++)
        {
            if (countalph[j] > max)
            {
                maxch = 97 + j;
                max = countalph[j];
            }
        }
        printf("%c %d\n", maxch, max);
    }
    return 0;
}