#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float F, C;
    cout << "What is the current temperature in Fahrenheit?" << endl;
    cin >> F;
    C = (F-32)*5/9;
    cout << "The Fahrenheit temperature you entered, converted to Celsius, is " << setprecision(2) <<
        C << " degrees Celsius.";
    return 0;
}
