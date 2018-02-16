#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strlstr(const char haystack[] , const char needle[]);

int main()
{
    char adr[51] ;
    char * ptr , * base ;

    scanf("%s", adr);
    base = adr ;

    ptr = strstr(adr , "http");

    if (ptr == adr)
    {
        printf("http://");
        base += 4 ;
    }
    else
    {
        printf("ftp://");
        base += 3 ;
    }

    ptr = strlstr(adr , "ru");
    printf("%.*s.ru", ptr - base , base);
    base += (ptr - base) + 2 ;

    if (base[0] != '\0')
        printf("/%s", base);

    return 0;
}

char * strlstr(const char haystack[] , const char needle[]) 	// returns a pointer to the first character of the last occurrence
{																// of the string needle int the string haystack.
    char * scout , * target ;

    target = scout = strstr(haystack , needle);
    if (scout != NULL)
    {
        while ((scout = strstr(scout + 1 , needle)) != NULL )
            target = scout ;
    }

    return target ;
}
