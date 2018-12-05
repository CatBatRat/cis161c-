#include <iostream>


using namespace std;

int main()
{
    int number, factors;
    string out;
    cin >> number;
    for(int x=number;x > 0; x--) {
        (number%x == 0)?cout << x << endl:cout;

            //cout << x << endl;
    }

    return 0;
}
