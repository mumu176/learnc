#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    char str1[80];
    char str2[80];
    bool bo1,bo2,bo3,bo4;
    int i, flag = 0;
    gets(str1);
    gets(str2);


    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        bo1=str1[i]>='a'&&str1[i]<='z'||str1[i]>='A'&&str1[i]<='Z';
        bo2=str2[i]>='a'&&str2[i]<='z'||str2[i]>='A'&&str2[i]<='Z';
        bo3=abs(str1[i] - str2[i]) == 97 - 65;
        bo4=bo1&&bo2&&bo3;
        if (str1[i] > str2[i]&&!bo4)
        {
            flag = 1;
            break;
        }
        else if (str1[i] < str2[i]&&!bo4)
        {
            flag = -1;
            break;
        }
        else if (str1[i] == str2[i]||(str1[i] == str2[i])&&bo4)
        {
            flag = 0;
        }
    }
    if(strlen(str1)==strlen(str2)&&flag==0)
    printf("=");
    else if(flag==1||strlen(str1)>strlen(str2))
    printf(">");
    else if(flag==-1||strlen(str1)<strlen(str2))
    printf("<");

    return 0;
}