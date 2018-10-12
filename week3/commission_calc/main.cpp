// vim: set autochdir nowrap:
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    /* Base price for change in commission rate. */

    double input;
    cout << "Please input the total transaction amount.\n"
    "Amount: "; cin >> input;

    // Set commission percentage rates.
    const double
        base = 100000,
        rate1 = (input * 0.05),                    // 5%  of sale
        rate2 = (input - base) * 0.10 + 5000,      // 10% of sale + 5000
        rate3 = (input - base * 3) * 0.15 + 25000; // 15% of sale + 25000
    const string o_template = "Your commission for this sale is $ ";

    cout << fixed << showpoint << setprecision(2);
    cout << endl << "Your commission for this sale is $";
    // Start at highest point and work down
    if( input >= base * 3) {
        cout << rate3;
    }
    else if( input >= base ) {
        cout << rate2;
    }
    else {
        cout << rate1;
    }


    return 0;
}
