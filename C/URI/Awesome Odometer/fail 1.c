#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    unsigned int n, i, k, j ;
    unsigned int string_lenght, num_lenght ;
    unsigned long long num_of_equal ;
    char display[100005], odometer[100005], full_odometer[100005] ;
    _Bool equal_odometer, end_of_odd_cycle ;

    while ( scanf("%s", display) != EOF )
    {
        string_lenght = strlen(display);
        num_of_equal = 0 ;

        if ( display[0] == '0' )
        {
            printf("%llu", num_of_equal % (int) pow(2,32));
            continue;
        }


        //  generating all possible numbers meeting the criteria  //
        for (num_lenght = 1 ; num_lenght <= string_lenght ; ++num_lenght)
        {
            //  Initializing odometer and full_odometer //
            odometer[0] = odometer[num_lenght - 1] = '1';
            full_odometer[0] = full_odometer[num_lenght - 1] = '9';
            for (i = 1 ; i < (num_lenght - 1) ; ++i)
            {
                odometer[i] = '0';
                full_odometer[i] = '9';
            }
            odometer[i + 1] = '\0';
            full_odometer[i + 1] = '\0';



            //  the cycle for a specific num_lenght  //
            do
            {
                equal_odometer = 1 ;


                if ( num_lenght == 1 )						// num_lenght = (1) of even or odd
                {
                    if ( num_lenght < string_lenght )        	// num_lenght (less) than or equal to string_lenght
                    {
                        //  Testing of equality between odometer and full_odometer  //
                        if ( odometer[0] != full_odometer[0] )
                            equal_odometer = 0;


                        //  Increment  //
                        odometer[0] += 1;

                        ++num_of_equal;
                    }

                    else            						// num_lenght less than or (equal) to string_lenght
                    {
                        //  Testing of equality between odometer and display  //
                        if ( odometer[0] != display[0] )
                            equal_odometer = 0;


                        //  Increment  //
                        odometer[0] += 1;


                        ++num_of_equal;
                    }
                }


                else if ( num_lenght % 2 == 0 )				// num_lenght = 1 of (even) or odd
                {
                    if ( num_lenght < string_lenght )					// num_lenght (less) than or equal to string_lenght
                    {
                        //  Testing of equality between odometer and full_odometer  //
                        for (k = 0 ; k < num_lenght ; ++k)
                        {
                            if ( odometer[k] != full_odometer[k] )
                                equal_odometer = 0 ;
                        }


                        //  Halfs Increment  //
                        for (n = (num_lenght/2 - 1),j = (num_lenght/2) ; n >= 0 ; --n,++i)
                        {
                            if ( odometer[n] == '9' )
                                odometer[n] = '0';
                            else
                                odometer[n] += 1 ;

                            if ( odometer[j] == '9' )
                                odometer[j] = '0';
                            else
                            {
                                odometer[j] += 1 ;
                                break;
                            }
                        }

                        ++num_of_equal;
                    }
                    else								            // num_lenght less than or (equal) to string_lenght
                    {
                        //  Testing of equality between odometer and display  //
                        for (k = 0 ; k <= (num_lenght/2 - 1) ; ++k)
                        {
                            if ( odometer[k] != display[k] )
                                equal_odometer = 0 ;
                        }


                        //  Halfs Increment //
                        for (n = (num_lenght/2 - 1),j = (num_lenght/2) ; n >= 0 ; --n,++i)
                        {
                            if ( odometer[n] == '9' )
                                odometer[n] = '0';
                            else
                                odometer[n] += 1 ;

                            if ( odometer[j] == '9' )
                                odometer[j] = '0';
                            else
                            {
                                odometer[j] += 1 ;
                                break;
                            }
                        }

                        ++num_of_equal;
                    }
                }


                else								        // num_lenght = 1 of even or (odd)
                {
//                    ..........
                }
            } while ( !equal_odometer );
        }

        printf("%llu", num_of_equal % (int) pow(2,32));
    }


	return 0;
}
