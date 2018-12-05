#include <iostream>

using namespace std; //used as so not have to put"std::" in front of all the variables (search the library for used variables)

int main()
{
    //variables = holders for values
    //type = what type of info stored
   int age; //int stands for intiger (positive or negitive whole values)
   string name; //string = a line of text

    cout << "May I have you first name?" << endl; // endl = end line
    cin >> name; //cin = console input

    cout << "May I have your age?" << endl;
    cin >> age;

    cout << "Hello " << name << "!" << endl;//cout = command output
    cout << "Nice to meet you!" << endl;
    cout << "You are looking pretty good for " << age << "." << endl;

    return 0;
}
