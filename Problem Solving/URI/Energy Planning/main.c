#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    unsigned int  B, D  ;
    int N, A, C, n ;
    double rate;

    setlocale(LC_ALL, "portuguese_brazil");

    scanf("%d", &N);

    for (n = 0 ; n < N ; ++n )
    {
        scanf("%d%u%d%u", &A, &B, &C, &D);

        rate = (double)(D - B) / (C - A);

        printf("%.2f\n", trunc(100*rate) / 100);


    }


    return 0;
}
