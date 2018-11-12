#include <iostream>
using namespace std;

int iCount();

int main()
{
    const int LIMIT = 10;
    for(int i = 0; i < LIMIT; i++ )
    {
        cout << "iCount has been called " << iCount() << " times " << endl;
    }

    return 0;
}
int iCount()
{
    static int counter = 0;
    return ++counter;
}



