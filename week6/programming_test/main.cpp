#include <iostream>

using namespace std;

int main()
{

    string input = "";
    string newout = "";
    cout << "Please input one of the items listed below." << endl
        << "The input is case sensitive." << endl;
    cout << endl
        << "turtle" << endl
        << "tree" << endl
        << "tin" << endl
        << endl
        << "Input: ";
    cin >> input;

    cout << "You input " << input << ". That is ";
    if( input == "turtle") cout << "an animal.";
    else if( input == "tree") cout << "a plant.";
    else if( input == "tin") cout << "a mineral.";
    else cout << "not match one of the items on the list.";

    return 0;
}
