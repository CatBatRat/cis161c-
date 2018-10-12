#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main(){

    srand(time(nullptr));

    /* Set the random numbers and keep their
     * value between 1 and 99 */
    int randn1 = rand() % 99 + 1;
    int randn2 = rand() % 99 + 1;

    int answer;


    /* Set a bool value for checking when this do/while
    loop will will stop. */
    bool correct = false;

    /* Ask the user to input their answer and
    continue through a "do while" loop until the
    user gets the answer right */
    do{
        cout << "What is the sum of " << randn1 <<
            " and " << randn2 << "?" << endl <<
            "Answer: "; cin >> answer;

        /* Check if the answer given by the user is correct.
        If true: set "correct" to 'true'
        If false: trigger *else* and loop back */
        if (answer == randn1 + randn2){correct = true;}
        else{
            cout << "That is not the correct answer." << endl <<
                "Please try again." << endl;
        }
    }
    while(correct == false);

    cout << "Good job! You have pleased the computer. '-'" << endl;

    /* Display the results with correct formatting.
     * Side note: find out how to get the length
     * of a string to use the value for auto formatting*/
    cout << setw(3) << randn1 <<endl;
    cout << "+" << setw(2) << randn2 << endl;
    cout << "---" << endl;
    cout << setw(3) << answer;

    return 0;
}
