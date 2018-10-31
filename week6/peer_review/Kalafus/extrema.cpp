/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-19
 *	Description:	input: user supplies integers 1-100
 *					processing: remember extrema (greatest_value and least_value integers encountered)
 *					output: when user enters 0, extrema
 *							when user enters other values, issue WARNING to std::cout.
 */

#include <iostream> // std::cout
					// std::cin
					// std::endl
					// std::streamsize
//#include <iomanip>	// std::right
#include <limits> 	// std::numeric_limits<std::streamsize>::max()
#include "extrema.h"
#include "tool.h"

int greatest_value = INIT_GREATEST_VALUE;
int least_value = INIT_LEAST_VALUE;

short int extremaUserComputerInterface()
{
	extremaVerboseInstructions();
	extremaQuitInstructions();
	return extremaComputerUserInterface();
}

void extremaVerboseInstructions()
{
	std::cout << "Enter a sequence of integers between " << BOUNDARY_LOWER << " and " << BOUNDARY_UPPER << ", and I will keep track of the least_value and greatest_value values you give to me." << std::endl;
}

void extremaQuitInstructions()
{
	std::cout << "(input '" << QUIT << "' to tell me when you want to exit)" << std::endl;
}

short int extremaComputerUserInterface()
{
	/*	input:		user input via keyboard
	 *	processing:	remembers greatest and least values seen (within a pre-defined range)
	 *	output:		prints those greatest and least values; returns success state.
	 */
	int input = SENTINAL_INT;
	int repeat = SENTINAL_INT;

//	std::cout << std::setw(18) << std::right;

	do
	{
		greatest_value = INIT_GREATEST_VALUE;
		least_value = INIT_LEAST_VALUE;
		do
		{
			input = extremaInput();
			if ( (BOUNDARY_LOWER <= input) and (input <= BOUNDARY_UPPER) )
			{
				extrema(input);
			}
			else if ( input == QUIT )
			{
				if ( least_value == INIT_LEAST_VALUE )
				{
					std::cout << "least value: " << "empty" << std::endl;
				}
				else
				{
					std::cout << "least value: " << least_value << std::endl;
				}
				if ( greatest_value == INIT_GREATEST_VALUE )
				{
					std::cout << "greatest value: " << "empty" << std::endl;
				}
				else
				{
					std::cout << "greatest value: " << greatest_value << std::endl;
				}
			}
			else if ( input == SENTINAL_INT )
			{
				std::cout << "Invalid input type; try an integer." << std::endl;
				extremaQuitInstructions();
			}
			else
			{
				std::cout << input << " is right out! Please enter a value between " << BOUNDARY_LOWER << " and " << BOUNDARY_UPPER << "." << std::endl;
				extremaQuitInstructions();
			}
		}
		while ( input != QUIT );

		std::cout << "Repeat loop or Quit? ('" << QUIT << "' to quit; any other value to repeat)? ";
		repeat = extremaInput();
	}
	while ( repeat != QUIT );

	return 0;
}

int extremaInput()
{
	/*	input:		std::cin
	 *	processing:	safely convert string to int.
	 *	output:		on error, return int min.
	 * 				else, return int user keyed in.
	 */
	return toolInputInt(toolInputString());
}

void extrema(int value)
{
	/*	input:		a value
	 *	processing:	update file scope variables greatest and least value
	 *	output:		void
	 */
	if ( value < least_value )
	{
		least_value = value;
	}

	if ( value > greatest_value )
	{
		greatest_value = value;
	}
}
