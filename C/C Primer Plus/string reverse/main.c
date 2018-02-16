#include <stdio.h>
#include <string.h>

int main()
{
    char line[16] , linerev[16] ;
    int i , lenth;

    gets(line);
    lenth = strlen(line);

    for (i = 0 ; i < lenth ; ++i)
    {
        linerev[i] = line[lenth]
    }


    return 0;
}
