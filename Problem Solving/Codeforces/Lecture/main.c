#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j ;
    int h = 0 ;

    scanf("%d %d", &n, &m);

    char a[m][11], b[m][11] ;
    char word[11] ;
    char lecture[n][11] ;

    for (i = 0 ; i < m ; ++i)
    {
        scanf("%s%s", a[i], b[i]);
    }

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%s", word);

        for (j = 0 ; j < m ; ++j)
        {
            if ( strcmp(word, a[j]) == 0 )
            {
                if ( strlen(a[j]) <= strlen(b[j]) )
                    sprintf(lecture[h], "%s", a[j]);
                else
                    sprintf(lecture[h], "%s", b[j]);
                ++h;
                break;
            }
            else if ( strcmp(word, b[j]) == 0 )
            {
                if (strlen(a[j]) <= strlen(b[j]))
                    sprintf(lecture[h], "%s", a[j]);
                else
                    sprintf(lecture[h], "%s", b[j]);
                ++h;
                break;
            }
        }
    }

    for (i = 0 ; i < n ; ++i)
    {
        printf("\n\n%s\n\n", lecture[i]);
    }

    return 0;
}
