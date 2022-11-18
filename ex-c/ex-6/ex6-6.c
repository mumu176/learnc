#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int isAnagram(char *str1, char *str2)
{
    int i;
    bool flag = 1;
    int countalph[26] = {0};

    if (strlen(str1) != strlen(str2))
        return 0;
    for (i=0; str1[i] != '\0';i++)
    {
        countalph[str1[i] - 97]++;
    }
    for (i=0; str2[i] != '\0';i++)
    {
        countalph[str2[i] - 97]--;
    }
    for (i = 0; i < 26; i++)
    {
        if (countalph[i] != 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}

int main()
{
    char str[2][20];
    scanf("%s", str[0]);
    scanf("%s", str[1]);
    if (isAnagram(str[0], str[1]) == 1)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}