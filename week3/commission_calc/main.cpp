// vim:autochdir:
#include <iostream>
#include <iomanip>


/* I think I got a little carried away with this one. I really liked the idea
 * of the calculations being done on-the-fly and there being no limit to the
 * number of levels this code can calculate.
 *
 * I am pretty happy with the result, as I can add an arbitrary number of
 * additional bases and rates and they will still be properly calculated.*/

using namespace std;

int main() {
    #define BS(a,b) (a[b+1]-a[b])
    // Base amounts at which interest levels change.
    const double BASES[] = {0, 100000, 300000};
    // Number of interest levels MUST match number of bases!
    // Each level applies to the amount OVER the previous BASE
    // remember, these are cumulative.
    const double RATES[] = {0.05, 0.10, 0.15};

    // define variables
    double input, output;

    // Variables for:
    // - RATES array length
    // - Controlling entry into the second while loop
    // - Tracking number of loops in relation to RATES array length
    int rl, tr = 0;
    bool go = true;


    // Get number of elements in the "RATES" array
    rl = sizeof(RATES)/sizeof(RATES[0]);
    // I wonder why there is not something like the
    // String object property for length with arrays.

    // Set display of any following numbers
    cout << fixed << showpoint << setprecision(2);
    cout << "Please input the total transaction amount\n"
            "from your sale to calculate your commission.";
    // Enter main while loop
    while(true) {
        output = 0; tr = 0;
        cout << "\nAmount: ";
        cin >> input;
        cout << flush;
        system("clear");
        // Exit program upon entering 0
        if( input == 0 ) return 0;
        // Set go = 0 upon negative number entry
        if( input <= 0 ) {
            go = false; cout << "\nPlease enter a positive value\n";
        }
        while(go) {
            if( input <= BS(BASES,tr) or tr == rl-1 ) {
                output += input * RATES[tr];
                break;
            }
            if( input > BASES[tr] ) {
                output += BS(BASES,tr)*RATES[tr];
                input -= BS(BASES,tr);
            }
            tr++;
        }
        if ( go == true ) {
            cout << endl << "Your commission for a sale of " << input <<
                            "\nis $ " << output << endl;
        }
        go = true;
        cout << "\nYou may now enter another sale amount,\n"
                "or you may input a '0' to exit";

    }
    return 0;
}
