/*
 * File: main.cpp Auther: Jame J Kalafus Date: 02018-11-12 Description: Intro
 * C++ Week 7 homework; specification as follows:

Rock, Paper, Scissors

Create version of the Rock, Paper, and Scissors game using functions. The game must:

1) Display clear set of instructions to the user

2) Input R, P, or S from the user. Validate the input, if incorrect continually prompt the user to re-enter until correct. Either upper or lower case is ok.

3) Display clear output describing the outcome of the game including the user's pick, the computer's pick and the victor,

4) Ask the user if he/she would like to play again and repeat the entire game again as necessary.


You need to have at least the following four functions:

  displayInstructions no inputs, displays the instructions

  getMove no inputs, get move from user and validate, return lower case char (‘r’,’p’,’s’)

  getWinner inputs are two chars (user move and computer move)
	  return 1 for user victory, 2 for computer victory, 3 for tie

  playAgain no inputs, return true if the user wants  to go again, false if they do not


Your program should have appropriate comments (including at least one per function) and you should use constants where appropriate. All input should be validated.
*/

#include <iostream>
#include <string>
#include <ctime>
#include "main.h"
#include "tool.h"

int main()
{
	/*
	 * provides User Interface to play rock paper scissors
	 */

	char userMove = ' ';
	char computerMove = ' ';
	short int victor = -1;

	std::srand(static_cast<unsigned>(std::time(0)));


	displayInstructions();

	do
	{
		userMove = getMove(); // prompt user for their move.
		computerMove = generateMove(); // prompt computer to return its move.
		victor = getWinner(userMove, computerMove); // determine who won.
		announceWinner(victor, userMove, computerMove); // announce the victor to the user with a nice message reflecting precise final game state.
	}
	while ( playAgain() );


	return 0;
}


void displayInstructions()
{
	/*
	 * Instructions for playing a game of Rock Paper Scissors.
	 */
	std::cout
		<< "Welcome to Rock Paper Scissors!" << std::endl << std::endl
		<< "Paper covers Rock, Rock breaks Scissors, Scissors cut Paper" << std::endl
		<< "Enter r, p, or s to pit yourself against the Computer!" << std::endl;
}

char getMove()
{
	/*
	 * Get the users move via keyboard input; returns the first character encountered that matches one of the characters we are looking for (r,p,s or R,P,S).
	 */
	char move = ' ';
	do
	{
		std::cout
			<< "(R)ock, (P)aper, or (S)cissor"
			<< std::endl
			<< "? ";
		std::cin >> move;
		flushCin(); // flush input after getting a response so that remaining characters in the line will not be interpreted by the next function reading from std::cin.
	}
	while ( (move != 'r') and (move != 'p') and (move != 's')
	and	(move != 'R') and (move != 'P') and (move != 'S') );

	return move;
}

char generateMove()
{
	/*
	 * Models the computer as a random actor, and gets a random throw from them.
	 */
	switch(getRandom(0,2))
	{
		case 0: return 'r';
		case 1: return 'p';
		case 2: return 's';
	}
	std::cout << "ERROR: Something went wrong getting a random move from the computer; throwing Paper by default.";
	return 'p'; // control won't reach here, but it will quiet the warning, and paper makes naive sense as a default because the most common first throw is rock in the embodied version of this game.
}

short int USER_VICTORY = 1;
short int COMPUTER_VICTORY = 2;
short int TIE = 3;
short int getWinner(char userMove, char computerMove)
{
	/*
	 * return 1 on user victory
	 * return 2 on computer victory
	 * return 3 on tie
	 */

	if ( (userMove == computerMove) or (userMove == (computerMove + 'a' - 'A')) or ((userMove + 'a' - 'A') == computerMove) ) // the second two conditions are a repeat of the first symmetric case condition, taking into account the two antisymmetric configurations of differing case. move+'a'-'A' is a quick hack to shift from lowercase ascii to uppercase.
	{
		// get this case out of the way in general so we can disregard the possibility in all remaining logic
		return TIE;
	}
	else if ( (userMove == 'r') or (userMove == 'R') )
	{
		if ( (computerMove == 'p') or (computerMove == 'P') )
		{
			// paper beats rock; computer victory.
			return COMPUTER_VICTORY;
		}
		else if ( (computerMove == 's') or (computerMove == 'S') )
		{
			// rock beats scissor; user victory.
			return USER_VICTORY;
		}
	}
	else if ( (userMove == 'p') or (userMove == 'P') )
	{
		if ( (computerMove == 's') or (computerMove == 'S') )
		{
			// scissor beats paper; computer victory.
			return COMPUTER_VICTORY;
		}
		else if ( (computerMove == 'r') or (computerMove == 'R') )
		{
			// paper beats rock; user victory.
			return USER_VICTORY;
		}
	}
	else if ( (userMove == 's') or (userMove == 'S') )
	{
		if ( (computerMove == 'r') or (computerMove == 'R') )
		{
			// rock beats scissor; computer victory.
			return COMPUTER_VICTORY;
		}
		else if ( (computerMove == 'p') or (computerMove == 'P') )
		{
			// scissor beats paper; user victory.
			return USER_VICTORY;
		}
	}

	return 0; // execution should not reach here, so return a default invalid value.
}

void announceWinner(short int victor, char userMove, char computerMove)
{
	if ( victor == USER_VICTORY )
	{
		// user won
		std::cout
			<< "Congratulations ~!~ You Win!  Your "
			<< rpsCharToWord(userMove)
			<< " defeats computer "
			<< rpsCharToWord(computerMove)
			<< "."
			<< std::endl;
	}
	else if ( victor == COMPUTER_VICTORY )
	{
		// computer won
		std::cout
			<< "Good Effort ~!~ You Lose!  Computer "
			<< rpsCharToWord(computerMove)
			<< " defeats your "
			<< rpsCharToWord(userMove)
			<< "."
			<< std::endl;
	}
	else if ( victor == TIE )
	{
		// tie
		std::cout
			<< "Good Effort ~!~ You Tie With Computer! You both chose "
			<< rpsCharToWord(userMove)
			<< "."
			<< std::endl;
	}
	else
	{
		std::cout << "ERROR: announceWinner: unable to determine the victor using flag value of '" << victor << "'." << std::endl;
	}
}

const std::string rpsCharToWord(char character)
{
	/*
	 * converts char r,p,s (case insensitive) to the corresponding string rock,paper,scissor
	 */
	switch (character)
	{
		case 'r':
		case 'R': return "rock";
		case 'p':
		case 'P': return "paper";
		case 's':
		case 'S': return "scissor";
	}
	// execution should not reach this point...
	return "???"; // ... so return a sensible default value
}
