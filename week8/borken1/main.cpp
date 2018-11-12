
#include <iostream>
using namespace std;

int myFun(int x, int y);

int main()
{
    int x, y;
    cout << "enter two integers ";
    cin >> x >> y;

    cout << "The sum of " << x << " + " << y << " is " << myFun(x, y) << endl;

    return 0;
}
int myFun(int x, int y)
{
    return x + y;
}




