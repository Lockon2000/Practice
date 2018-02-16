#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, x, j ;
    long double grain, gram ;
    unsigned long long kg ;

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%d", &x);

        grain = 0 ;

        for (j = 0 ; j < x ; ++j)
        {
            grain += pow(2,j) ;
        }

        gram = grain / 12 ;

        kg = gram / 1000 ;

        printf("%llu kg\n", kg);
    }

    return 0;
}
