#include <stdio.h>

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c----->%c\n", a, c);
    }
    else
    {
        hanoi(n - 1, a, c, b);
        printf("%c----->%c\n", a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 's', 'f', 'd');
    return 0;
}