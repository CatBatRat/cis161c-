#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main(){

    srand(time(nullptr));

    /* Set the random numbers and keep their
    value between 1 and 99 */
    int randn1 = rand() % 99 + 1;
    int randn2 = rand() % 99 + 1;

    int answer;

    for(int x=0;x<30000;x++){
        cout << rand() % 99 + 1 << " ";
    }


    // Ask the user to input their answer

    // Set a bool value for checking when this do/while
    // loop will will stop.
    bool correct = false;
    do{
        cout << "What is the sum of " << randn1 <<
            " and " << randn2 << "?" << endl <<
            "Answer: "; cin >> answer;

        if (answer == randn1 + randn2){correct = true;}
        else{
            cout << "That is not the correct answer." << endl <<
                "Please try again." << endl;
        }
    }
    while(correct == false);

    cout << "Good job! You have pleased the computer" << endl;


    cout << setw(3) << randn1 <<endl;
    cout << "+" << setw(2) << randn2 << endl;
    cout << "---" << endl;
    cout << setw(3) << answer;

    return 0;
}
