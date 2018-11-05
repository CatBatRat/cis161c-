#include <iostream>
using namespace std;

float circle(int);
int getDiameter();

int main()
{
    int diameter;
    cout << "enter the diameter of your circle\n";
    diameter = getDiameter();

    cout << " your circle has area " << circle(diameter) << endl;

    return 0;
}
int getDiameter()
{
    int value;

    cin >> value;

    return value;
}

float circle(int diameter)
{
    float radius = diameter / 2.0;
    const float PI = 3.1415926;

    return radius * radius * PI;
}
