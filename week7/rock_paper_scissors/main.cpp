#include <iostream>
#include <random>
#include <regex>
#include <string>
#include <vector>
#include "qolife.h"

using std::cout; using std::cin; using std::endl;

const int MIN = 1, MAX = 100;
const std::string regex_match_string
    = R"((r|p|s|q)(ock|aper|cissors|uit)?)";

void intro();
char regMatch(std::string input);
int getChoice();
int getBot();
int roundWinner(int,int);
void gameWinner();
bool playAgain();

int main()
{
    srand(time(0));
    bool quit = false,again = true;
    intro();
    do {
        int round = 0;
        int win = 0;
        int p1s = 0, p2s = 0; // Player 1 and Player 2 score.
        while( !(quit) and round < 5 ) {
            // Show the intro and instructions to the user
            int choice = getChoice();
            win = roundWinner(choice,getBot());
            if( win == 1 ) {cout << "Player 1 wins" << endl;p1s++;}
            else if( win == 0 ) {cout << "Player 2 wins" << endl;p2s++;}
            else cout << "It's a draw" << endl;
            round++;
            cout << "::Score::\n"
                 << "   Player 1: " << p1s << endl
                 << "   Player 2: " << p2s << endl;
        }
    } while(playAgain());
    // Get input from user
    //pChoice = getInput();
    // Get choice from bot
    //bChoice = getBot();
    // Check round winner
    //int roundWinner()
    // Count number of wins

    // Check if play again
    // Declare the overall winner
    return 0;
}

void intro() {
    cout << "This is the game of Rock/Paper/Scissors!\n"
            "You will play against a computer opponent, but he isn't very smart.\n"
            "Try to go easy on the poor guy.\n\n"
            "Rock beats Scissors, Scissors beat Paper, and Paper Beats Rock\n"
            "Best out of five wins!" << endl;
}

int getChoice() {
    std::string input = "";
    char choice = '0';
    do {
    std::getline(cin, input);
    choice = regMatch(input);
    if( choice == '0' )
        cout << "That is not an option," << endl
        << "please try again." << endl;
    } while( choice == '0' );
    switch(choice) {
        case 'r': return 0;
        case 'p': return 1;
        case 's': return 2;
    }
    return 3;
}

char regMatch(std::string input) {
    using namespace std::regex_constants;
    std::regex matcher(regex_match_string,icase);
    std::smatch output;
    std::regex_match(input,output,matcher);
    if( output.empty() ) return '0';
    char result = static_cast<std::string>( output[1] )[0];
    result = std::tolower(result);
    return result;
}

int roundWinner(int p1,int p2) {
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

int getBot() {
    return rand() % 3;
}

bool playAgain() {
    cout << "Would you like to play again?" << endl;
    char again;
    cin >> again;
    return (again == 'y')?true:false;
}
