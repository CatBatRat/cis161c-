#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "qolife.h"

using std::cout; using std::cin; using std::endl;

void intro();

char match_input(std::string input);

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
 * aren't scattered all over the and there is no need to unravel what is going
 * on or unwind some complex task in order to make a small change. */
int main()
{
    int round;
    int p1s, p2s; // Player 1 and Player 2 score.
    srand(time(0));
    // Show the intro and instructions to the user
    intro();
    do {
        round = 1;
        p1s = 0; p2s = 0; // Player 1 and Player 2 starting score.
        while( p1s + p2s < 5 ) {
            round_winner( get_choice(), get_bot(), p1s, p2s );
            round++;
            cout << "::Score::\n"
                 << "   Player 1: " << p1s << endl
                 << "   Player 2: " << p2s << endl;
        }
        cout << endl;
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

int get_choice() {
    std::string input = "";
    char choice = '0';
    cout << "\nPlease select your move for this round." << endl;
    while( true ) {
        cin >> input;
        _cin_clear();
        cout << endl;
        choice = match_input(input);
        switch(choice) {
            case 'r': return 0;
            case 'p': return 1;
            case 's': return 2;
            case 'q':
                      cout << "Exiting game";
                      exit(0);
            default:  cout << "That is not rock, paper, or scissors" << endl
                           << "please try again. You may also type 'quit' to exit." << endl;
        }
    }
}

/* Uses a list of items as comparison to see if what the user entered is valid
 * then returns the first letter of what the user entered. */
char match_input(std::string input) {
    char output;
    std::vector<std::string> ops = {"rock","paper","scissors","quit","yes"};
    int len = ops.size();
    for( int x=0;x<len;x++ ) {
        if( _to_lower(input) == ops[x] or
                _to_lower(input)[0] == ops[x][0]) {
            output = ops[x][0];
            break;
        }
        else output = '0';
    }
    return output;
}

/* Checks for three win types and a type. Checking for these means there is only
 * one set of combos and they all result in player 1 winning. */
void round_winner(int p1,int p2,int& p1s,int& p2s) {
    int win;
    std::vector<std::string> c = {"Rock","Paper","Scissors"};
    if( p1 == p2 )
        win = 3;
    // r=0 p=1 s=2
    else if( p1 == 0 and p2 == 1 )
        win = 0;
    else if( p1 == 1 and p2 == 2 )
        win = 0;
    else if( p1 == 2 and p2 == 0 )
        win = 0;
    else win = 1;
    cout << "Player 1 chooses " << c[p1] << " and Player 2 chooses " << c[p2] << endl;
    if( win == 0 ) {
        cout << c[p2] << " beats " << c[p1] << endl;
        cout << "Player 2 wins" << endl;
        p2s++;
    }
    if( win == 1 ) {
        cout << c[p1] << " beats " << c[p2] << endl;
        cout << "Player 1 wins" << endl;
        p1s++;
    }
    if( win == 3 ) {
        cout << c[p1] << " matches " << c[p2] << endl;
        cout << "It's a draw" << endl;
    }
}

int get_bot() {
    return rand() % 3;
}

bool play_again() {
    cout << "Would you like to play again?" << endl;
    std::string again;
    cin >> again;
    _cin_clear();
    /* match_input() only returns the first letter of a word but the user must
     * input the either the full word or the first letter in order to match. */
    return (match_input(again) == 'y')?true:false;
}

// Compare score to find match winner.
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
