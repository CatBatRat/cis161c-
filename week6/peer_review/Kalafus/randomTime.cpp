#include <iostream> // provides cout, cin
#include <random> // <cstdlib> provides srand, rand
#include <ctime> // provides time
#include <iomanip> // provides setw

int randomTime()
{
	/* Generates and prints two random numbers
	Asks user for their sum.
	Takes one user input.
	Prints the correct sum.
	*/

	std::srand(static_cast<unsigned>(std::time(0)));
	int rand1 = std::rand() % 99 + 1;
	int rand2 = std::rand() % 99 + 1;

	int user_answer;

	std::cout << "What is the sum of " << rand1 << " and " << rand2 << "?" << std::endl;
	std::cin >> user_answer;

	std::cout	<< std::endl << std::setw(3) << rand1
			<< std::endl << "+" << std::setw(2) << rand2
			<< std::endl << "---"
			<< std::endl << std::setw(3) << rand1 + rand2;

	return 0;
}
