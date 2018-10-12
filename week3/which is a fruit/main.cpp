#include <iostream>

using namespace std;

int main()
{
    string answer;
    cout << "Which is a fruit? An apple or a potato?" << endl;
    cout << "Answer: "; cin >> answer;
    if( answer == "apple" )
        cout << "That is correct and apple is a fruit.";
    else if( answer == "potato" )
        cout << "A potato is not a fruit";
    else
        cout << answer << " was not one of the choices.";
    return 0;
}
