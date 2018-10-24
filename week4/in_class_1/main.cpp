#include <iostream>

using namespace std;

int main()
{
    int number = 38;
    bool is_prime = true;

    for ( int x=number/2; x  1; x--)
        if( number % x == 0 )
        {
            is_prime = false;
            break;
        }
    if( is_prime )
        cout << "The number is prime!";
    else
        cout << "The number is not prime.";
}
