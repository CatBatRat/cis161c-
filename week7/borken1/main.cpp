#include <iostream>
using namespace std;

/* Since asking for user input setting default values for length and width
 * is redundant.*/
int area(int length, int width);

int main()
{
    int length, width;
    cout << "Enter the width and length of your rectangle\n";
    cin >> length >> width;

    cout << "Your triangle has an area " << area(length, width);

    return 0;
}

int area(int length, int width)
{
    return length * width;
}

