/*
 * File: main.cpp
 * Author: Jame J Kalafus
 * Date: 02018-11-12
 * Description: complete SPECIFICATION below.

 Guess My Number

Create a multi-function version of the Guess My Number game. Your game should generate a random number between 1 and 99, ask the user for a guess, and respond to each guess with correct, too high, or too low as needed. Once the user guesses the number correctly, report how many guesses it took and ask if they want to play again.

You need to have at least the following three functions:

  displayInstructions - no inputs, displays the instructions

  getNumber - inputs are min and max, returns a random number between min and max

  getMove - inputs are min and max, gets, validates, returns an integer from the user
	that is between min and max

   playAgain - no inputs, return true if the user wants  to go again, false if they do not

Your program should have appropriate comments(including at least one per function) and you should use constants where appropriate. All input should be validated.
 */

#include <iostream>
#include <random>
#include "main.h"
#include "tool.h"

int main()
{
	int number = -1;
	int move = -1;

	int counter = -1;

	displayInstructions();

	do
	{
		number = getNumber();
		counter = 0;
		do
		{
			move = getMove();
			counter++;
			if ( move > number )
			{
				std::cout << "too high" << std::endl;
			}
			else if ( move < number )
			{
				std::cout << "too low" << std::endl;
			}
			else if ( move == number )
			{
				std::cout << "You guessed it in " << counter << " tries!" << std::endl;
				if ( counter <= ceil(log(MAX - MIN + 1)/log(2)) )
				{
					std::cout << "You guessed optimally!!" << std::endl;
				}
			}
		}
		while ( move != number );

	}
	while ( playAgain() );
	return 0;
}

void displayInstructions()
{
	std::cout
		<< "Guess a number between " << MIN << " and " << MAX << ", inclusive!" << std::endl
		<< " You can have as many tries as you need! I will count them because I love data!" << std::endl;
}

int getNumber(int min, int max)
{
	return getRandom(min, max);
}

int getMove(int min, int max)
{
	int move = -1;
	bool not_done = true;

	do
	{
		std::cout << "Your guess, please: ";
		std::cin >> move;
		flushCin();
		if ( (min <= move) and (move <= max) )
		{
			not_done = false;
		}
		else
		{
			std::cout << "Please try again: enter a whole number between " << min << " and " << max << ", inclusive.";
		}
	}
	while ( not_done );
	return move;
}

