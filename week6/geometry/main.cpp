#include <iostream>
#include "qolife.h" // _scroller, _validator, _dec_string //

using std::cout; using std::cin; using std::endl;
using std::string;

// Set a constant for the rough value of PI.
const float PI = 3.1416;
const int circ = 1,squ = 2, rec = 3, tri = 4;

double _circle(double radius);
double _square(double side);
double _rectangle(double height,double width);
double _triangle(double height, double width);


int main() {
    double long num1 = 0, num2 = 0, result = 0;
    int choice;
    /* My '_validator' function in use again. Also acts as a self
     * documentation of what variable are in use. */
    std::vector<string> choices = {
        "Please select the shape you would\n"
        "like to calculate the area of.",
        //
        "Circle",
        "Square",
        "Rectangle",
        "Triangle"
    };
    choice = _validate(choices);
    switch( choice ) {
        case circ:
            /* '_g_positive' get a positive number from the user and allows
             * setting ther prompt used at function call. */
            num1 = _g_positive("Please input the radius of the circle.");
            result = _circle(num1);
            break;
        case squ:
            num1 = _g_positive("Please input the side length of the square.");
            result = _square(num1);
            break;
        case rec:
            num1 = _g_positive("Please input the height of the rectangle.");
            num2 = _g_positive("Please input the width of the rectangle.");
            result = _rectangle(num1,num2);
            break;
        case tri:
            num1 = _g_positive("Please input the height of the triangle.");
            num2 = _g_positive("Please input the width of the triangle.");
            result = _triangle(num1,num2);
            break;
    }
    /* Use my '_scroller' function to show a little visual aid.
     * _scroller takes a string, width, and direction and either
     * scrolls text in from the left, or scrolls across from the
     * right like a news ticker. It also doesn't create a newline
     * so text can be placed at the same location; as demonstrated
     * here when the result is placed in the same location where
     * the 'Processing...' text appeared.*/
    if (result) {
    _scroller("Processing...", 20, "left");
    /* Use my '_dec_string' function to set the number of decimals to display
     * before before converting to a string to be used in '_scroller'.*/
    _scroller( "The area of the " + choices[choice] + " is " + _dec_string(result,2),
            50, "right");
    }
    else {
        cout << "Exiting.";
    }
    cout << endl << "End of program.";
    return 0;
}

// Calculates and returns the area of a circle using the radius^2 * PI.
double _circle(double radius) {
    return (radius*radius*PI);
}

// Calculates and returns the area of a square using the length of side^2.
double _square(double side) {
    return (side*side);
}

// Calculates and returns the area of a rectangle using hight times width.
double _rectangle(double height,double width) {
    return (height*width);
}

// Calculates and returns the area of a triangle using hight times width.
double _triangle(double height, double width) {
    return (height*width*0.5);
}

