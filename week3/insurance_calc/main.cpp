#include <iostream>

using namespace std;

int main()
{
    char mf;
    int age;
    int rate = 100;

    cout << "Are you a boy or a girl?" << endl <<
    "male/female: "; cin >> mf;
    cout << endl << "And what is your age?" << endl <<
    "age: "; cin >> age;

    if( mf == 'f' ) {
        if( age < 25 ) {
            rate = rate * 1.1;
        }
    }
    else {
        if( age < 25 ) {
            rate = rate * 1.25;
        }
        else {
            rate = rate * 1.2;
        }
    }
    cout << "Your insurance rate is: " << rate << "%" << endl;
    return 0;
}
