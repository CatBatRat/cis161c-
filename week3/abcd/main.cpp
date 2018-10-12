#include <iostream>

using namespace std;

int main()
{
    char let;
    string thing = "";
    cout << "Please input a letter from a to b" << endl;
    cin >> let;

    if(let) {
        if( let == 'a' ) thing = "apple";
        if( let == 'b' ) thing = "bear";
        if( let == 'c' ) thing = "cat";
        if( let == 'd' ) thing = "dog";
        if( thing != "") cout << "You entered the word " << let << " for " << thing;
        else cout << "\n\nError, that is not one of the letters you can enter.";
    }


    return 0;
}
