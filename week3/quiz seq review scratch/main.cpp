#include <iostream>

using namespace std;

int main()
{
    // "PI" was not given a type and none of the other variables
    // were defined first
    float PI = 3.1415, radius,area,perimeter;

    cout << "Enter the radius of a circle" << endl;
    //cin uses ">>" not "<<" which is used for cout
    cin >> radius;

    // calculate area and perimeter

    // "^" is not a valid way to square a number
    // in this case "radius * radius" will do the trick
    area = radius * radius * PI;

    perimeter = radius * 2 * PI;



    //needs to use "<<" not "<"
    cout << "The area is " << area << " and the perimeter is " << perimeter << endl;

    return 0;
}
