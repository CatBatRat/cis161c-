// vim: set autochdir:
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Define variables
    char op;
    int num1, num2;
    double out;

    // Display instructions
    cout << "Please enter two integers, separated by an operator,\n"
            "with spaces in between.\n\n"
            " Example: 2 + 2\n\n"
            " + = Add\n"
            " - = Subtract\n"
            " * = Multiply\n"
            " / = Divide\n"
            " % = Modulo\n"
            " \n ";

    // Capture all needed values on a single line
    // separated by spaces
    cin >> num1 >> op >> num2;

    // Check if division and check for 0 in the second value
    // and perform division if not 0, else display error.
    if(op == '/') {
        if(num2 != 0) {
            cout << fixed << showpoint << setprecision(3);
            out = static_cast<float>(num1)/static_cast<float>(num2);
        }
        else cout << "Can't divide by zero!";
    }
    if(op == '*') { out = num1 * num2; }
    if(op == '%') { out = num1 % num2; }
    if(op == '+') { out = num1 + num2; }
    if(op == '-') { out = num1 - num2; }

    cout <<" "<<num1<<" "<<op<<" "<<num2<<" = "<<out;

    return 0;
}
