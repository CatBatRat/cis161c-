#include <iostream>
#include <cstdlib>

//here, it is specified that cout and cin be used from the standard namespace
using std::cout;
using std::cin;
//here, constant characters are defined to represent rock, paper, scissors, yes, and no
const char rock = 'r';
const char paper = 'p';
const char scissors = 's';
const char yes = 'y';
const char no = 'n';
//here, a function is defined to display brief and friendly instructions to the player
void displayInstructions()
{
  cout << "Welcome to a sporting game of rock paper scissors." << "\n" << "\n";
  cout << "Please enter your move, (r/p/s): ";
  return;
}
//here, a function is defined to get the player's move
char getMove()
{
  //here, the player's input is taken
  char input;
  cin >> input;
  //here, the player's input is validated
  while (input != rock && input != paper && input != scissors && input != 'R' && input != 'P' && input != 'S')
    {
      cout << "That is not a legal move. Enter r, p, or s: ";
      cin.clear();
      cin >> input;
    }
  //here, if the player's move was valid, it is returned
  return input;
}
//here, a function is defined to conduct the game and determine the winner
int getWinner(char user_move, char comp_move)
{
  //here, an integer variable is defined for keeping track of the how the game ends
  int result;
  //here, an integer variable is defined for randomly determining the computer's move
  int number = rand() % 3 + 1;
  //here, a boolean variable is set for keeping track of when the game is in progress
  bool playing = true;
  while (playing)
    {
      //get user move
      user_move = getMove();
      //get computer move
      switch (number)
	{
	case 1:
	  comp_move = rock;
	  break;
	case 2:
	  comp_move = paper;
	  break;
	case 3:
	  comp_move = scissors;
	  break;
	}
      //determine how the game ends
      if ((user_move == rock || user_move == 'R') && comp_move == scissors)
	{
	  playing = false;
	  result = 1;
	  cout << "Congratulations, your rock crushed the computer's scissors!" << "\n" << "\n";
	}
      else
	if ((user_move == paper || user_move == 'P') && comp_move == rock)
	  {
	    playing = false;
	    result = 1;
	    cout << "Congratulations, your paper covered the computer's rock!" << "\n" << "\n";
	  }
	else
	  if ((user_move == scissors || user_move == 'S') && comp_move == paper)
	    {
	      playing = false;
	      result = 1;
	      cout << "Congratulations, your scissors cut the computer's paper!" << "\n" << "\n";
	    }
	  else
	    if (comp_move == rock && (user_move == scissors || user_move == 'S'))
	      {
		playing = false;
		cout << "Unfortunately, the computer's rock smashed your scissors." << "\n" << "\n";
		result = 2;
	      }
	    else
	      if (comp_move == paper && (user_move == rock || user_move == 'R'))
		{
		  playing = false;
		  result = 2;
		  cout << "Unfortunately, the computer's paper covered your rock." << "\n" << "\n";
		}
	      else
		if (comp_move == scissors && (user_move == paper || user_move == 'P'))
		  {
		    playing = false;
		    result = 2;
		    cout << "Unfortunately, the computer's scissors cut through your paper." << "\n" << "\n";
		  }
		else
		  if (user_move == comp_move)
		    {
		      playing = false;
		      result = 3;
		      cout << "The round was a tie." << "\n" << "\n";
		    }
      //return an appropriate value
      if (result = 1)
	return 1;
      else
	if (result = 2)
	  return 2;
        else
	  if (result = 3)
	    return 3;
    }
}
//here, a function is defined to repeat the game if the player so desires
bool playAgain()
{
  //here, necessary variables are defined
  char user_move;
  char comp_move;
  char again;
  //here, the player is asked whether they want to play again and input is taken
  cout << "Do you want to play another round (y/n)? ";
  cin >> again;
  //here, the player input is validated
  while (again != yes && again != 'Y' && again != no && again != 'N')
    {
      cout << "Invalid input.  Enter y/n: ";
      cin.clear();
      cin >> again;
    }
  //here, as long as the player wants to play again, the game is repeated
  while (again == yes || again == 'Y')
    {
      displayInstructions();
      getWinner(user_move, comp_move);
      playAgain();
      return true;
    }
  while (again == no || again == 'N')
    {
        return false;
        exit(getWinner(user_move, comp_move));
        exit(playAgain());
    }
}
//here, the main function is defined
int main()
{
  char user_move;
  char comp_move;
  //here, the displayInstructions() and getWinner() functions are called, starting the first round
  displayInstructions();
  getWinner(user_move, comp_move);
  //here, as long as the player wants to play again, the playAgain() function will start new rounds
  while (playAgain())
    {
      displayInstructions();
      getWinner(user_move, comp_move);
    }
  return 0;
}
