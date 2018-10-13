// vim: set autochdir:
#include <iostream>
#include <iomanip>
#include <stdio.h>

/* I think I got a little carried away with this one.
 * I really liked the idea of the calulations being done
 * on the fly and there being no limit to the number of
 * levels this code can calulate.*/

using namespace std;

int main() {
    // Base amounts at which interest levels change.
    const double BASES[] = {0, 100000, 300000};
    // Number of interest levels MUST match number of bases!
    // Each level applies to the amount OVER the previous BASE;
    // remember, these are cumlative.
    const double RATES[] = {0.05, 0.10, 0.15};

    // define variables
    double input, output;

    // Variables for:
    //  RATES array length
    //  Controlling intry into the second while loop
    //  Tracking number of loops in relation to RATES array length
    int rl, go = 1, tr = 0;

    // Get number of elements in the "RATES" array
    rl = sizeof(RATES)/sizeof(RATES[0]);
    // I wonder why there is not something like the
    // String object property for length with arrays.

    // Set display of any following numbers
    cout << fixed << showpoint << setprecision(2);

    while(1) {
    // Hardcoded value for testing
    //input = 400000;
    cout << "Please input the total transaction amount\n"
        "from your sale to calulate your commission.\n"
    "Amount: "; cin >> input;
    // Exit program upon entering 0
    if( input == 0 ) return 0;
    // Set go = 0 upon negative number entry
    if( input <= 0 ) {
        go = 0; cout << "Please enter a positive value\n";
        break;
    }
    else break;
    }

    while(go) {
        if( input < BASES[tr+1]-BASES[tr] or tr == rl-1 ) {
            output += input * RATES[tr];
            cout << endl << "Your commission for this sale is $";
            cout << output << endl;
            break;
        }
        if( input > BASES[tr] ) {
            if( tr == rl ) break;
            output += (BASES[tr+1]-BASES[tr])*RATES[tr];
            input -= (BASES[tr+1]-BASES[tr]);
        }
        else break;
        tr++;
    }

    return 0;
}
