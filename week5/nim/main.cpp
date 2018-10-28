// vim:set autochdir:

#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
#include <cstdio>


using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;

char clear_screen[] = "cls";
void _clear() {
    cout << std::flush;
    std::system(clear_screen);
}

/* This struct is used to store settings given at the menu so they can
 * be easily accessed later. Pass it by reference to have changes take
 * effect without having to return any data.*/
struct settings {
    // Starting number of sticks.
    int start;
    int remaining;
    /* Type of player
     * 1: Human player
     * 2: Dumb bot
     * 3: Smart bot*/
    int player;
    int type;
    int turn=1;
};


// Main menu where type of game can be set.
void _menu(settings&);
/* Player function which can act as one of Player 1, Player 2,
 * and a Bot with two difficulty settings. */
int _player(settings&, int type=1);
/* Print centered text to the screen. I plan to make this adaptable
 * and able to take more kinds of data.*/
void _print_center(vector<string>& tocenter, int width=68, char sfill='=');
/* This is the bot 'NPC' in this game. It has both smart and dumb
 * modes. Don't make a mistake or it will roll you to the end.*/
int _bot( int rem, int level );
/* Simply declares the winner and leaves it possible to increase
 * complexity of win conditions without having to clutter main.*/
void _win(settings&);
/* I am very proud of this one. Feed it a set of options and it will
 * ensure the user inputs the correct data before returning the value
 * entered. Number of option and value returned is based on list provided
 * meaning more options can be added and _validate will adapt to the
 * changes.*/
int _validate(vector<string>& check,int limit=0);

int main()
{
    srand(time(0));
    settings sets;
    int again;
    vector<string> intro = {
        "Welcome to the game of Nim!",
        "This is a game of numbers and cunning!",
        "Can you master the math and come out victorious?"
    }; _print_center(intro);
    do {
        _menu(sets);
        _clear();
        sets.remaining = rand()%8+12;
        cout << "The starting number is " << sets.remaining;
        do {
            // Print the current number of sticks
            cout << endl << std::setw(sets.remaining) << std::setfill('|') << "";
            cout << " " << sets.remaining << endl;
            // Call the player and subtract the output from remaining.
            if( sets.turn == 1 )
                sets.remaining -= _player( sets );
            else
                sets.remaining -= _player( sets, sets.type );
            cout << sets.remaining << endl;
            // Check for 'win'. Current method is hard-coded and requires
            // two if statements. Will create something a bit more elegant
            // later.
            if( sets.remaining <= 0 ) { _win(sets); break; }
            sets.turn = ( sets.turn == 1 )?2:1;
        } while ( sets.remaining > 0 );
        /* First example of the '_validate' function in use. The
         * corresponding number to enter will be shown next to each
         * option and it will enforce correct entry before returning
         * the value.*/
        vector<string> replay {
            "Would you like to play again?",
            "Play again",
            "Quit"
        }; again = _validate(replay);
        _clear();
    } while( again == 1 );
    return 0;
}

int _player(settings& sets, int type)
{
    int choice;
    /* If player type is '1' then entry is controlled by the player,
     * else control is passed to the bot.*/
    if( type == 1 )
    {
        vector<string> choices = {
            "Please select the number of sticks to take.",
            "Take One",
            "Take Two",
            "Take Three"
        };
        if( sets.remaining < 3 )
        {
            choice = _validate(choices,sets.remaining);
        }
        /* Determines which numbers the player can pick.*/
        else
        {
            choice = _validate(choices);
        }
        cout << "Player " << type << " chooses " << choice << endl;
    }
    else
    {
        /* Pass on the number of sticks left which is used by the bot
         * to determine how many to take, along with the type '1-2'
         * which determine how the bot will decide on the next number.*/
        choice = _bot(sets.remaining, type);
        cout << "Player 2 bot chooses " << choice << endl;
    }
    return choice;
}

int _bot( int rem, int type )
{
    int choice;
    /* This is the dumb bots AI. It will always decide using a random
     * number making it very easy to beat.*/
    if ( type == 2 )choice = rand()%3+1;
    /* This is the smart bot, It will check 'current' with modulo 4 and
     * make a random if the result is 0. Else it will use the leftover
     * amount to ensure the number presented to player is a multiple
     * of 4; making the game impossible to win if the player choice brings
     * the number of sticks to a multiple of 4.*/
    if ( type == 3 )
    {
        if( rem%4 == 0 ) choice = rand()%3+1;
        else choice = rem%4;
    }
    return choice;
}


void _menu(settings& sets)
{
    cout << endl;
    vector<string> p_type = {
        "Please select the game mode you want to play.",
        "Play against a friend.",
        "Play against a bot.",
        "Play against a challenging bot."
    }; sets.type = _validate(p_type);
    vector<string> starting = {
        /* Space holder for a method of selecting what the starting
         * number of sticks will be.*/
    };
    //item.start = _validate();
}

void _win(settings& sets)
{
    string winner = "Player " + std::to_string(sets.turn) + " wins!";
    vector<string> congrats {
        winner,
        "Congratulations to both players on a good game!"
    };
    _print_center(congrats,50,'*');
    /*cout << endl;
    cout << "Player " << sets.turn << " wins!" << endl;
    cout << "Congratulations to both players on a good game!" << endl;*/
}

/* This function uses 'vectors' which allow for a greater degree of
 * options when manipulating the contents, passing by reference, or
 * or more freedom when adding additional elements.*/
int _validate(vector<string>& check,int limit)
{
    int option;
    if( limit == 0 ) limit=check.size();
    else limit = limit+1;
    while(true)
    {
        cout << endl << check[0] << endl;
        /* Use the size (number of elements) of the vector to determine
         * how many to print and which number to show next to each option.*/
        for( int x=1;x<limit;x++ )
        {
            cout << x << " ";
            cout << check[x] << endl;
        }
        cin >> option;
        /* Compare input from the user and make sure sure only a number
         * from the list is input. The 'cin.clear()' and 'cin.ignore()'
         * is because of an infinite loop that happens when a letter is
         * input. Outside of using regular expression, is there any way
         * this situation? Also each letter will cause an additional trip
         * through the loop; I suspect because each letter entered is
         * considered as a separate integer?*/
        if( option > 0 and option <= limit-1 ) return option;
        else
        {
            cout << "You must input a number from the list" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}

/* This uses some simple math to print out some centered text and set a
 * fill character/s for each line. I will expand on this later to take
 * more options and allow for more kinds of formatting that are difficult
 * or inconvenient to achieve with the standard library.*/
void _print_center(vector<string>& tocenter, int width, char sfill)
{
    int center;
    for ( int x=0; x<tocenter.size();x++ )
    {
        int to_pad = width - tocenter[x].length();
        int left_pad = to_pad / 2;
        int right_pad = to_pad - left_pad;
        cout << std::string( left_pad, sfill )
            << tocenter[x]
            << std::string( right_pad, sfill )
            << endl;
    }
}

