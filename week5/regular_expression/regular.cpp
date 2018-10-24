// vim:set autochdir:

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

//Example 1
#include <iostream>
#include <cstdio>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string input;
    regex integer(R"((\+|-)?([\d])+)");
        cout << R"((\+|-)?([\d])+)";
    //As long as the input is correct ask for another number
    while(true)
    {
        cout<<"Give me an integer!"<<endl;
        cin>>input;
    cout << flush;
    system("clear");
        if(!cin) break;
        //Exit when the user inputs q
        if(input=="q")
            break;
        if(regex_match(input,integer))
            cout<<"integer"<<endl;
        else
        {
            cout<<"Invalid input"<<endl;
        }
    }
}
