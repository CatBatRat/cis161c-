/*
 *	Author:			Jame J Kalafus
 *	Date:			02018-10-08
 *	Description:	CS161+ Week 3 homework demonstrating sequence and selection.
 */

#include <iostream>
#include <limits>
#include <cmath>

#ifndef HACKENBUSH_H
#define HACKENBUSH_H

#ifndef CONST
#define CONST
const short int QUIT = 0;
const short int INVALID = -1;
const short int CONTINUE = 1;
#endif

const bool HACKENBUSH__ROUND_UP_REMOVED = true;
const bool HACKENBUSH__USER_PLAYS_FIRST = true;

const int HACKENBUSH__MAX_REMOVE = 3;
const int HACKENBUSH__MIN_REMOVE = 1;
const int HACKENBUSH__TERMINAL_STATE = 0;
const int HACKENBUSH__INITIAL_STATE = 11;

const int HACKENBUSH__MIN_GAME = HACKENBUSH__TERMINAL_STATE + HACKENBUSH__MAX_REMOVE + 1;
const int HACKENBUSH__MAX_GAME = std::numeric_limits<int>::max();

const short int HACKENBUSH__UN_INITIALIZED = INVALID; // needs pseudo-random initialization of game state

void hackenbushUserComputerInterface();
void hackenbushVerboseInstructions();
void hackenbushTerseInstructions();
void hackenbushQuitInstructions();

class Hackenbush
{
	public:
				 	Hackenbush()
		{
		}
		void		play();
	private:
		void		initialize()
		{
			Hackenbush::game_state = HACKENBUSH__INITIAL_STATE; // TODO randomize initial state
			Hackenbush::is_user_turn_register = HACKENBUSH__USER_PLAYS_FIRST;
		}

		void		echo_game_state()
		{
			std::cout << "Sticks: " << Hackenbush::get_state() << std::endl;
			for ( int counter = 0; counter < Hackenbush::get_state(); counter++ )
			{
				std::cout << "|";
			}
			std::cout << std::endl;
		}
		void		echo_player_turn()
		{
			if ( Hackenbush::is_user_turn() )
			{
				std::cout << "It's your turn." << std::endl;
			}
			else
			{
				std::cout << "It's not your turn." << std::endl;
			}
		}

		int	get_user_move();
		int	get_computer_move();

		int	game_state = HACKENBUSH__UN_INITIALIZED;
		int	get_state()
		{
			return Hackenbush::game_state;
		}

		bool		is_valid_move(int move)
		{
			if ( (Hackenbush::get_state()-move >= HACKENBUSH__TERMINAL_STATE) and ( (HACKENBUSH__MIN_REMOVE <= move) and (move <= HACKENBUSH__MAX_REMOVE) ) )
			{
				return true;
			}
			return false;
		}
		bool		apply_move(int move)
		{
			bool result = Hackenbush::is_valid_move(move);
			if ( result )
			{
				game_state -= move;
			}
			else
			return result;
		}

		bool		is_user_turn_register = HACKENBUSH__USER_PLAYS_FIRST;
		bool		is_user_turn()
		{
			return is_user_turn_register;
		}
		void		toggle_turn()
		{
			if ( is_user_turn() == true )
			{
				is_user_turn_register = false;
			}
			else
			{
				is_user_turn_register = true;
			}
		}

		bool		is_game_over()
		{
			return ( Hackenbush::get_state() == HACKENBUSH__TERMINAL_STATE );
		}

		bool		play_again()
		{
			std::cout << "Play again? (y/n) " << std::endl;
			switch ( toolInputString()[0] )
			{
				case 'y': return true;
				case 'n': return false;
			}
			return false;
		}
};

#endif // HACKENBUSH_H
