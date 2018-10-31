/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-19
 *	Description:	input:		integer (quit on 0)
 *					processing:	factor (absolute value of*) integer
 *					output:		list of all factors (unity, primes, and
 *								composites) in ascending order.
 */

#include <iostream> // std::cout
					// std::cin
					// std::endl
#include "factor.h"
#include "tool.h"

// this would be more efficient at runtime with a list of primes, preferably auto-generated and cached up to sqrt(std::numeric_limits<type>::max()) , but seeing as the requirements list is that it work for 24, this is already overegging the pudding in that it only checks for divisors up to 8; could very well have left it at a loop testing every int less than the integer with no noticable effect on user experience. only need to really check up to the floor of the positive sqrt of the integer, but then also would need another routine to compute the display of the implied known factors.
// To do it "better" significantly increases the footprint of this program in persistent storage and in memory, while radically decreasing the "footprint" (duration of execution) at runtime; in other words, it is a tradeoff in how the complexity of the program manifests, and whether work is front-loaded (taken care of at development time, hardware and software) or end-loaded (simple dev, long-running, unwieldy, bloated runtime environment).

short int factorUserComputerInterface()
{
	factorVerboseInstructions();
	factorQuitInstructions();
	return factorComputerUserInterface();
}

void factorVerboseInstructions()
{
	std::cout << "Enter an integer, and I will tell you its factors." << std::endl;
}

void factorQuitInstructions()
{
	std::cout << "(enter '" << QUIT << "' to quit)" << std::endl;
}

short int factorComputerUserInterface()
{
	/*	input:		void (input string from keyboard)
	 *	processing:	determines activity based on user indicated state.
	 *	output:		prints output through factor(input).
	 */
	int input = QUIT;

	do
	{
		input = factorInput();
		switch (input)
		{
			case QUIT:			std::cout << "Quit signal received." << std::endl; return 0;
			case SENTINAL_INT:	std::cout << "Invalid input type; try a integer." << std::endl;
								factorQuitInstructions();
								break;
			default:			factor(input); break;
		}
	}
	while ( input != QUIT );

	return 1;
}

int factorInput()
{
	std::cout << "Enter an integer to factor: ";
	return toolInputInt(toolInputString());
}

short int factor(int integer)
{
	/*	input:		integer
	 *	processing:	check integer for divisors (exhaustive search: speed is great up to 999999, good up to 9999999, noticable lag at 99999999)
	 *	output:		list of factors of integer
	 */
	int sign = 1;
	if ( integer < 0 )
	{
		sign = -1;
		integer = -integer;
	}
	else if ( integer == QUIT )
	{
		return 0;
	}

	for ( int dummy = 1; dummy <= integer/3; dummy++ )
	{
		if ( integer % dummy == 0 )
		{
			std::cout << sign*dummy << ' ';
		}
	}
	if ( integer%2 == 0 )
	{
		std::cout << sign*integer/2 << ' ';
	}
	std::cout << sign*integer << std::endl;

	return 0;
}
