/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ Week 3 homework demonstrating sequence and selection.
 */

#include <iostream> /* std::cout
					 * std::cin
					 * std::endl
					 */
#include <string> /* std::string */
#include "tool.h"	// toolInputString()
					// toolInputLongLong()
#include "reversePolishNotationCalculator.h"

void reversePolishNotationCalculatorUserComputerInterface()
{
	reversePolishNotationCalculatorVerboseInstructions();
	reversePolishNotationCalculatorQuitInstructions();

	ReversePolishNotationCalculator calculator;
	calculator.run();
}

void reversePolishNotationCalculatorVerboseInstructions()
{
	// consider the following print statements as dually being commentary.
	std::cout << "Computing result of Reverse Polish Notation calculation..." << std::endl \
		<< std::endl \
		<< "Available operations:" << std::endl \
		<< "	mult '*' div '/' remainder '%' plus '+' minus '-'" << std::endl \
		<< "Enter two or more integers followed by a mixture of integers and operators." << std::endl \
		<< std::endl \
		<< "When [the number of operators entered] plus one is equal to [the number of integers entered], the result of the computation will be printed." << std::endl;
}

void reversePolishNotationCalculatorQuitInstructions()
{
	std::cout << "(enter 'q' to quit, 'c' to clear)" << std::endl;
}

long long reversePolishNotationCalculator(long long leftHandOperand, long long rightHandOperand, char operation)
{
	/*	input:		operand operand operation
	 *	processing:	computes result under rpn syntax
	 *	output:		result
	 */

	switch ( operation )
	{
		case '/':	if ( rightHandOperand != 0 )
					{
						return leftHandOperand / rightHandOperand;
					}
					else
					{
						std::cout << "ERROR: attempted divide by zero." << std::endl;
					}
					break;
		case '%':	if ( rightHandOperand != 0 )
					{
						return leftHandOperand % rightHandOperand;
					}
					else
					{
						std::cout << "ERROR: attempted to compute remainder of division by zero." << std::endl;
					}
					break;
		case '*':	return leftHandOperand * rightHandOperand;
		case '+':	return leftHandOperand + rightHandOperand;
		case '-':	return leftHandOperand - rightHandOperand;
		default:	std::cout << "ERROR: unrecognized operand." << std::endl; break;
					/* the UserComputerInterface checks for valid operator, so
					 * this shouldn't be reached in this implementation.
					 */
	}

	return SENTINAL_LONG_LONG;
}

ReversePolishNotationCalculator::ReversePolishNotationCalculator()
{
	/*	init namespace variables:	stack[]
	 */
	ReversePolishNotationCalculator::stackLength = 0;
	ReversePolishNotationCalculator::clear();
}

void ReversePolishNotationCalculator::run()
{
	/*	input:		std::string input from keyboard.
	 *	processing:	append to rpn stack.
	 *	output:		prints syntax messages, and completed calculations (when
	 *				stack reduces to one entry, prints the result, otherwise
	 *				continues same behaviors)
	 */
	std::string input;
	do
	{
		input = toolInputString();
	}
	while ( ReversePolishNotationCalculator::appendSwitch(input) != QUIT );
}

short int ReversePolishNotationCalculator::appendSwitch(std::string input)
{
	switch ( input[0] )
	{
		case 'q':
		case 'Q':	std::cout << "Quit signal received! Honoring and exiting..." << std::endl;
					return QUIT;
		case 'c':
		case 'C':	ReversePolishNotationCalculator::clear();
					return CONTINUE;
		default:	return ReversePolishNotationCalculator::append(input); break;
	}
}

short int ReversePolishNotationCalculator::append(std::string input)
{
	/*	input:		std::string input
	 *	processing:	pushes next integer onto the stack, or, if contextually
	 *	valid operation is given, reduce the stack.
	 *	output:		stack side
	 *	effects
	 */

	long long integer = toolInputLongLong(input);

	if ( not (integer == SENTINAL_LONG_LONG) )
	{
		ReversePolishNotationCalculator::stack[ReversePolishNotationCalculator::stackLength++] = integer;
	}
	// if trying to make one of the first two entries, check that they are integers before reducing.
	else if ( !(stackLength == 0) and !(stackLength == 1) )
	{
		if ( input == "" )
		{
			std::cout << "Sorry, I didn't get that. Please try again!" << std::endl;
			reversePolishNotationCalculatorQuitInstructions();
		}
		else
		{
			switch ( input[0] )
			{
				case '%':
				case '/':	if (ReversePolishNotationCalculator::stack[ReversePolishNotationCalculator::stackLength-1] == 0) // check for divide by zero error on % and / operations.
							{
								std::cout << "IGNORING: undefined operation: '" << input[0] << "' by zero." << std::endl;
								break;
							}
				case '*':
				case '+':
				case '-':	ReversePolishNotationCalculator::reduce(input[0]); return CONTINUE;
				default:	std::cout << "Please enter an integer or operation %/*+-" << input[0] << "'" << std::endl;
							reversePolishNotationCalculatorQuitInstructions(); // remind user of quit instructions on bad input.
			}
		}
	}
	return INVALID;
}

void ReversePolishNotationCalculator::reduce(char operation)
{
	/*	input:		char operation
	 *	processing:	pop top two elements, rpn them with the given operation.
	 *	output:		push the result onto the stack.
	 */
	long long integer;
	if ( ReversePolishNotationCalculator::stackLength >= 2 )
	{
		integer = reversePolishNotationCalculator(ReversePolishNotationCalculator::stack[ReversePolishNotationCalculator::stackLength-2], stack[ReversePolishNotationCalculator::stackLength-1], operation);
		if ( integer != SENTINAL_LONG_LONG )
		{
			ReversePolishNotationCalculator::stack[ReversePolishNotationCalculator::stackLength-2] = integer;
			ReversePolishNotationCalculator::stack[ReversePolishNotationCalculator::stackLength-1] = SENTINAL_LONG_LONG;
			if ( --ReversePolishNotationCalculator::stackLength == 1 )
			{
				std::cout << "=" << integer << " ";
			}
		}
	}
	else
	{
		std::cout << "ERROR: called reduce without enough integers; please issue a Bug Report to the dev team." << std::endl;
	}
}

void ReversePolishNotationCalculator::clear()
{
	ReversePolishNotationCalculator::stackLength = 0;
	for (short unsigned int dummy = 0; dummy < MAX_LENGTH; dummy++)
	{
		ReversePolishNotationCalculator::stack[dummy] = SENTINAL_LONG_LONG; /* Sentinal value for initialized entries */
	}
}
