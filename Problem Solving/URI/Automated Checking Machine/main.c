#include <stdio.h>

int main()
{
    int i, x, a[5], b[5] ;

    scanf("%d%d%d%d%d%d%d%d%d%d", &a[0],&a[1],&a[2],&a[3],&a[4],&b[0],&b[1],&b[2],&b[3],&b[4]);

    i = -1 ;
    x = 1 ;

    while (i++ < 4)
    {
        if (a[i] == b[i])
            x = 0;
    }

    if ( x == 0 )
        putchar('N');
    else
        putchar('Y');

    putchar('\n');

    return 0;
}
