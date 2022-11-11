#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int s;
    srand((unsigned)time(NULL));
    s = rand()%10;
    printf("%d", s);
}