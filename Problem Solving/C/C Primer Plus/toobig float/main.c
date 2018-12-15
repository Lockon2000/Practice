#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int main()
{
    char Alph[56];
    int i = 0,x = 0;

    while (i<=55)
    {
        Alph[i] = 65 + i;
        ++i;
    }

    while (x<=55)
    {
        printf("%c %d\n", Alph[x],Alph[x]);
        ++x;
    }

    return 0;
}
