#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n ;
    int d , k ;
    string desks ;
    char ch1 , ch2 , ch3 ;
    int length ;
    int j ;
    int repaints ;

    cin >> n ;

    for (int i = 0 ; i < n ; ++i)
    {
        cin >> d >> k ;
        cin >> desks ;

        repaints = 0 ;
        length = desks.length();
        j = 0 ;

        while ((j+1) < length)
        {
            ch1 = desks[j] ;
            ch2 = desks[j+1] ;

            if (ch1 == ch2)
            {
                ch2 = desks[j+2] ;
                ch3 = 'A' ;

                while (true)
                {
                    if (ch3 != ch1 && ch3 != ch2)
                    {
                        desks[j+1] = ch3 ;
                        break;
                    }
                    else
                        ++ch3;
                }
                ++repaints;
                j += 2 ;
                continue;
            }

            ++j;
        }

        cout << repaints << '\n' ;
    }


    return 0;
}
