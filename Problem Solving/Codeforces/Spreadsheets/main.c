#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void coordinates_scan(char *, int *, int *, int *);
void coordinates_convert(int, int, int);
void mapping(char *, int, int *);
void remapping(int, char *);

int main()
{
    char input[20];
    int row, colum ;
    int input_form ;
    int n, i ;

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
    scanf("%s", input);
    coordinates_scan(input, &row, &colum, &input_form);
    coordinates_convert(row, colum, input_form);
    }

    return 0;
}

void coordinates_scan(char input[], int * row_ptr, int * colum_ptr, int * input_form_ptr)
{
    int lenth = strlen(input) ;
    int lenth_of_first_chars ;
    char first_chars[10] ;
    char * first_num ;

    first_num = strpbrk(input, "123456789");
    lenth_of_first_chars = lenth - strlen(first_num) ;
    strncpy(first_chars, input, lenth_of_first_chars);
    first_chars[lenth_of_first_chars] = '\0' ;

    if ( strpbrk(input + lenth_of_first_chars, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == NULL )
    {
        *input_form_ptr = 2 ;
        sscanf(input + lenth_of_first_chars, "%d", row_ptr);
        mapping(first_chars, lenth_of_first_chars, colum_ptr);
    }
    else
    {
        *input_form_ptr = 1 ;
        sscanf(input, "%*c%d%*c%d", row_ptr, colum_ptr);
    }
}

void coordinates_convert(int row, int colum, int input_form)
{
    char output[20];

    if (input_form == 1)
    {
        remapping(colum, output);
        printf("%s%d\n", output, row);
    }
    else
    {
        printf("R%dC%d\n", row, colum + 1);
    }
}

void mapping(char input[], int lenth, int * colum_ptr)
{
    int i, n, j ;
    char colum_characters[10] ;

    for (i = 0 ; i < lenth ; ++i)
    {
        colum_characters[i] = 'A' ;
    }
    colum_characters[i] = '\0' ;

    n =
    j = 0 ;
    while ( strcmp(colum_characters,input) == 0)
    {

    }



}

void remapping(int colum, char output[])
{
    int lenth, i ;

    itoa(colum, output, 26);
    lenth = strlen(output);

    for (i = 0 ; i < lenth ; ++i)
    {
        switch (output[i])
        {
            case '0': output[i] = 'A' ;
                        break ;
            case '1': output[i] = 'B' ;
                        break ;
            case '2': output[i] = 'C' ;
                        break ;
            case '3': output[i] = 'D' ;
                        break ;
            case '4': output[i] = 'E' ;
                        break ;
            case '5': output[i] = 'F' ;
                        break ;
            case '6': output[i] = 'G' ;
                        break ;
            case '7': output[i] = 'H' ;
                        break ;
            case '8': output[i] = 'I' ;
                        break ;
            case '9': output[i] = 'J' ;
                        break ;
            case 'a': output[i] = 'K' ;
                        break ;
            case 'b': output[i] = 'L' ;
                        break ;
            case 'c': output[i] = 'M' ;
                        break ;
            case 'd': output[i] = 'N' ;
                        break ;
            case 'e': output[i] = 'O' ;
                        break ;
            case 'f': output[i] = 'P' ;
                        break ;
            case 'g': output[i] = 'Q' ;
                        break ;
            case 'h': output[i] = 'R' ;
                        break ;
            case 'i': output[i] = 'S' ;
                        break ;
            case 'j': output[i] = 'T' ;
                        break ;
            case 'k': output[i] = 'U' ;
                        break ;
            case 'l': output[i] = 'V' ;
                        break ;
            case 'm': output[i] = 'W' ;
                        break ;
            case 'n': output[i] = 'X' ;
                        break ;
            case 'o': output[i] = 'Y' ;
                        break ;
            case 'p': output[i] = 'Z' ;
                        break ;
        }
    }
}
