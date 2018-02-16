#include <cstdio>
#include <cctype>

using namespace std;

int main()
{
    char ch ;
    bool cap = true ;

    while ((ch = getchar()) != EOF)
    {
        switch (ch)
        {
            case '\n':
                cap = true ;

            case ' ':
                putchar(ch);
                break ;

            default:
                if (cap == true)
                    putchar(toupper(ch));
                else
                    putchar(tolower(ch));
                cap = !cap ;
        }
    }

    return 0;
}
