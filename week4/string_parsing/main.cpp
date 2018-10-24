#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int test;
    string s, out;
    vector<string> news;

    while( cin >> s )
    {
        news.push_back(s);
        if( s[0] == '0' )break;
        else break;
    }
    bool _only_ints(string s);
    test = (_only_ints(news.at(0)))?stoi(news.at(0)):0;
    cout << test;


    return 0;
}

bool _only_ints(string s)
{
    return s.find_first_not_of("0123456789") == string::npos;
}
