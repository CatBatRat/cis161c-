// vim:set autochdir:

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int validate(vector<string>& check)
{
    int option;
    while(true)
    {
        cout << endl << "Please input the number of you selection." << endl;
        for( int x=0;x<check.size();x++ )
        {
            cout << x+1 << " ";
            cout << check[x] << endl;
        }
        cin >> option;
        cout << flush;
        system("clear");
        if( option > 0 and option <= check.size() ) return option;
        else
        {
            cout << "You must input a number from the list" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}

int main()
{
    char option;
    vector<string> values = {
        "Single player against a bot.",
        "Multiplayer against a friend.",
        "Quit the game."
    };
    option = validate(values);
    switch(option)
    {
        case 1:
            {
                cout << "Here We Goooo!";
            }
    }
    return 0;
}
