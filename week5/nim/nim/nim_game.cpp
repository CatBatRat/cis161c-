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

struct settings {
    int start;
    int remaining;
    int player;
    int type;
    int turn=1;
};


void _menu(settings&);
int _player(settings&, int type=1);
void _print_center(vector<string>& tocenter, int width=68, char sfill='=');
int _bot( int rem, int level );
void _win(settings&);
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
            cout << endl << std::setw(sets.remaining) << std::setfill('|') << "";
            cout << " " << sets.remaining << endl;
            if( sets.turn == 1 )
                sets.remaining -= _player( sets );
            else
                sets.remaining -= _player( sets, sets.type );
            cout << sets.remaining << endl;
            if( sets.remaining <= 0 ) _win(sets);
            else sets.turn = ( sets.turn == 1 )?2:1;
        } while ( sets.remaining > 0 );
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
        else
        {
            choice = _validate(choices);
        }
        cout << "Player " << type << " chooses " << choice << endl;
    }
    else
    {
        choice = _bot(sets.remaining, type);
        cout << "Player 2 bot chooses " << choice << endl;
    }
    return choice;
}

int _bot( int rem, int type )
{
    int choice;
    if ( type == 2 )choice = rand()%3+1;
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
    };
}

void _win(settings& sets)
{
    string winner = "Player " + std::to_string(sets.turn) + " wins!";
    vector<string> congrats {
        winner,
        "Congratulations to both players on a good game!"
    };
    _print_center(congrats,50,'*');
}

int _validate(vector<string>& check,int limit)
{
    int option;
    if( limit == 0 ) limit=check.size();
    else limit = limit+1;
    while(true)
    {
        cout << endl << check[0] << endl;
        for( int x=1;x<limit;x++ )
        {
            cout << x << " ";
            cout << check[x] << endl;
        }
        cin >> option;
        if( option > 0 and option <= limit-1 ) return option;
        else
        {
            cout << "You must input a number from the list" << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

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

