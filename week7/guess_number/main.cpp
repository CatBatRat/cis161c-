#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <vector>
#include "qolife.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int START = 10;

void intro();
int get_input();
int check_input(int,int,int);
bool play_again();

/* Still working on keeping main() as clean as possible. Idealy I
 * want to have it be nothing but a loop, function calls, and variables.
 * I am getting closer, trimming the fat and all, but it does require
 * a shift in my way of thinking. */
int main() {
    std::srand(std::time(0));
    intro();
    do {
		// Set the starting random number between 1 and 99.
        int number = rand() % 99 + 1;
        int tries = 1;
        int input = 0;
        int score = START;
        cout << "I'm thinking of a number between 1 and 99" << endl;
        do {
            cout << "\nPlayer score = "<< score << endl;
            input = get_input();
            score = check_input(input,number,score);
            tries++;
		// While score above zero (loss) and input != number (win)
        } while( score > 0 and input != number );
		// Bit of a snarky comment from the computer
		// thought I would have a little fun with this
        if( score < 1 ) cout << "\nYou have failed to read my mind.\n"
                                "You have a long way to go before you're\n"
                                "ready for more than card tricks.\n" << endl;
		// Make sure to display the final score and number of tries
        cout << "Your final score is " << score
             << "\nand it took you " << tries << " tries." << endl;
    // Use the play again function to see if the game should continue
    }while( play_again() == true );

    return 0;
}

void intro() {
    std::vector<string> hello = {
        "Greetings, aspiring psychics!",
        "Your goal is to read my mind while",
        "I tell you how wrong you are!"
    };
    _print_center( hello,50,300,'_' );
    cout << endl;
    std::string s = std::to_string(START);
    std::vector<string> ins = {
        "This is a simple mind reading game.",
        "A number will be selected at random and",
        "you will attempt to read my mind to find",
        "the answer you seek. You will be given",
        s+" points to start but you will lose points",
        "with every wrong guess! There is a bonus",
        "for ending with 5 or more points."
    };
	/* Made some changes to my _print_center function. Now I can
	 * provide optional left and right fill characters. Later I
	 * Plan to change this to used function overloading. Then calls
	 * will be much simpiler. */
    _print_center( ins, 50, 300, '{','}' );
    _wait_enter();
}

int get_input() {
    int input;
    _scroller("Tell me what number I'm thinking.","right");
    bool exit = false;
    do {
        cout << endl;
        cout << "Answer : ";
        cin >> input;
        _cin_clear();
        if( !(input) or input > 99 or input < 1 )
            cout << "That is not a valid answer. Try again." << endl;
        else exit = true;
    } while( !(exit) );
    return input;
}

int check_input(int input, int number, int score) {
    if( input < number ) {
        if( number - input < 10 ) {
            cout << "Your less than 10 lower, so I'll only take one point." << endl;
            score -= 1;
        }
        else {
            cout << "Your way lower, two points taken." << endl;
            score -= 2;
        }
    }
    else if( input > number ) {
        if( input - number < 10 ) {
            cout << "Your less than 10 higher, so I'll only take one point." << endl;
            score -= 1;
        }
        else {
            cout << "Your way higher, two points taken." << endl;
            score -= 2;
        }
    }
    else {
        cout << "You read my mind!";
        if( score < 5 ) cout << " Took you long enough, but you got it.";
        else {
            cout << "\nHere's a bonus for doing it so fast!" << endl;
            cout << score << " + 5" << endl;
            score += 5;
        }
        cout << endl;
    }
    return score;
}

bool play_again() {
    std::string play;
    cout << "Would you like to play again? (yes/no)" << endl;
    cin >> play;
    play = _to_lower(play);
    if( play == "yes" ) return true;
    else return false;
}
