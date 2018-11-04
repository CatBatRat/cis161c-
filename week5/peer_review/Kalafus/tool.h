/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ common tools
 */

#include <string>	// std::string
#include <limits>	// std::numeric_limits<int>::min();
					// std::numeric_limits<long long>::min();

#ifndef TOOL_H
#define TOOL_H

const int SENTINAL_INT = std::numeric_limits<int>::min();
const long long SENTINAL_LONG_LONG = std::numeric_limits<long long>::min();
// const long double SENTINAL_LONG_DOUBLE = std::numeric_limits<long double>::min();

void toolFlushInput();
std::string toolInputString();
int toolInputInt(std::string input);
long long toolInputLongLong(std::string input);
// long double toolInputLongDouble(std::string input);

#endif // TOOL_H
