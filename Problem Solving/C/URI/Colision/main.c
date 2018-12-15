#include <stdio.h>

int main()
{
    int a1, a2, b1, b2, hub, hlb, vub, vlb, x, y ;
    long long int n, i ;

    scanf("%l64d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%d%d%*d%*d%d%d%*d%*d%d%d", &a1, &b1, &a2, &b2, &x, &y);

        if (a1 > a2)
        {
            vub = a1;
            vlb = a2;
        }
        else
        {
            vub = a2;
            vlb = a1;
        }

        if (b1 > b2)
        {
            hub = b1;
            hlb = b2;
        }
        else
        {
            hub = b2;
            hlb = b1;
        }

        if ( (x > vlb && x < vub) && (y > hlb && y < hub) )
            putchar('1');
        else
            putchar('0');

        putchar('\n');

    }
    return 0;
}
