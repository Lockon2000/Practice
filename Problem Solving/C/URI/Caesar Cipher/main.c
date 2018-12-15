#include <stdio.h>
#include <string.h>

int main()
{
    int n ;
    int i, j ;
    scanf("%d", &n);

    int shift ;
    char cipher[51];
    int length ;

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%s", cipher);
        scanf("%d", &shift);
        length = strlen(cipher);

        for (j = 0 ; j < length ; ++j )
        {
            if ((cipher[j] - shift) >= 65 )
                cipher[j] -= shift ;
            else
                cipher[j] = 91 - ( 65 - (cipher[j] - shift) ) ;
        }

        printf("%s\n", cipher);

    }
    return 0;
}
