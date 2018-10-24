// vim:set autochdir:
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int exponent = 1;
long long number;

int main()
{
    while (exponent < 30)
    {
        number = pow(10, exponent);
        cout << number << endl;
        exponent += 1;
    }

    return 0;
}
