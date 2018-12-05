/*#include <iostream>

// Needs the using statement
using namespace std;

// y should have the default value
int multiply(int x, int y = 3);

int main()
{
    int length, width, area;

    cout << "Enter length and width of a rectangle ";
    cin >> length >> width;

    // declared as void
    area = multiply(length, width);

    cout << "The area is " << area << endl;

    // no need for separate function as there is a default value for the second argument
    area = multiply(width);

    cout << "The second area is " << area << endl;

    return 0;
}

// returns value but set as void, also has a semicolon, and there should not be
// a default value here as there is already one in the function declaration
int multiply(int x, int y)
{
    return x * y;
}*/

/*#include <iostream>

using namespace std;

// missing semicolon
bool is_prime(int value);

// This program prints out the first 10 odd primes

int main()

{

    int value = 3;

    // should be initialized or may start with whatever is at memory address
    int counter = 0;

    // should not have a semicolon
    while( counter < 10 )

    {

        // should be not
        if ( ! is_prime(value) )

        {

            cout << counter << " " << value << endl;

            counter++;

        }

        value +=2;

    }

    return 0;

}

bool is_prime(int value)

{

    // for loop does not guard, and should increment by one or incorrect values will be printed
    for(int i = 2; i < value / 2; i++)
    {
        if ( value % i == 0 )

            return true;
    }

    return false;

}*/

//Write a simple program that asks the user for a count of how many numbers
//will be input, then inputs that many integers, adds them up, and calculates
//the average.
//
//You must write a function that is used to input each number and verifies that
//it is within the range 1 to 99. If it is outside that range, notify the user
//and ask them to enter a new value. Likewise, check for non-numbers, notify
//the user of invalid input and get a new value entered.
//
//You must also use a single function to perform the processing and provide
//both the average and total to the main.
//
//Main should look like this
//
//      ask for number of values get the number of values to be entered
//
//      call a function to get that many values, sum them, and return the total
//      and average
//
//      display the total and average
//
//your two functions should be
//
//      1) input a number, validate it, and return it
//
//      2) pass in a count, read in that many numbers, sum them, return the
//      total and average

#include <iostream>
#include <limits>

using namespace std;

int get_value();
void find_average(int& total, double& average, const int& numvalues);

int main() {
    int total = 0, numvalues = 0;
    double average = 0;
    cout << "This program will ask for a count of numbers to\n"
            "input then return the average of the numbers input.\n"
            "All input must be between 1 and 99.\n"
            "How many numbers would you like to input\n";
    numvalues = get_value();
    find_average(total, average, numvalues);
    cout << "The total of the " << numvalues << " numbers entered is " << total << " and the average is " << average << "." << endl;
}

int get_value() {
    int value;
    bool getout = false;
    do {
        cout << "Input number: ";
        cin >> value;
        if( cin.fail() ) {
            cout << "Not an integer. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            value = 0;
        }
        if( value > 0 and value < 100 )
            getout = true;
        else
            cout << "That is not in the range or 1 to 99." << endl;
    } while( getout == false );

    return value;
}

void find_average(int& total, double& average, const int& numvalues) {
    cout << "Now input " << numvalues << " numbers to find their average." << endl;
    for( int x = 0; x < numvalues; x++ ) {
        total += get_value();
    }
    average = static_cast<double>( total ) / static_cast<double>( numvalues );

}
