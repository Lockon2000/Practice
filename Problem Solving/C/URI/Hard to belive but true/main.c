#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    int a = 0 , b = 0 , c = 0 ;
    int finum[7], scnum[7], thnum[7] ;
    int i ;
    char ch ;
    char fich[7], scch[7], thch[7] ;
    bool there_is_still_input_left = true ;

    while (there_is_still_input_left)
    {
    for ( i = 0 ; i < 7 ; ++i )
        fich[i] = '0';

    for ( i = 0 ; i < 7 ; ++i )
        scch[i] = '0';

    for ( i = 0 ; i < 7 ; ++i )
        thch[i] = '0';

        i = 0;

    while ( isdigit(ch = getchar()))
        {
            fich[i] = ch ;
            ++i ;
        }

        i = 0;

    while ( isdigit(ch = getchar()))
        {
            scch[i] = ch ;
            ++i ;
        }

        i = 0;

    while ( isdigit(ch = getchar()))
        {
            thch[i] = ch ;
            ++i ;
        }

        for ( i = 0 ; i < 7 ; ++i )
        {
            switch (fich[i])
            {
                case '0' : finum[i] = 0 * pow(10 , i);
                            break;
                case '1' : finum[i] = 1 * pow(10 , i);
                            break;
                case '2' : finum[i] = 2 * pow(10 , i);
                            break;
                case '3' : finum[i] = 3 * pow(10 , i);
                            break;
                case '4' : finum[i] = 4 * pow(10 , i);
                            break;
                case '5' : finum[i] = 5 * pow(10 , i);
                            break;
                case '6' : finum[i] = 6 * pow(10 , i);
                            break;
                case '7' : finum[i] = 7 * pow(10 , i);
                            break;
                case '8' : finum[i] = 8 * pow(10 , i);
                            break;
                case '9' : finum[i] = 9 * pow(10 , i);
                            break;
            }
        }

        for ( i = 0 ; i < 7 ; ++i )
        {
            switch (scch[i])
            {
                case '0' : scnum[i] = 0 * pow(10 , i);
                            break;
                case '1' : scnum[i] = 1 * pow(10 , i);
                            break;
                case '2' : scnum[i] = 2 * pow(10 , i);
                            break;
                case '3' : scnum[i] = 3 * pow(10 , i);
                            break;
                case '4' : scnum[i] = 4 * pow(10 , i);
                            break;
                case '5' : scnum[i] = 5 * pow(10 , i);
                            break;
                case '6' : scnum[i] = 6 * pow(10 , i);
                            break;
                case '7' : scnum[i] = 7 * pow(10 , i);
                            break;
                case '8' : scnum[i] = 8 * pow(10 , i);
                            break;
                case '9' : scnum[i] = 9 * pow(10 , i);
                            break;
            }
        }

        for ( i = 0 ; i < 7 ; ++i )
        {
            switch (thch[i])
            {
                case '0' : thnum[i] = 0 * pow(10 , i);
                            break;
                case '1' : thnum[i] = 1 * pow(10 , i);
                            break;
                case '2' : thnum[i] = 2 * pow(10 , i);
                            break;
                case '3' : thnum[i] = 3 * pow(10 , i);
                            break;
                case '4' : thnum[i] = 4 * pow(10 , i);
                            break;
                case '5' : thnum[i] = 5 * pow(10 , i);
                            break;
                case '6' : thnum[i] = 6 * pow(10 , i);
                            break;
                case '7' : thnum[i] = 7 * pow(10 , i);
                            break;
                case '8' : thnum[i] = 8 * pow(10 , i);
                            break;
                case '9' : thnum[i] = 9 * pow(10 , i);
                            break;
            }
        }

        a = 0 ; b = 0 ; c = 0 ;

        for(i = 0 ; i < 7 ; ++i )
            a += finum[i] ;

        for(i = 0 ; i < 7 ; ++i )
            b += scnum[i] ;

        for(i = 0 ; i < 7 ; ++i )
            c += thnum[i] ;

        if ( a + b == c)
            printf("True\n");
        else
            printf("False\n");

        if ( a == 0 && b == 0 && c == 0 )
            there_is_still_input_left = 0;
    }

    return 0;
}
