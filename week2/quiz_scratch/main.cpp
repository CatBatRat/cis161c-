#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{

    double test1 = 12, test2 = 7;
    test1 /= 7;

    cout << "#";
    cout << fixed << setprecision(2);
    cout << setw(8) << test1;
    cout << "#";

    int x = 0, y = 5;
    y = (x + 1) + (y + 1);
    cout << endl << y;

    return 0;
}
