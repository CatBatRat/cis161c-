/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-19
 *	Description:	input: user supplies integers 1-100
 *					processing: remember extrema (greatest_value and least_value integers encountered)
 *					output: when user enters 0, send extrema to std::cout.
 *							when user enters other values, send WARNING to std::cout.
 */

#ifndef EXTREMA_H
#define EXTREMA_H

#ifndef CONST
#define CONST
const short int QUIT = 0;
const short int INVALID = -1;
const short int CONTINUE = 1;
#endif

const int INIT_LEAST_VALUE = std::numeric_limits<int>::max();
const int INIT_GREATEST_VALUE = std::numeric_limits<int>::min();

const int BOUNDARY_LOWER = 1;
const int BOUNDARY_UPPER = 100;

short int extremaUserComputerInterface();
short int extremaComputerUserInterface();
void extremaVerboseInstructions();
void extremaQuitInstructions();
int extremaInput();
void extrema(int value);

#endif // EXTREMA_H
