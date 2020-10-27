#include <stdio.h>
#include <string.h>

int main()
{
    int n , i, lenth, j, m, a ;
    char wrong[101], right[101];

    scanf("%d", &n);
    getchar();

    for (i = 0 ; i < n ; ++i)
    {
        gets(wrong);
        lenth = strlen(wrong);

        a = lenth/2 - 1;

        for (j = 0 ; j < lenth/2 ; ++j)
        {
            right[j] = wrong[a - j];
        }

        for (m = 0; m < lenth/2 ; ++m)
        {
            right[m + j] = wrong[lenth - 1 - m];
        }
        right[lenth] = '\0';

        printf("%s\n", right);

    }

    return 0;
}
