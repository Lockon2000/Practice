#include <stdio.h>
#include <string.h>

int main()
{
    int n ;
    scanf("%d", &n);

    char lib[50][51];
    char ch ;
    char * ptr[50];
    char * temp_ptr ;
    int length[50];
    int temp_len ;

    getchar();

    int i , j ;
    for (i = 0 ; i < n ; ++i)
    {
        j = 0 ;
        scanf("%s", lib[j]);
        ptr[j] = lib[j];
        length[j] = strlen(lib[j]);
        ++j;
        while ((ch = getchar()) != '\n')
        {
            scanf("%s", lib[j]);
            ptr[j] = lib[j];
            length[j] = strlen(lib[j]);
            ++j;
        }

        int k , l , end = 0 ;
        for (k = j - 1  ; k != end ; ++end)
        {
            for (l = j - 1 ; l != end ; --l)
            {
                if (length[l - 1] < length[l])
                {
                    temp_ptr = ptr[l - 1];
                    ptr[l - 1] = ptr[l];
                    ptr[l] = temp_ptr ;
                    temp_len = length[l - 1];
                    length[l - 1] = length[l];
                    length[l] = temp_len ;
                }
            }
        }

        int g ;
        for (g = 0 ; g < j ; )
        {
            printf("%s", ptr[g]);
            if (++g < j)
                putchar(' ');
        }

        putchar('\n');

    }
    return 0;
}
