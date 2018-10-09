#include <iostream>

using namespace std;

int main()
{
    int one,two,three;

    cout << "Enter three integers" << endl;
    cin >> one >> two >> three;
    if(one < two && three){
        cout << "The first number you entered is the smaller number\n";
        cout << one << " is smaller than " << two << endl;
    }
    else if(two < one && three){
        cout << "The second number you entered is the smaller number\n";
        cout << two << " is smaller than " << one << endl;
    }
    else if(three < one && two){
        cout << "The third number you entered is the smaller number\n";
        cout << two << " is smaller than " << one << endl;
    }
    else{
        cout << "All the numbers are equal\n";
        cout << one << " = " << two << " = " << three << endl;
    }
    return 0;
}
