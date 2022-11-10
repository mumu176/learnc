#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
int main()
{
    // int s;
    // srand((unsigned)time(NULL));
    // s=rand();
    time_t t;
    t = time(NULL);
    struct tm *tb;
    tb = localtime(&t);
    printf("%s", asctime(tb));
    return 0;
}
