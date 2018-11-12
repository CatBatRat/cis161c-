#include <iostream>
using namespace std;


// thjs program inputs a value, then outputs that many squares
void getValue(int &value);

int main()
{
    int value;
    getValue(value);
    for(int i = 1; i < value+1; i++)
    {
        cout << i * i << endl;
    }

    return 0;
}
void getValue(int &value)
{
    cout << "Enter an integer: ";
    cin >> value;
}




