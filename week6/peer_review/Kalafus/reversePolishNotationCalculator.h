/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ Week 3 homework demonstrating sequence and selection.
 */

#include <limits>
#include <string>

#ifndef REVERSE_POLISH_NOTATION_CALCULATOR_H
#define REVERSE_POLISH_NOTATION_CALCULATOR_H

#ifndef CONST
#define CONST
const short int QUIT = 0;
const short int INVALID = -1;
const short int CONTINUE = 1;
#endif

const short unsigned int MAX_LENGTH = std::numeric_limits<short unsigned int>::max();

void reversePolishNotationCalculatorUserComputerInterface();
void reversePolishNotationCalculatorVerboseInstructions();
void reversePolishNotationCalculatorQuitInstructions();
long long reversePolishNotationCalculator(long long leftOperand, long long rightOperand, char operation);

class ReversePolishNotationCalculator
{
	public:
			 				ReversePolishNotationCalculator();
		void				run();
	private:
		short int			appendSwitch(std::string input);
		short int			append(std::string input);
		void 				reduce(char operation);
		void				clear();

		short unsigned int	stackLength;
		long long			stack[MAX_LENGTH];
};

#endif // REVERSE_POLISH_NOTATION_CALCULATOR_H
