// vim: set autochdir:
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char math;
    int num1, num2;
    double out;

    cout << "Please enter two integers.\n";
    cout << "First number: "; cin >> num1;
    cout << "Second number: "; cin >> num2;
    cout << "And what kind of math operation\n"
        "would you like to perform?\n";
    cout << " *,/,%,+,- : "; cin >> math;
    if(math == '/') {
        if(num2 != 0) {
            cout << fixed << showpoint << setprecision(2);
            out = static_cast<float>(num1)/static_cast<float>(num2);
        }
        else cout << "Can't divide by zero!";
    }
    if(math == '*') { out = num1 * num2; }
    if(math == '%') { out = num1 % num2; }
    if(math == '+') { out = num1 + num2; }
    if(math == '-') { out = num1 - num2; }

    cout << out;

}
