#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "qolife.h"

using std::cout; using std::cin; using std::endl;

const int MIN = 1, MAX = 100;
//const std::string regex_match_string = R"((r|p|s|q)(ock|aper|cissors|uit)?)";

void intro();
char match_input(std::string input);
int get_choice();
int get_bot();
int round_winner(int,int);
void game_winner(int,int);
bool playAgain();

int main()
{
    srand(time(0));
    intro();
    do {
        int round = 1;
        int win = 0;
        int p1s = 0, p2s = 0; // Player 1 and Player 2 score.
        while( p1s + p2s < 5 ) {
            cout << endl;
            cout << "Please select your move for this round." << endl;
            // Show the intro and instructions to the user
            int choice = get_choice();
            win = round_winner(choice,get_bot());
            if( win == 1 ) {cout << "Player 1 wins" << endl;p1s++;}
            else if( win == 0 ) {cout << "Player 2 wins" << endl;p2s++;}
            else cout << "It's a draw" << endl;
            round++;
            cout << "::Score::\n"
                 << "   Player 1: " << p1s << endl
                 << "   Player 2: " << p2s << endl;
        }
        cout << endl;
        game_winner(p1s,p2s);
        cout << "The game lasted " << round << " rounds." << endl;
    } while(playAgain() == true);

    cout << "Goodbye!" << endl;

    return 0;
}

void intro() {
    std::vector<std::string> intro = {
        "This is the game of Rock/Paper/Scissors!",
        "You will play against a computer opponent, but he",
        "isn't very smart. Try to go easy on the poor guy.",
        "Rock beats Scissors, Scissors beats Paper, Paper beats Rock.",
        "Best out of five, wins!"
    };
    _print_center(intro, 62, 300, ' ');
}

int get_choice() {
    std::string input = "";
    char choice = '0';
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

/* I was using a regex match here but I found that my own method was muthc
 * simplier and I didn't have to wait so long for the program to compile and
 * run as my method is several orders of magnitude faster. */
/*char match_input(std::string input) {
    using namespace std::regex_constants;
    std::regex matcher(regex_match_string,icase);
    std::smatch output;
    std::regex_match(input,output,matcher);
    if( output.empty() ) return '0';
    char result = static_cast<std::string>( output[1] )[0];
    result = std::tolower(result);
    return result;
}*/

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

int round_winner(int p1,int p2) {
    int win;
    std::vector<std::string> c = {"Rock","Paper","Scissors"};
    if( p1 == p2 ) win = 3;
    // r=0 p=1 s=2
    else if( p1 == 0 and p2 == 1 ) win = 0;
    else if( p1 == 1 and p2 == 2 ) win = 0;
    else if( p1 == 2 and p2 == 0 ) win = 0;
    else win = 1;
    cout << "Player 1 chooses " << c[p1] << " and Player 2 chooses " << c[p2] << endl;
    if( win == 0 ) cout << c[p2] << " beats " << c[p1] << endl;
    if( win == 1 ) cout << c[p1] << " beats " << c[p2] << endl;
    if( win == 3 ) cout << c[p1] << " matches " << c[p2] << endl;
    return win;
}

int get_bot() {
    return rand() % 3;
}

bool playAgain() {
    cout << "Would you like to play again?" << endl;
    std::string again;
    cin >> again;
    _cin_clear();
    return (match_input(again) == 'y')?true:false;
}

void game_winner(int p1, int p2) {
    if( p1 > p2 )
           cout << "You won this match!" << endl
                << "The final score is " << p1 << " to " << p2 << endl
                << "Congratulations on your win!" << endl;
    else   cout << "You have lost this match." << endl
                << "The final score is " << p1 << " to " << p2 << endl
                << "Better luck next time." << endl;
    cout << endl;
}
