// vim:set autochdir:

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <curses.h>
#include <regex>

using namespace std;

#define w(width,input) setw(width) << input


const char clr[] = "cls";

int _minmax();
int _factors();
int _commission();
int _calculator();

int main()
{
    // Set to -1 so there will be no upward limit to number
    // of menu entries.
    int enter = -1;

    // Create a main menu so all of the number calculation can
    // be kept in one place. I may include any later work in
    // program as well.
    cout << "Welcome to the main menu of Number Works!\n"
            "This Program is meant to provide you with\n"
            "a set of tools to work with number problems\n"
            "of various types.\n\n";

    // While not zero means that only the number 0 when entered at the menu
    while(enter != 0)
    {
        cout << "Please enter the number of the program you would like to use\n\n"

                "1 = Find the minimum and maximum of a series of numbers.\n"
                "2 = Find all the factors of a number.\n"
                "3 = Calculate commission on a sale.\n"
                "4 = Use a simple calculator to perform basic math functions.\n"
                "0 = Exit\n\n"

                "Selection = "; cin >> enter;
        cout << flush;
        system(clr);

        switch(enter)
        {
            case 1:
                    _minmax();
                    break;
            case 2:
                    _factors();
                    break;
            case 3:
                    _commission();
                    break;
            case 4:
                    _calculator();
                    break;
            case 0:
                    return 0;
            default: cout << "Please input a valid number from the list,\n"
                             "or enter \"0\" to exit.\n\n";
        }
    }
    return 0;
}
int _minmax()
{
    long int input, highest, lowest;

    cout << "Please input any series of integers and this program\n"
            "will identify the highest and lowest number then\n"
            "display the difference between the two.\n"
            "You may enter a \"0\" at any time to exit this program.\n\n";
    bool first = true;

    while(true)
    {
        cout << "Integer: #";
        cin >> input;
        cout << flush;
        system(clr);
        if(first == true) {
            cout <<left<< "The first integer you have entered is #"
                << input << "\n\n";
            lowest = input;
            highest = input;
            first = false;
        }
        else {
            if ( input == 0 )
                return 0;
            if ( input < 1 || input > 100 ) {
                cout << "You must input a number between 1 and 100." << endl;
                continue;
            }
            if(input < lowest)
                lowest = input;
            else if(input > highest)
                highest = input;
            if(input) {
                cout << left << w(43,"  The lowest integer you have entered is")
                    << lowest << endl;
                cout << left << w(43,"  The highest integer you have entered is")
                    << highest << endl;
                cout <<left<< w(43,"The difference between the two integers is")
                    << highest - lowest << "\n\n\n";
            }
        }

    }

    return 0;
}

int _factors()
{

    int number = 1;
    string out;
    cout << "Please input the integer you would like to know the factors of.\n"
            "Must be greater than \"0\". NO negative integers.\n\n";

    while(number != 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Integer: #";
        cin >> number;
        cout << flush;
        system(clr);
        if(number < 0)
        {
            cout << "No negative numbers!\n\n";
            number = 1;
            continue;
        }
        else
        {
            cout << "The factors of " << number << " are" << endl;
            for(int x=number/2;x > 1; x--)
            {
                (number%x == 0)?cout << x << " ":cout;
            }
            cout << "and 1.";
        }
        cout << "\nYou may now enter an additional number, or input \"0\"\n"
                "to return to the main menu.\n\n";
    }
    cout << flush;
    system(clr);
    return 0;
}

int _commission()
{

    #define BS(a,b) (a[b+1]-a[b])
    // Base amounts at which interest levels change.
    const double BASES[] = {0, 100000, 300000};
    // Number of interest levels MUST match number of bases!
    // Each level applies to the amount OVER the previous BASE
    // remember, these are cumulative.
    const double RATES[] = {0.05, 0.10, 0.15};

    // define variables
    double input, output;

    // Variables for:
    // - RATES array length
    // - Controlling entry into the second while loop
    // - Tracking number of loops in relation to RATES array length
    int rl, tr = 0;
    bool go = true;


    // Get number of elements in the "RATES" array
    rl = sizeof(RATES)/sizeof(RATES[0]);
    // I wonder why there is not something like the
    // String object property for length with arrays.

    // Set display of any following numbers
    cout << fixed << showpoint << setprecision(2);
    cout << "Please input the total transaction amount\n"
            "from your sale to calculate your commission.";
    // Enter main while loop
    while(true)
    {
        output = 0; tr = 0;
        cout << "\nAmount: ";
        cin >> input;
        cout << flush;
        system(clr);
        // Exit program upon entering 0
        if( input == 0 )
            return 0;
        // Set go = 0 upon negative number entry
        if( input <= 0 )
        {
            go = false; cout << "\nPlease enter a positive value\n";
        }
        while(go)
        {
            if( input <= BS(BASES,tr) or tr == rl-1 )
            {
                output += input * RATES[tr];
                break;
            }
            if( input > BASES[tr] )
            {
                output += BS(BASES,tr)*RATES[tr];
                input -= BS(BASES,tr);
            }
            tr++;
        }
        if ( go == true )
        {
            cout << endl << "Your commission for a sale of " << input <<
                            "\nis $ " << output << endl;
        }
        go = true;
        cout << "\nYou may now enter another sale amount,\n"
                "or you may input a '0' to exit";

    }
    return 0;
}

int _calculator()
{
    // Define variables
    char op;
    int num1, num2;
    double out;

    /* Capture all needed values on a single line
     * separated by spaces then match using a regular expre*/
    string input;
    regex matcher(R"((\d+)\s*([\D\W)])\s*(\d+))");

    // Display instructions
    cout << "Please enter two integers, separated by an operator,\n"
            " Example: 2 + 2,\n"
            " or enter a '0' to exit.\n"
            " + = Add\n"
            " - = Subtract\n"
            " * = Multiply\n"
            " / = Divide\n"
            " % = Modulo\n"
            " \n ";
    bool go = true;
    cin.clear();
    cin.ignore();
    while(go)
    {
        std::getline(cin, input, '\n');
        if( input == "0")
        {
            cout << flush;
            system(clr);
            return 0;
        }
        smatch result;
        regex_match(input,result,matcher);
        if( result.empty() )
        {
            cout << "That is not valid input\nPlease try again." << endl;
            continue;
        }
        else
        {
            num1 = stoi(result[1]);
            num2 = stoi(result[3]);
            op = static_cast<string>(result[2])[0];
        }

        // Check if division and check for 0 in the second value
        // and perform division if not 0, else display error.
        switch(op)
        {
            case '/':
            {
                if(num2 != 0)
                {
                    cout << fixed << showpoint << setprecision(3);
                    out = static_cast<float>(num1)/static_cast<float>(num2);
                    break;
                }
                else
                {
                    cout << "Can't divide by zero!";
                    break;
                }
            }
            case '*': out = num1 * num2; break;
            case '%': out = num1 % num2; break;
            case '+': out = num1 + num2; break;
            case '-': out = num1 - num2; break;
            default:  cout << "That is not a valid operator, please try again."; break;
        }


    cout <<" "<<num1<<" "<<op<<" "<<num2<<" = "<<out;
    }

    return 0;
}
