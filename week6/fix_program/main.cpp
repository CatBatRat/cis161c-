/*#include <iostream>

// Needs a using namespace std
using namespace std;

int main()
{
      // This program should read in two numbers
      // and output the largest one of them.

    int num1=0, num2=0, largest=0;

    cout << "Enter two integers" << endl;

    // '>>' is reversed and the comma should be a '>>' operator is reversed
    cin >> num1 >> num2;

    // No largest and can't have ';' after an if statement
    if ( num1 > num2 )
    {
        largest = num1;
    }
    else
    {
        largest = num2;
    }

    // Missing an '<<'
    cout << "The largest is " << largest << endl;

    return 0;

}*/
#include <iostream>

using namespace std;

int main()
{

    // Initialize 'index' at 1
    int index = 1;

    const int LIMIT = 10;

    // Should not be a ';' after the while loop
    // Also make '<=', or set LIMIT at 11, or use a 'do while', or prefix '++index' in the while condition and intialize 'index' at 0.
    while ( index <= LIMIT )
    {

        cout << index * index << endl;
        // Should increment not decrement
        index++;

    }

    return 0;
}
