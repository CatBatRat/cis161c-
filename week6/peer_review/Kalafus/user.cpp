#include <iostream>

#include "user.h"

int age = -1;
std::string name;

int user()
{
    // Toy asking for and subsequently echoing operator name and age.

    std::cout << "whAt. is your _name_?\n";
    std::cin >> name;
    std::cout << "whAt. is your age?\n";
    std::cin >> age;
    std::cout << "whAt. is the capitol of Antioch?\n ";

    std::cout << std::endl << "Your name is " << name << " and your age is " << age << ".\n";
    return 0;
}
