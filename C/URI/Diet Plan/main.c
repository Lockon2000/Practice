#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cross_out(char [], char []);
void sort_print(char []);
int comp(const void * , const void *);

int main()
{
    int n , i ;
    char ch ;
    char diet[27], breakfast[27], lunch[27] ;

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        getchar();
        if (( ch = getchar()) == '\n')
            diet[0] = '\0' ;
        else
        {
            ungetc(ch , stdin);
            scanf("%s", diet);
        }
        getchar();
        if (( ch = getchar()) == '\n')
            breakfast[0] = '\0' ;
        else
        {
            ungetc(ch , stdin);
            scanf("%s", breakfast);
        }
        getchar();
        if (( ch = getchar()) == '\n')
            lunch[0] = '\0' ;
        else
        {
            ungetc(ch , stdin);
            scanf("%s", lunch);
        }

        if (cross_out(diet , breakfast))
        {
            printf("----------------CHEATER\n");
            continue ;
        }
        if (cross_out(diet , lunch))
        {
            printf("----------------CHEATER\n");
            continue ;
        }

        sort_print(diet);
    }

    return 0;
}

int cross_out(char diet[], char meal[])
{
    int diet_length = strlen(diet);
    int meal_length = strlen(meal);
    int n , m ;

    for (n = 0 ; n < meal_length ; ++n)
    {
        for (m = 0 ; m < diet_length ; ++m)
        {
            if (meal[n] == diet[m])
            {
                diet[m] = 'a' ;
                break ;
            }
        }
        if (m == diet_length)
            return 1 ;
    }

    return 0 ;
}

void sort_print(char dinner[])
{
    int n = 0 ;
    int length = strlen(dinner);

    qsort(dinner , length , 1 , comp);

    while (dinner[n] != 'a')
    {
        ++n ;
    }


    dinner[n] = '\0' ;

    printf("----------------%s\n", dinner);
}

int comp(const void * fir , const void * sec)
{
    if (*((char *) fir) > *((char *) sec))
        return 1 ;
    else if (*((char *) fir) < *((char *) sec))
        return -1 ;
    else
        return 0 ;
}
