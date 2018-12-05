/*#include <iostream>

using namespace std;

int area(int length, int width = 0);

int main()
{
    int length, width;

        // for rectangle use both arguments
    cout << "Enter length and width of a rectangle" << endl;
    cin >> length >> width;

    cout << "The area is " << area(length, width) << endl;

      // for square, only need first argument
    cout << "Enter side of a square" << endl;
    cin >> length;

    cout << "The area is " << area(length) << endl;

    return 0;
}

// There was already a default argument provided in the function protoype of this definition.
// There is also semicolon after the function definition.
int area(int length, int width)
{
    if ( width == 0 )
        return length * length;

    return length * width;
}*/

/*#include <iostream>

using namespace std;

void area2(int& area, int length, int width = 0);

int main()
{
    int length, width, area;

      // for rectangle use two arguments
    cout << "Enter length and width of a rectangle" << endl;
    cin >> length >> width;

    area2(area, length, width);
    cout << "The area is " << area << endl;

      // for squares use one argument
    cout << "Enter side of a square" << endl;
    cin >> length;

    area2(area, length);
    cout << "The area is " << area << endl;

    return 0;
}

void area2(int& area, int length, int width)
{
    if ( width == 0 )
        area = length * length;
    else
        area = length * width;
}*/

#include <iostream>

using namespace std;

// Function prototypes.
void square(int& perim, int& area, int side);
int get_input();

int main()
{
    // Create the variables for use in the program.
    int perim, area, side;
    cout << "Input the side of a square and I will tell you the area\n"
            "and perimeter of the shape.\n" << endl;
    side = get_input();
    square(perim, area, side);

    cout << "The area of a square with side = " << side
         << " is " << area << ".\n"
         << "The perimeter of the square is " << perim << "." << endl;

    return 0;
}

// Get user input integer and return it.
int get_input()
{
    int output;
    cout << "Please enter your value:" << endl;
    cin >> output;
    return output;
}

// Calculate area and perimeter and set the values in main using references.
void square(int& perim, int& area, int side)
{
    // Calculate the perimeter of a square.
    perim = side * 4;
    // Calculate the area of a square.
    area = side * side;
}
