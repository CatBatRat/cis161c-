#include <iostream>
#include <fstream>
#include <sstream>
#include "functions.hpp"

using namespace std;

string D_function(char symbol, int width)
{//from codebind.com
    ostringstream output;
    int n = width;
    int space = n-1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= space; j++)
        {
            output << " ";
        }
        space--;
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j <= space; j++)
            {
                output << " ";
            }
            space++;
            for(int j = 1; j<=2*(n-i)-1;j++)
            {
                output << symbol;
            }
            output << "\n";
        }
    }
    return output.str();
}
string R_function(char symbol, int width, int length)
{
    for(int i = 1; i <= width; i++)
    {
        for(int j = 1; j <= length; j++)
        {
            cout << j << symbol;
        }
        cout << "\n";
    }
}
string S_function(char symbol, int width)
{
    for(int i = 1; i <= width; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            cout << j << symbol;
        }
        cout << "\n";
    }
}
string T_function(char symbol, int width)
{//code from hotjar
    for(int i = 1; i <= width; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j << symbol;
        }
        cout << "\n";
    }
}
void E_function(int file_name)
{
    //file_name.close();
}

