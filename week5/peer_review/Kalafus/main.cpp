/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ Week 4 homework demonstrating sequence and selection.
 */

#include <iostream> /* std::cout
					 * std::cin
					 * std::endl
					 * std::streamsize
					 */
#include <limits> 	/* std::numeric_limits<std::streamsize>::max()
					 */
#include "main.h"
#include "tool.h" // toolFlushInput();
#include "user.h"
#include "randomTime.h"
#include "commissionCalculator.h"
#include "reversePolishNotationCalculator.h"
#include "factor.h"
#include "extrema.h"
#include "hackenbush.h"

const short unsigned int MENU_LOWER_BOUND = 0;
const short unsigned int MENU_UPPER_BOUND = 7;

int main()
{
	switch (mainMenu())
	{
		case 1: user(); break;
		case 2: randomTime(); break;
		case 3: commissionCalculatorUserComputerInterface(); break;
		case 4: reversePolishNotationCalculatorUserComputerInterface(); break;
		case 5: factorUserComputerInterface(); break;
		case 6: extremaUserComputerInterface(); break;
		case 7: hackenbushUserComputerInterface(); break;
		case 0: std::cout << "Received quit signal." << std::endl;
	}
	return 0;
}

short unsigned int mainMenu()
{
	std::cout \
		<< "Select an exercise: " << std::endl \
		<< std::endl \
		<< "1) User Identification" << std::endl \
		<< "2) Random Time" << std::endl \
		<< "3) Commission Calculator" << std::endl \
		<< "4) Reverse Polish Notation Calculator" << std::endl \
		<< "5) List Factors (unity, primes, and composites)" << std::endl \
		<< "6) Extrema Minder" << std::endl \
		<< "7) Play Hackenbush" << std::endl \
		<< "0) Quit" << std::endl \
		<< "? ";
	return mainMenuInput();
}

short unsigned int mainMenuInput()
{
	short unsigned int value = 0;
	bool continue_condition = false;

	do
	{
		value = toolInputInt(toolInputString());

		if ( not (value == SENTINAL_INT) and not (value < MENU_LOWER_BOUND) and not (value > MENU_UPPER_BOUND) )
		{
			continue_condition = true;
		}
		else
		{
			// keep asking for user input.
			std::cout << "Please enter an integer between " << MENU_LOWER_BOUND << " and " << MENU_UPPER_BOUND << std::endl;
		}
	}
	while ( not continue_condition );

	return value;
}
