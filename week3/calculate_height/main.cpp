#include <iostream>

using namespace std;

int main(){
    int total = 0, feet, inches;

    cout << "Please enter your hight in feet, then inches\n";

    cout << "\nfeet:   ";cin >> feet;
    cout << "\ninches: ";cin >> inches;

    cout << "\n\nAt " << feet << " feet " << inches <<
    " inches, you are a total of " << (feet*12)+inches <<
    " inches tall\n\n";

    return 0;
}
