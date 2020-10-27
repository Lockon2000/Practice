#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void entire_game(int *, int *);
void little_game(bool *, int *);
void redu_frac(int, int);


int main(void)
{
    int num_little_games = 0, num_words_entire_game = 0 ;

    entire_game(&num_little_games, &num_words_entire_game);
    redu_frac(num_little_games, num_words_entire_game);

    return 0;
}


void entire_game(int * p_num_little_games, int * p_num_words_entire_game)
{
    bool end_entire_game = false;
    int num_words_little_game = 0 ;

    while (!end_entire_game)
    {
        little_game(&end_entire_game, &num_words_little_game);
        *p_num_little_games += 1;
        *p_num_words_entire_game += num_words_little_game;
    }

        *p_num_little_games -= 1;
}


void little_game(bool * p_end_entire_game, int * p_num_words_little_game)
{
    char current_word[30] = "\0" , test_end_word[9] = "\0", test_archive_word[30] = "\0" , archive[510][26] = {"\0"} , ch ;
    char end_word[9] = "BULLSHIT" ;
    bool end_little_game = false, is_included = false, is_word = false;
    int i = 0, n = 0, j = 0, k = 0, m = 0, l = 0 ;
    *p_num_words_little_game = 0;

    while (!end_little_game)
    {
        is_included = false;

        is_word = false;
        i = 0 ;
        l = 0 ;
        while(isalpha(ch = getchar()) || ch == -1)
        {
            if (ch == -1)
            {
                *p_end_entire_game = true;
                *p_num_words_little_game = 0 ;
                return ;
            }
            else
            {
                current_word[i] = ch;
                if (l > 0)
                    is_word = true ;
                i++;
                l++;
            }
        }
        current_word[i] = '\0';

        if (!is_word)
        {
            continue;
        }

        for (k = 0 ; k < 30 ; ++k)
        {
            test_archive_word[k] = tolower(current_word[k]) ;
            if (test_archive_word[k] == '\0')
                break;
        }

        n = 0 ;
        while (n < m && !is_included)
        {
            if (strcmp(test_archive_word, archive[n]) == 0)
            {
                is_included = true;
                break;
            }
            ++n;
        }

        if (!is_included)
        {
            *p_num_words_little_game += 1;
            strcpy(archive[j], test_archive_word);
            ++j;
        }

        strncpy(test_end_word, current_word, 8);
        test_end_word[8] = '\0';
        if (strcmp(test_end_word, end_word) == 0)
        {
            end_little_game = true;
            *p_num_words_little_game -= 1;
        }
        ++m;
        }
}

void redu_frac(int denomenetor, int numerator)
{
    int curr_nume, curr_denom ;
    int nume_fatrors[500], denom_factors[500] ;
    int i, j, n ;
    int g_c_f, g_c_f_factors[700] ;

    for (i = 0 ; i < 500 ; ++i)
    {
        nume_fatrors[i] = denom_factors[i] = g_c_f_factors[i] = -1 ;
    }
    g_c_f_factors[0] = nume_fatrors[0] = denom_factors[0] = 1 ;

    curr_nume = numerator ;
    curr_denom = denomenetor ;

    for (i = 1,j = 0 ; i <= numerator ; i++)
    {
        if (curr_nume == (curr_nume/i)*i)
        {
            nume_fatrors[j] = i ;
            curr_nume /= i ;
            i = 1 ;
            ++j;
            if (curr_nume == 1)
                break;
        }
    }

    for (i = 1,j = 0 ; i <= denomenetor ; i++)
    {
        if (curr_denom == (curr_denom/i)*i)
        {
            denom_factors[j] = i ;
            curr_denom /= i ;
            i = 1 ;
            ++j;
            if (curr_denom == 1)
                break;
        }
    }

    n = 0 ;
    for (i = 0 ; nume_fatrors[i] != -1 ; ++i)
    {
        for (j = 0 ; denom_factors[j] != -1 ; ++j)
        {
            if (nume_fatrors[i] == denom_factors[j])
            {
                g_c_f_factors[n] = nume_fatrors[i] ;
                denom_factors[j] = 0 ;
                n++;
                break;
            }
        }
    }

    g_c_f = 1 ;
    for (i = 0 ; g_c_f_factors[i] != -1 ; ++i)
    {
        g_c_f *= g_c_f_factors[i] ;
    }

    printf("%d / %d\n", numerator/g_c_f, denomenetor/g_c_f);

}
