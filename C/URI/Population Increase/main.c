#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, pa, pb, i, n ;
    double g1, g2, g3, g4 ;
    const int TIME_LIMIT = 100;

    scanf("%d", &t);

    for (n = 0 ; n < t ; ++n )
    {
        scanf("%d%d%lf%lf", &pa, &pb, &g3, &g4);

        i = 0;

        g1 = 1.0 + g3/100;
        g2 = 1.0 + g4/100;

        while ( pa <= pb && i < TIME_LIMIT )
        {
            pa *= g1;
            pb *= g2;
            ++i;
        }

        if ( pa > pb )
            printf("%d anos.\n", i);
        else
            printf("Mais de 1 seculo.\n");
    }


    return 0;
}
