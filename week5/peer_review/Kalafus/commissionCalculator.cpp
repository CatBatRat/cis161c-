/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ Week 3 homework demonstrating sequence and selection.
 */

#include <iostream> /* std::cout
					 * std::cin
					 * std::endl
					 */
#include <limits> 	/* std::numeric_limits<long double>::max()
					 */
#include "tool.h" // toolFlushInput();
#include "commissionCalculator.h"

short unsigned int commissionCalculatorUserComputerInterface()
{
	commissionCalculatorVerboseInstructions();
	commissionCalculatorQuitInstructions();
	return commissionCalculatorComputerUserInterface();
}

void commissionCalculatorVerboseInstructions()
{
	// consider the following print statements as dually being commentary.
	std::cout << "Calculating the commission earned in a real estate transaction..." << std::endl \
		<< "| Sales:				| Commission:" << std::endl \
		<< "| ------				| -----------" << std::endl \
		<< "| TOTAL < $100,000			| 5%" << std::endl \
		<< "| $100,000 < TOTAL < $300,000		| $5,000+10%*(TOTAL-$100,000)" << std::endl \
		<< "| TOTAL > $300,000			| $25,000+15%*(TOTAL-$300,000)" << std::endl;
}

void commissionCalculatorQuitInstructions()
{
	std::cout << std::endl << "(enter '0' to quit)" << std::endl;
}

short unsigned int commissionCalculatorComputerUserInterface()
{
	/*	input:		
	 *	processing:	
	 *	output:		
	 */
	long double total = std::numeric_limits<long double>::max(), commission = 0;

	do
	{
		total = commissionCalculatorInput();
		if ( total == 0 ) // check for Quit condition.
		{
			std::cout << std::endl << "Received quit signal." << std::endl;
			return 0;
		} else { // else input is valid, so compute the commission before again do-ing.
			commission = commissionCalculator(total);
			std::cout << "Commission earned: $" << commission << std::endl;
			commissionCalculatorQuitInstructions(); // Remind user how to quit before looping.
		}
	}
	while ( true );

	std::cout << "ERROR, return 1: commissionCalculatorUserComputerInterface execution shouldn't reach this point.";
	return 1;
}

long double commissionCalculatorInput()
{
	/*	input:		User input via keyboard
	 *	output:		return user supplied double value
	 */
	long double value = 0;
	bool continue_condition = false;
	do
	{
		std::cout << std::endl << "Enter Sales Total in USD: $";
		std::cin >> value;
		if ( std::cin ) // true if std::cin happily parsed the input value.
		{
			continue_condition = true;
		} else { // input parse failed, so keep asking for user input.
			toolFlushInput(); // flush std::cin in case of funky user input.
		}
	}
	while ( not continue_condition );

	return value;
}

long double commissionCalculator(long double total)
{
	/*	input:		long double of sales total
	 *	processing:	computes sales commission
	 *	output:		returns sales commission
	 */
// BEGIN PARAMETERS
	short unsigned int countOfTiers = 3;
	long double commissionTiers[countOfTiers] = {300000, 100000, 0};
	long double ratePerTier = 0.05;
// END PARAMETERS

	long double commission = 0, remainder = 0;

	remainder = total;
	for (short unsigned int dummy = 0; dummy <= countOfTiers; dummy++) // sum commission on per tier basis; sum runs from highest tier to lowest tier.
	{
		if (remainder > commissionTiers[dummy]) {
			commission += (remainder - commissionTiers[dummy]) * (countOfTiers - dummy) * ratePerTier;
			remainder = commissionTiers[dummy];
		}
	}

	return commission;
}
