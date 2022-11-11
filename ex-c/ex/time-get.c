#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
int main()
{
    time_t t;
    t = time(NULL);
    struct tm *tb;
    tb = localtime(&t);
    printf("%s", asctime(tb));
    return 0;
}
