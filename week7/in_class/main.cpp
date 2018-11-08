#include <iostream>

using namespace std;

int sum(int = 30,int = 6);
int main()
{
    cout << sum() << endl;
    return 0;
}

int sum(int num1, int num2)
{
    int total = num1 + num2;

    return total;
}
