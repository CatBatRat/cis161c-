#include <iostream>
using namespace std;

int myFun(int x, int y);

int main()
{
    int x, y, sum;
    cout << "enter two integers ";
    cin >> x >> y;

    sum = myFun(x, y);
    cout << "The product of " << x << " * " << y << " is " << sum << endl;

    return 0;
}
int myFun(int x, int y)
{
    return x * y;
}



