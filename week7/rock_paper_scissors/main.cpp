#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <vector>
#include "qolife.h"

/* Set using statements for the commands I will be using most often. */
using std::cout; using std::cin; using std::endl; using std::string;

void intro();

char match_input(string input);

int get_choice();

int get_bot();

void round_winner(int,int,int&,int&);

void game_winner(const int&,const int&,const int&);

bool play_again();

/* I have put a great deal of work into finding ways to keep main() as clean as
 * possible. I use it to start things and to check if things should continue,
 * but I prefer to rely on the functions I have made to do all of the heavy
 * lifting. It is so much easier to debug code this way and I can often make
 * very large changes to the function of the program very quickly and without
 * errors because it is so clear where things are happening. This way tasks
 * aren't scattered all over the place and there is no need to unravel what is
 * going on or unwind some complex task in order to make a small change. */
int main()
{
    int round;    /* Number of turns. */
    int p1s, p2s; /* Player 1 and Player 2 score. */

    srand(time(0));

    /* Show the intro and instructions to the user. */
    intro();

    do {
        round = 1;

        /* Picked up this trick from the Yahtzee assignment. I did not know c++
         * supported assignment chaining. */
        p1s = p2s = 0; /* Player 1 and Player 2 starting score. */

        do {

            /* Use the return values from get_choice() and get_bot() directly
             * within the call to round_winner(). I like this a lot as it makes
             * it very obvious where data is coming from. */
            round_winner( get_choice(), get_bot(), p1s, p2s );
            round++;
            cout << "::Score::\n"
                 << "   Player 1: " << p1s << endl
                 << "   Player 2: " << p2s << endl;

        /* Loop will continue until the score from both players == 5 or win
         * from one side is inevitable. */
        } while( p1s + p2s < 5
                and !( p1s + p2s > 3 and std::abs( p1s - p2s ) > 1) );

        cout << endl;

        /* Call game winner to announce who one and how many turns taken. */
        game_winner( p1s, p2s, round );

    } while(play_again() == true);

    cout << "Goodbye!" << endl;

    return 0;
}

void intro() {

    _print_center(
        { "This is the game of Rock/Paper/Scissors!",
        "You will play against a computer opponent, but he",
        "isn't very smart. Try to go easy on the poor guy.",
        "Rock beats Scissors, Scissors beats Paper, Paper beats Rock.",
        "Best out of five, wins!" } , 62, 300, ' ');
}

/* Gets the players choice and checks decided what to do with the char recieved
 * from match_input() */
int get_choice() {

    string input = "";
    cout << "\nPlease input your move for this round." << endl;

    while( true ) {
        cin >> input;

        _cin_clear();

        cout << endl;

        /* While I get user input as a string, I do not let it stay that way.
         * This way I can get creative by using the players or the computers
         * option as an index for all sorts of cool stuff such as using the
         * number as the index value of an array to retrieve. */
        switch(match_input(input)) {
            case 'r':
                    return 0;
            case 'p':
                    return 1;
            case 's':
                    return 2;
            case 'q':
                    cout << "Exiting game";
                    exit(0);
            default:
                    cout << "That is not Rock, Paper, or Scissors\n"
                            "please try again. "
                            "You may also type 'quit' to exit." << endl;
        }
    }
}

/* Uses a list of items as comparison to see if what the user entered is valid
 * then returns the first letter of what the user entered. */
char match_input(string input) {

    char output;

    /* Sets of words to use for validation and matching. These will be compared
     * to user input. */
    std::vector<string> ops = {"rock","paper","scissors","quit","yes"};

    /* Gets length of string and stores it in an int for easy comparison.*/
    const int len = ops.size();
    for( int x=0;x<len;x++ ) {

        /* Checks if first character or whole word. Must be one or the other,
         * but no partial matches. Can be any case or mix of lower and
         * uppercase.*/
        if( _to_lower(input) == ops[x] or
                _to_lower(input) == string(1, ops[x][0] )) {
            output = ops[x][0];
            break;
        }
        else output = '0';
    }
    return output;
}

/* Checks for three win types and a tie. Checking for these means there is only
 * one set of combos left and they all result in player 1 winning. */
void round_winner(int p1,int p2,int& p1s,int& p2s) {
    int win;
    std::vector<string> c = {"Rock","Paper","Scissors"};

    if( p1 == p2 ) // Tie
        win = 0;
    /* r=0 p=1 s=2 */
    else if( p1 == 0 and p2 == 1 ) /* Paper beats Rock. */
        win = 2;
    else if( p1 == 1 and p2 == 2 ) /* Scissors beats Paper. */
        win = 2;
    else if( p1 == 2 and p2 == 0 ) /* Rock beats Scissors. */
        win = 2;
    else win = 1; /* All other possible combinations are a win for player 1. */

    /* Players choice acts as index for the vector above to display the choice
     * from each player. */
    cout << "Player 1 chooses " << c[p1]
        << " and Player 2 chooses " << c[p2] << endl;

    if( win == 2 ) {
        cout << c[p2] << " beats " << c[p1] << endl;
        cout << "Player 2 wins" << endl;
        p2s++;
    }
    if( win == 1 ) {
        cout << c[p1] << " beats " << c[p2] << endl;
        cout << "Player 1 wins" << endl;
        p1s++;
    }
    if( win == 0 ) {
        cout << c[p1] << " matches " << c[p2] << endl;
        cout << "It's a draw" << endl;
    }
}

/* Just gets a random number for use by the bot. No need to use a char as it
 * would just be converted to number anyway. */
int get_bot() {
    return rand() % 3;
}

/* Ask the player if they would like to play again. Uses match_input so the
 * player is free to put in y or yes however they want and it will still be
 * accepted. */
bool play_again() {
    cout << "Would you like to play again?" << endl;
    string again;
    cin >> again;
    _cin_clear();

    /* match_input() only returns the first letter of a word but the user must
     * input either the full word or the first letter in order to match. */
    return (match_input(again) == 'y')?true:false;
}

/* Compare score to find match winner. Also making it a habit to pass by
 * constant reference when there is no need for the function to be changing it.
 * Should help prevent any accidents in the future. */
void game_winner(const int& p1s, const int& p2s, const int& round) {

    if( p1s > p2s )
        cout << "You won this match!\n"
            << "The final score is " << p1s << " to " << p2s
            << "\nCongratulations on your win!" << endl;
    else
        cout << "You have lost this match.\n"
            << "The final score is " << p1s << " to " << p2s
            << "\nBetter luck next time." << endl;

    cout << endl;
    cout << "The game lasted " << round << " rounds." << endl;
}
