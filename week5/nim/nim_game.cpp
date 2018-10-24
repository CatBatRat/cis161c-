// vim:set autochdir:

/*#include <iostream>
#include <string>
using namespace std;
void startup(std::string&);
void outputfile(std::string);
int main()
{
    std::string filename;
    startup(filename);
    outputfile(filename);
}   
void startup(std::string& name)
{
    cin >> name;
}
void outputfile(std::string name)
{
    cout << name;
}*/
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <sstream>


using std::cout; using std::cin; using std::endl;
using std::string;

int _bot( int current, int level );
int _human();

struct settings {
    int start;
    int level;
    int players;
};

void _menu(settings&);

int main()
{
    srand(time(0));
    settings sets;
    _menu(sets);
    int remaining;

    remaining = sets.start;

    do {
        remaining -= _human();
        cout << "now at " << remaining << endl;
        //
        remaining -= _bot( remaining, sets.level );
        cout << "now at " << remaining << endl;
        //
    } while ( remaining > 0 );

    return 0;
}

int _human()
{
    int choice;
    while ( true )
    {
        cout << "Pick a number between '1' and '3'\n"
                "Choice = ";
                cin >> choice;
        if ( choice <= 3 and choice > 0 )
        {
            cout << "You choose " << choice << endl;
            return choice;
        }
            cout << "That is not between '1' and '3'\n\n";
            cin.clear();
            cin.ignore();
            choice = 0;
    }
}

int _bot( int current, int level )
{
    int choice;
    if ( level == 1 )choice = rand()%3+1;
    if ( level == 2 )
    {
        if( current%4 != 0 ) choice = current%4;
        else choice = rand()%3+1;
    }
    cout << "The computer chooses " << choice << endl;
    return choice;
}

struct screen {
    string intro[100] = {
        "Welcome to the game of Nim!",
        "This is a game of numbers and cunning!",
        "Can you master the math and come out victorious?"};
};

void _menu(settings& item)
{
    screen text;
    int center;
    for ( int x; x<sizeof(text.intro)/sizeof(text.intro[0]);x++ )
    {
        char sfill = '=';
        string line = text.intro[x];
        center = (68/2)-(text.intro[x].length()/2);
        line.replace(0, 0, center, sfill);
        cout << std::left << std::setfill(sfill);
        cout << std::setw(68) << line << endl;
    }

    item.level = 2;
    item.start = rand()%20 + 12;
    item.start = 21;
}

