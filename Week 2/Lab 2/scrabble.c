#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
    // TODO: Print the winner
}

int compute_score(string word)
{
    int score = 0;


    for (int i = 0; i < strlen(word); i++)
    {
        //convert words into alphabets and store each lowercase alphabet in variable
        char letter = tolower(word[i]);

        //determining position of alphabet using ASCII Table
        int position = letter - 'a';

        //if position is in the range 26, calculating the score using POINTS list
        if (position >= 0 && position <= 26)
        {
            score = score + POINTS[position];

        }

    }
    return score;

}
