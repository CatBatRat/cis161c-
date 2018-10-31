/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ Week 6 homework: simple game
 */

#include <iostream> /* std::cout
					 * std::cin
					 * std::endl
					 */
//#include <string> /* std::string */
#include "tool.h"	// toolInputString()
					// toolInputLongLong()
#include "hackenbush.h"

void hackenbushUserComputerInterface()
{
	hackenbushVerboseInstructions();
	hackenbushQuitInstructions();

	Hackenbush game;
	game.play();
}

void hackenbushVerboseInstructions()
{
	// consider the following print statements as dually being commentary.
	std::cout << "There are " << HACKENBUSH__INITIAL_STATE << " sticks on the board to start. Two players alternate in operating on the number of sticks. A player must remove between " << HACKENBUSH__MIN_REMOVE << " and " << HACKENBUSH__MAX_REMOVE << " sticks during their turn. Be the player who, at their turns end, leaves the board with " << HACKENBUSH__TERMINAL_STATE << " sticks remaining to win!" << std::endl;
}

void hackenbushTerseInstructions()
{
	std::cout << "Please remove between " << HACKENBUSH__MIN_REMOVE << " and " << HACKENBUSH__MAX_REMOVE << " sticks." << std::endl;
}

void hackenbushQuitInstructions()
{
	std::cout << "(enter 'q' to quit)" << std::endl;
}

void Hackenbush::play()
{
	/*	input:		
	 *	processing:	
	 *	output:		
	 */

	do // while ( Hackenbush::play_again() );
	{
		Hackenbush::initialize();
	
		int current_move = INVALID;
		do // while ( not Hackenbush::is_game_over() );
		{
			Hackenbush::echo_player_turn(); // give context
			Hackenbush::echo_game_state(); // show game board
			// get a legal move...
			do // while ( not Hackenbush::is_valid_move(current_move) );
			{
				// from the player whose turn it is
				if ( Hackenbush::is_user_turn() )
				{
					current_move = Hackenbush::get_user_move();
					if ( Hackenbush::is_valid_move(current_move) )
					{
						std::cout << "You remove " << current_move << " sticks." << std::endl;
					}
					else
					{
						hackenbushTerseInstructions();
						hackenbushQuitInstructions();
					}
				}
				else
				{
					current_move = Hackenbush::get_computer_move();
					if ( Hackenbush::is_valid_move(current_move) )
					{
						std::cout << "My algorithm removes " << current_move << " sticks." << std::endl;
					}
				}
			}
			while ( not Hackenbush::is_valid_move(current_move) );
			// and apply the move
			Hackenbush::apply_move(current_move);
			if ( Hackenbush::is_game_over() )
			{
			// check if they've won, and if so, announce the outcome and quit.
			// else, change to the next user's turn.
				if ( Hackenbush::is_user_turn() )
				{
					std::cout << "You have won!" << std::endl;
				}
				else
				{
					std::cout << "I, meaning me the algorithm instance, have won!" << std::endl;
				}
			}
			else
			{
				Hackenbush::toggle_turn();
			}
		}
		while ( not Hackenbush::is_game_over() );
	}
	while ( Hackenbush::play_again() );
}

int Hackenbush::get_user_move()
{
	return toolInputLongLong(toolInputString());
}

int Hackenbush::get_computer_move()
{
	int game_state = Hackenbush::get_state();
	if ( (HACKENBUSH__MIN_REMOVE <= game_state ) and (game_state <= HACKENBUSH__MAX_REMOVE) )
	{
		return game_state;
	}
	// TODO else if (HACKENBUSH__TERMINAL_STATE+HACKENBUSH__MAX_REMOVE+1) // if 4 is within reach this turn, computer can force victory next turn.
	return 3; // favor a quick game
}
