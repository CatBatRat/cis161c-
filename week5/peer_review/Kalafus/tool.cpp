/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ common tools
 */

#include <cstring> // std::string
#include <iostream> /*
					 * std::cin
					 * std::streamsize
					 */
#include <limits> 	/*
					 * std::numeric_limits<std::streamsize>::max()
					 */
#include "tool.h"

void toolFlushInput()
{
	std::cin.clear(); // clear's error flag, allowing further input or reading.
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n'); // flushes buffer.
}

std::string toolInputString()
{
	// input:	void (keyboard stroke batches accessed via std::cin)
	// output:	std::string
	// 			else (if input fails)
	// 			returns an empty std::string.
	std::string input;

	std::cin >> input;
	if ( std::cin )
	{
		return input;
	}
	else
	{
		toolFlushInput(); // in case of bad input, flush the buffer.
	}
	return "";
}

int toolInputInt(std::string input)
{
	// input:	a std::string
	// output:	recast as a int
	// 			else (if recast fails)
	// 			returns min value for type int.
	try
	{ 
		return stoi(input);
	}
	catch ( std::invalid_argument e )
	{
	}
	return SENTINAL_INT;
}

long long toolInputLongLong(std::string input)
{
	// input:	a std::string
	// output:	recast as a long long
	// 			else (if recast fails)
	// 			returns min value for type long long.
	try
	{ 
		return stoll(input);
	}
	catch ( std::invalid_argument e )
	{
	}
	return SENTINAL_LONG_LONG;
}

/*
long double toolInputLongDouble(std::string input)
{
	// input: 	a std::string
	// output: 	recast as a long double
	// 			else (if recast fails)
	// 			returns min value for type long double.
	try
	{ 
		return stold(input); // to do twice.
	}
	catch ( std::invalid_argument e )
	{
	}
	return SENTINAL_LONG_DOUBLE;
}
*/
