#include <iostream> // cout, cin, endl
#include <string>   // getline, string
#include "qolife.h" // _scroller, _validator, _dec_string, _g_positive //
#include <cmath>    // acos for PI
#include <vector>   // vector

using std::cout; using std::cin; using std::endl;
using std::string;

// Calculates and returns the area of a circle using the radius^2 * PI.
double _circle( double radius, const double& );
// Calculates and returns the area of a square using the length of side^2.
double _square( double side );
// Calculates and returns the area of a rectangle using hight * width.
double _rectangle( double height, double width );
// Calculates and returns the area of a triangle using hight * width / 2.
double _triangle( double height, double width );

int main() {
    // Set a constant for the rough value of PI.
    const double PI = std::acos( -1 );
    // Values to be used in the switch case statement.
    const int circ = 1, squ = 2, rec = 3, tri = 4;

    double long num1 = 0, num2 = 0, result = 0;
    int choice;
    string type = "";

    /* My '_validator' function in use again. Also acts as a self documentation
     * of which variables are required. */
    std::vector<string> choices = {
        "Please select the shape you would\n"
        "like to calculate the area of.",
        //
        "Circle",
        "Square",
        "Rectangle",
        "Triangle"
    };
    choice = _validate( choices );
    switch( choice ) {
        case circ:
            /* '_g_positive' get a positive number from the user and allows
             * setting the prompt used at function call. */
            num1 = _g_positive( "Please input the radius of the circle." );
            result = _circle( num1, PI );
            type = "radius";
            break;
        case squ:
            num1 = _g_positive( "Please input the side length of the square." );
            result = _square( num1 );
            type = "side";
            break;
        case rec:
            num1 = _g_positive( "Please input the height of the rectangle." );
            num2 = _g_positive( "Please input the width of the rectangle." );
            result = _rectangle( num1, num2 );
            type = "height and width";
            break;
        case tri:
            num1 = _g_positive( "Please input the height of the triangle." );
            num2 = _g_positive( "Please input the width of the triangle." );
            result = _triangle( num1, num2 );
            type = "height and width";
            break;
    }
    /* Use my '_scroller' function to show a little visual aid.  _scroller
     * takes a string, width, and direction and either scrolls text in from the
     * left, or scrolls across from the right like a news ticker. It also
     * doesn't create a newline so text can be placed at the same location; as
     * demonstrated here when the result is placed in the same location where
     * the 'Processing...' text appeared.*/
    if ( result ) {
        string secnd = "";
        if( num2 )
            secnd = " by " + _dec_string( num2 );
        _scroller( "Processing...", 20, "left" );
        /* Use my '_dec_string' function to set the number of decimals to display
         * before before converting to a string to be used in '_scroller'.*/
        string final_result
            = choices[choice] + " of " + type + ", " + _dec_string( num1 )
            + secnd + " = " + _dec_string( result, 6 );
        _scroller( final_result, 50, "right");
    }
    else {
        cout << "Exiting.";
    }
    cout << endl
        << "End of program.\n"
        "Press 'Enter' to exit.";
    string null = "";
    std::getline( cin, null );
    return 0;
}

double _circle( double radius, const double& PI ) {
    return ( radius*radius*PI );
}

double _square( double side ) {
    return ( side * side );
}

double _rectangle( double height, double width ) {
    return ( height * width );
}

double _triangle( double height, double width ) {
    return ( height * width * 0.5 );
}

