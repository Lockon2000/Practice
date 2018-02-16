#include <stdio.h>
#include <inttypes.h>

int main()
{
    int a = 2147483647 ;
    unsigned int b = 4294967295 ;
    short c = 5;
    int h = 8439;

    printf("\n\n\n%d %d %d\n\n\n", a, a+1 ,a+2 );
    printf("\n\n\n%u %u %u\n\n\n", b, b+1 ,b+2 );
    printf("\n\n\n%hd %d %d\n\n\n", c, c+1 ,h+2 );
    printf("%"PRIuMAX"\n\n\n", UINTMAX_MAX);

    return 0;
}
