/*
 * File: tool.cpp
 * Auther: Jame J Kalafus
 * Date: 02018-11-12
 * Description: utility functions; think, multi-tool: universal tools.
 */

#include <iostream>
#include <random>
#include <limits>
#include "tool.h"

bool playAgain()
{
	/*
	 * Ask the user if they want to keep playing.
	 * Get the answer from the first character matching any of the values yYnNqQ.
	 * 	return true if user responds with a yY
	 * 	return false if user responds with a nNqQ
	 */
	char choice = ' ';

	do
	{
		std::cout << "Play again? (y,n,q) ";
		std::cin >> choice;
		flushCin(); // flush input after getting a response so that remaining characters in the line will not be interpreted by the next function reading from std::cin.

		switch (choice)
		{
			case 'y':
			case 'Y': return true;
			case 'n':
			case 'N':
			case 'q':
			case 'Q': return false;
		}
	}
	while ( std::cin ); // QUESTION would it be better to use a flag / Is it considered a code smell to return from inside a loop?

	// execution should not reach this state, since we are continuing the loop until std::cin fails to read a character; something must have gone wrong, so, exit.
	return false;
}

void flushCin()
{
	/* 
	 * flush std::cin when it hangs on invalid user input.
	 */

	std::cin.clear();
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
}

int getRandom(int lower_bound = 0, int upper_bound = RAND_MAX)
{
	/*
	 * get an evenly weighted random number within the specified range, inclusive.
	 */

	const int width = upper_bound - lower_bound + 1; // size of user specified range.
	const int clip = RAND_MAX - ((RAND_MAX + 1) % width); // we throw out randomly generated values which are larger than this limit; this is the adjustment that makes our random numbers evenly weighted, rather than tending to be biased toward choosing the lowest values slightly more often. (for ranges over about 2^13 and not too near either 2^14 or 2^15 the bias is especially significant, in the extreme case, resulting in as much as a double weighting of some values compared to others).

	if ( width > RAND_MAX ) // warn users when they are asking for a larger range than we have handling for.
	{
		std::cout << "WARNING: range exceeds width of random number generator; this condition is not handled. Your random number will be between " << lower_bound << " and " << (lower_bound + RAND_MAX) << "." << std::endl;
	}


	int random = std::rand();
	while ( random > clip ) // throw out overrepresented values on the top-end...
	{
		random = std::rand(); // ... by overwriting them with a new random value
	}

	return lower_bound + random % width; // we could have just done this from the top, but the mathematician in me was interested, and the computer scientist in me wanted the practice.
}
