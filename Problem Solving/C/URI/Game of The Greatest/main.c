#include <stdio.h>

int main()
{
    int a, b, c, d, n, i ;

    while ( scanf("%d", &n), n != 0)
    {
        c = d = 0 ;

        for (i = 0 ; i < n ; ++i)
        {
            scanf("%d%d", &a, &b);
            if ( a < b )
                ++d;

            if ( a > b)
                ++c;
        }

        printf("%d %d\n", c, d);
    }

    return 0;
}
