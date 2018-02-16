#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void games(int * p_num_games, int * p_total_num_words);
void red_frac(int , int);

int main()
{
    int num_games, total_num_words ;

    games(&num_games, &total_num_words);
    red_frac(num_games, total_num_words);

    return 0;
}


void games(int * p_num_games, int * p_total_num_words)
{
    char word[27], ch, word_test[9] ;
    char end_word[9] = "BULLSHIT" ;
    int num_words_one_game ;
    const int max_num_words = 500 ;
    _Bool end_entire_game, end_one_game ;

    end_entire_game = 0
    while (!end_entire_game)
    {
        while (!end_one_game)
        {
            while ((ch = getchar) != -1 && isalpha(ch))
            {
                word[i] = ch ;
            }

            strcpy(word_test, word)
            word_test[9] = '\0';

            if (strcmp(word,end_word) == 0)
            {
                ++*p_num_games;
                num_words_one_game = 0 ;
                end_one_game = 1 ;
            }
            else if

        }
    }

}


































