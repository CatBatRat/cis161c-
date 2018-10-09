/* Import the library that handles input/output streams */
#include <iostream>

/* Set the namespace to use std so that cout,cin...etc
don't have to prepend with std */
using namespace std;

#define x = 55

int main()
{
    /* Initiate an empty string and integer */
    string name;
    int age;


    /* Ask the user their name and store the input */
    cout << "What is your name?" << endl << "name: ";
    cin >> name;
    cout << endl;

    /* Ask the user their age and store the input */
    cout << "How old are you?" << endl << "age: ";
    cin >> age;
    cout << endl;

    /* Use the stored values to inform the user of their
    name and age */
    cout << endl << "Your name is " << name;
    cout << " and your age is " << age << "." << endl;

    return 0;
}
