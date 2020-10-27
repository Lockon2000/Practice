#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void entire_game(int *, int *);
void little_game(int *, _Bool *);
void read_compare
void
void red_frac(int, int);

int main(void)
{
    int num_all_games = 0, num_all_words = 0 ;

    entire_game(&num_all_games, &num_all_words);
    red_frac(num_all_games, num_all_words);

    return 0;
}

void entire_game(int * p_num_all_games, int * p_num_all_words)
{
    _Bool end_entire_game = 0;
    int num_words_little_game ;

    while (!end_entire_game)
    {
        little_game(&num_words_little_game, &end_entire_game);
        *p_num_all_words += num_words_little_game;
        *p_num_all_games++;
    }
}

void little_game(int * p_num_words_little_game, _Bool * p_end_entire_game)
{
    char ch, word[30], word_test[30], end_little_game_word[9] = "BULLSHIT" ;
    int i = 0;

    while (ch = getchar(),1)
    {
        if (ch == -1)
        {
            *p_end_entire_game = 1;
            break;
        }
        else if (isalpha(ch))
        {
            word[i] = ch ;
            ++i;
        }
        else
        {
            *p_num_words_little_game++;
        }

        strcpy(word_test,word);
        word_test[8] = '\0';

        if (strcmp(word_test,end_little_game_word) == 0)
        {
            *p_num_words_little_game--;
            break;
        }
    }
}































