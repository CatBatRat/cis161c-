// vim: set autochdir:
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    double input;
    cout << "Please input the total transaction amount.\n"
    "Amount: "; cin >> input;

    // Set base threshold values
    const double base1 = 100000, base2 = 300000;
    // Set commission percentage rates.
    const double rate0 = 0.05, rate1 = 0.10, rate2 = 0.15;
    // Set commission base ammount per level
    const double com1 = 5000, com2 = 25000;

    cout << fixed << showpoint << setprecision(2);
    cout << endl << "Your commission for this sale is $";

    // Start at highest point and work down
    if( input >= base2) { cout << (input - base2) * rate2 + com2; }
    else if( input >= base1 ) { cout << (input - base1) * rate1 + com1; }
    else { cout << (input * rate0); }


    return 0;
}
