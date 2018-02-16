#include <iostream>

using namespace std;

int main()
{
    string dollar ;
    int cent , rem , length ;

    while (cin >> dollar >> cent)
    {
        length = dollar.length();
        length -= rem = length%3 ;

        putchar('$');

        for (int i = 0 , j = rem ; j-- ; ++i)
            cout << dollar[i];

        if (rem != 0 && length != 0)
            putchar(',');

        for (int i = 0 ; length-- ; ++i)
        {
            cout << dollar[i+rem];
            if (length%3 == 0 && length != 0)
                cout << ',' ;
        }

        if (cent < 10)
            cout << ".0" << cent << '\n' ;
        else
            cout << '.' << cent << '\n' ;
    }
    return 0;
}
