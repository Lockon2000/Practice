#include <stdio.h>
#include <stdlib.h>

int main()
{
    int word_num = 1;
    char character;
    int check = 0;

    while (scanf("%c", &character) != -1)
    {
        if ((character == 32) || (character == '\n'))
        {
            ++word_num;
            while ((character == 32) || (character == '\n'))
            {
                if ((scanf("%c", &character) == -1))
                    goto finish;
            }
        }
        else
            ++check;
    }

finish: if ( check == 0)
            printf("\n\nThere where no Words in this file\n\n\n");
        else
            printf("\n\nThe Number of words in this File is %d\n\n\n", word_num);


    return 0;
}
