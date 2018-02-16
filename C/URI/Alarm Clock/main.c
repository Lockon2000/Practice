#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m1, m2, h1, h2, time1, time2, out ;

    while ( (scanf("%d%d%d%d", &h1, &m1, &h2, &m2)) , (h1 != 0 || h2 != 0 || m1 != 0 || m2 != 0) )
    {

        time1 = h1*60 + m1;
        time2 = h2*60 + m2;

        if ( time2 < time1)
            time1 -= 1440;

        out = time2 - time1;

        printf("%d\n", out);

    }

    return 0;
}
