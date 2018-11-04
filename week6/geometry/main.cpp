#include <iostream>
#include "qolife.h"

using std::cout; using std::cin; using std::endl;
using std::string;

// Set a constant for the rough value of PI.
const float PI = 3.1416;

double _circle(double radius);
double _square(double side);
double _rectangle(double height,double width);
double _triangle(double height, double width);
double _check(string prompt);


int main() {
    double long num1 = 0, num2 = 0, result = 0;
    int choice;
    std::vector<string> choices = {
        "Please select the shape you would\n"
            "like to calculate the area of.",

        "Circle",
        "Square",
        "Rectangle",
        "Triangle"
    };
    choice = _validate(choices);
    switch( choice ) {
        case 1:
            num1 = _check("Please input the Radius of the circle.");
            result = _circle(num1);
            break;
        case 2:
            num1 = _check("Please input the side length of the square.");
            result = _square(num1);
            break;
        case 3:
            num1 = _check("Please input the height of the rectangle.");
            num2 = _check("Please input the width of the rectangle.");
            result = _rectangle(num1,num2);
            break;
        case 4:
            num1 = _check("Please input the height of the triangle.");
            num2 = _check("Please input the width of the triangle.");
            result = _triangle(num1,num2);
            break;
    }
    /* Use my '_scroller' function to show a little visual aid*/
    _scroller("Processing...", 20, "left");
    _scroller( "The area of the " + choices[choice] + " is " + _dec_string(result,2),
            50, "right");

    return 0;
}

// Calculates the area of a circle.
double _circle(double radius) {
    return (radius*radius*PI);
}

// Calculates the area of a square.
double _square(double side) {
    return (side*side);
}

// Calculates the area of a rectangle.
double _rectangle(double height,double width) {
    return (height*width);
}

// Calculates the area of a triangle.
double _triangle(double height, double width) {
    return (height*width*0.5);
}

/* Get input from the user and check if valid input. Can also provide a string
 * To be used as the prompt for the user allowing to change the prompt for
 * each call to this function.*/
double _check(string prompt) {
    double num = 0;
    bool go = true;
    do {
        cout << prompt << endl;
        cout << "Entering a non number or 0 will exit" << endl;
        cin >> num;
        _cin_clear();
        if(num == 0) return 0;
        if(num <= 0) cout << "You must input a positive number." << endl;
        else go=false;
    } while ( go );
    cout << endl;
    return num;
}
