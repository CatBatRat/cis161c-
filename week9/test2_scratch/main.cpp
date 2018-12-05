/*#include <iostream>
// Missing <string> in order for adder to work.
#include <string>

using namespace std;

// There was a semicolon at the end this line.
// Needs to return a string.
string adder(string word1, string word2)
{

    return word1 + word2;

}

int main()
{

    cout << adder("dog ","cat") << endl;

    return 0;

}
*/

#include <iostream>

using namespace std;

// this program prints the sum of the numbers if called with two arguments

// if called with one argument, it returns the negative of that value

// Default arguments must be from right to left.
int myfunction(int, int = 0);

int main()

{

    int a = 4, b = 5;

    cout << myfunction(a,b) << endl;

    return 0;

}

// Already prototyped but had a semicolon.
int myfunction(int value1, int value2)

{

    // Since value2 is now the default of 0 must change value1 to value2.
    if ( value2 == 0 )

        return -1 * value1;

    return value1 * value2;

}

/*#include <iostream>

using namespace std;

//This program doubles the value it is called with

// using pass by reference

// Must take the reference to a variable.
void myfunction(int value, int& change)

{

    change = value * 2;

}

int main()

{
    int a;

    // Must pass a reference to 'a' if there is to be a
    // change made to it in a void function.
    myfunction(4, a);



    cout << a << endl;



    return 0;

}*/

/*#include <iostream>

using namespace std;

int getNumber();
int area(int side);
int area(int length, int width);

int main()

{

    cout << "Enter length and width of a rectangle: ";

    int length = getNumber();

    int width = getNumber();

    cout << "Its area is " << area(length, width) << endl;

    

    cout << "Enter the side of a square ";

    int side = getNumber();

    cout << "Its area is " << area(side) << endl;

    

    return 0;

}

int getNumber() {
    int value;
    cin >> value;
    cin.clear();
    cin.ignore(100000, '\n');
    return value;
}

// area square.
int area(int side) {
    return side * side;
}

// area rectangle.
int area(int length, int width) {
    return length * width;
}*/
