/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ Week 4 homework demonstrating sequence and selection.
 */

#include <iostream>
#include <limits> 	/* std::numeric_limits<std::streamsize>::max()
					 * std::numeric_limits<double>::max()
					 */
#include "main.h"

short unsigned int MENU_LOWER_BOUND = 0;
short unsigned int MENU_UPPER_BOUND = 2;

int main()
{
	switch (mainMenu())
	{
		case 1: commissionCalculatorUI(); break;
		case 2: reversePolishNotationCalculatorUI(); break;
		case 0: std::cout << "Received quit signal.";
	}
	return 0; 
}

short unsigned int mainMenu()
{
	std::cout << "Select an exercise: " << std::endl \
		<< "1) Commission Calculator" << std::endl \
		<< "2) Reverse Polish Notation Calculator" << std::endl \
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
		std::cin >> value;
		if ( (std::cin) and not (value < MENU_LOWER_BOUND) and not (value > MENU_UPPER_BOUND) ) // true if std::cin happily parsed and assigned the input value.
		{
			continue_condition = true;
		} else { // keep asking for user input.
			std::cout << "Please enter an integer between " << MENU_LOWER_BOUND << " and " << MENU_UPPER_BOUND << std::endl;
			flushInput(); // flush std::cin in case of funky user input.
		}
	}
	while ( not continue_condition );

	return value;
}

void flushInput()
{
	std::cin.clear();
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
}

void commissionCalculatorPrimer()
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

short unsigned int commissionCalculatorUI()
{
	commissionCalculatorQuitInstructions();
	commissionCalculatorPrimer();

	double total = std::numeric_limits<double>::max(), commission = 0;

	do
	{
		std::cout << std::endl << "Enter Sales Total in USD: $";
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

	std::cout << "ERROR, return 1: commissionCalculatorUI execution shouldn't reach this point.";
	return 1;
}

double commissionCalculatorInput()
{
	double value = 0;
	bool continue_condition = false;
	do
	{
		std::cin >> value;
		if ( std::cin ) // true if std::cin happily parsed the input value.
		{
			continue_condition = true;
		} else { // input parse failed, so keep asking for user input.
			std::cout << "Enter Sales Total in USD: $";
			flushInput(); // flush std::cin in case of funky user input.
		}
	}
	while ( not continue_condition );

	return value;
}

double commissionCalculator(double total)
{
// BEGIN PARAMETERS
	short unsigned int countOfTiers = 3;
	double commissionTiers[countOfTiers] = {300000, 100000, 0};
	double ratePerTier = 0.05;
// END PARAMETERS

	double commission = 0, remainder = 0;

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

void reversePolishNotationCalculatorPrimer()
{
	// consider the following print statements as dually being commentary.
	std::cout << "Computing result of Reverse Polish Notation calculation..." << std::endl;
	std::cout << "mult '*' div '/' remainder '%' plus '+' minus '-'" << std::endl \
       	<< "Enter two integers followed by an operator," << std::endl \
		<< "	and separated by blankspace characters." << std::endl;
}

void reversePolishNotationCalculatorQuitInstructions()
{
	std::cout << "(\"0 0 q\" to Quit)" << std::endl; // TODO awkward syntax; input handling needs be revamped to be able to accept "[Qq]uit" requests.
}

short unsigned int reversePolishNotationCalculatorUI()
{
	reversePolishNotationCalculatorPrimer();
	reversePolishNotationCalculatorQuitInstructions();

	char operation = 'q'; // in case of error getting any input, just quit.
	long long leftHandOperand = 0, rightHandOperand = 0, result = 0;

	do // loops the reverse polish notation calculator until quit signal is input.
	{
		std::cin >> leftHandOperand >> rightHandOperand >> operation; // assign user input to local variables.
		if ( std::cin ) // test for invalid input, else input is evidently valid.
		{
			switch (operation)
			{
				case '%':
				case '/': if (rightHandOperand == 0) // check for divide by zero error on % and / operations.
						  {
							  std::cout << "WARNING: undefined operation: divide by zero 'integer 0 {/,%}'." << std::endl;
							  break;
						  }
				case '*':
				case '+':
				case '-': result = reversePolishNotationCalculator(leftHandOperand, rightHandOperand, operation); // input is evidently valid, so execute Calculation.
						  std::cout << result << std::endl; // and print the result before again do-ing.
						  break;
				case 'Q':
				case 'q': if ( (leftHandOperand == 0) and (rightHandOperand == 0) ) 
						  { // quit signal received as defined by 0 0 [Qq]
							  return 0;
						  }
				default: std::cout << "WARNING: unknown operation: '" << operation << "'" << std::endl;
						 reversePolishNotationCalculatorQuitInstructions(); // remind user of quit instructions on bad input.
			}
		} else { // type casting failed; is the user trying to quit?
			std::cout << "Invalid types; try 'integer integer {+,-,*,/,%}'" << std::endl;
			reversePolishNotationCalculatorQuitInstructions(); // remind user of quit instructions on bad input.
			flushInput(); // clears the input stream to prime for new input.
		}
	}
	while ( true );

	std::cout << "ERROR, return 1: reversePolishNotationCalculatorUI execution shouldn't reach this point.";
	return 1;
}

long long reversePolishNotationCalculator(long long leftHandOperand, long long rightHandOperand, char operation)
{
	switch (operation)
	{
		case '/': if (rightHandOperand != 0)
				  {
					  return leftHandOperand / rightHandOperand;
				  } else {
					  std::cout << "ERROR: attempted divide by zero." << std::endl;
					  break;
				  }
		case '%': return leftHandOperand % rightHandOperand;
		case '*': return leftHandOperand * rightHandOperand;
		case '+': return leftHandOperand + rightHandOperand;
		case '-': return leftHandOperand - rightHandOperand;
		default: std::cout << "ERROR: unrecognized operand." << std::endl; // the UI checks for valid operator, so this shouldn't be reached in this implementation. If execution does reach here, sentinal value 0 is ambiguously returned.
				break;
	}
	return 0; // return ambiguous sentinal value 0 on unrecognized operand. This function needs input validated.
}
