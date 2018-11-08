#include <iostream>
#include <array>
#include "qolife.h"

using std::cout; using std::cin; using std::endl;

void intro(); int getInput(); int getBot(); int roundWinner(int,int); bool playAgain(); void gameWinner();

int main()
{
    //int p1 = 0, p2 = 0;
    // Show the intro and instructions to the user
    intro();
    // Get input from user
    //pChoice = getInput();
    // Get choice from bot
    //bChoice = getBot();
    // Check round winner
    //int roundWinner()
    // Count number of wins
    std::string test = "ThIs Is A tEsT";
    cout << "Can you see what comes after me? " << _to_lower(test);

    // Check if play again
    // Declare the overall winner
    _wait_enter();
    return 0;
}

void intro() {
    cout << "This is the game of Rock/Paper/Scissors!\n"
            "You will play against a computer opponent, but he isn't very smart.\n"
            "Try to go easy on the poor guy.\n\n"
            "Rock beats Scissors, Scissors beat Paper, and Paper Beats Rock\n"
            "Best out of five wins!" << endl;
}
