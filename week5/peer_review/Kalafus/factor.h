/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-19
 *	Description:	input: integer (quit on 0)
 *					processing: factor (absolute value of*) integer
 *					output: list of all factors (unity, primes, and composites) in ascending order.
 *
 *					*specification explicitly prefers asking for new input on <= zero
 *					 however, evaluation criterion do not indicate it as a requirement, so doing as I see fit.
 */

#ifndef FACTOR_H
#define FACTOR_H

#ifndef CONST
#define CONST
const short int QUIT = 0;
const short int INVALID = -1;
const short int CONTINUE = 1;
#endif

short int factorUserComputerInterface();
short int factorComputerUserInterface();
void factorVerboseInstructions();
void factorQuitInstructions();
int factorInput();
short int factor(int value);

#endif // FACTOR_H
