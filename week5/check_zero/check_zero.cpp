// vim:set autochdir:

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <sstream>

int main()
{
    int left,right,out;
    char op;
    std::regex matcher(R"((\d+)\s*([\D\W])\s*(\d+).*)");
    std::string test;
    std::getline(std::cin, test);
    std::smatch result;
    std::regex_match(test,result,matcher);
    std::cout << result[1];
    if( result.empty() ) return 0;
    else
    {
        left = std::stoi(result[1]);
        op = static_cast<std::string>(result[2])[0];
        right = std::stoi(result[3]);
    }
    switch(op)
    {
        case '+':
            out = left + right; break;
        case '/':
            out = left / right; break;
        case '*':
            out = left * right; break;
        case '%':
            out = left % right; break;
        case '-':
            out = left - right; break;
    }
    std::cout << std::endl << std::endl << test << " = " << out;

    return 0;
}
