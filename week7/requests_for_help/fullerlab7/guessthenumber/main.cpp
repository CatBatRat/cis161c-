#include <iostream>
#include <cstdlib>
//here, it is specified that cout and cin be used from the standard namespace
using std::cout;
using std::cin;
//here, constant integers are defined to represent the minimum and maximum values of the guessing range
const int minimum = 2;
const int maximum = 98;
//here, a function is defined to display brief and friendly instructions to the player
void displayInstructions()
{
  cout << "Guess a number between 1 and 99 and enter it here: ";
  return;
}
//here, a function is defined to get and return a random number between 1 and 99
int getNumber(int minimum, int maximum)
{
  int randomnum;
  randomnum = rand() % maximum + minimum;
  return randomnum;
}
//here, a function is defined to get and return the player's guess
int getMove(int minimum, int maximum)
{
  int choice;
  cin >> choice;

  while (choice < minimum || choice > maximum)
    {
      cout << "Invalid input.  Try again: ";
      cin.clear();
      cin >> choice;
    }
  return choice;
}
//here, a function is defined to return whether the player wants to go again
bool playAgain()
{
  char again;
  cout << "Do you want to go again? (y/n) ";
  cin >> again;

  while (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
    {
      cout << "Invalid input.  Enter y or n: ";
      cin.clear();
      cin >> again;
    }

  if (again == 'y' || again == 'Y')
    return true;
  else
      return false;
}

int main()
{
  //here, getNumber() is called, returning a random number which is then stored as the correct answer
  int answer = getNumber(minimum, maximum);
  //here, the displayInstructions() function is called, informing the player to make the first guess
  displayInstructions();
  //here, an integer variable representing the number of guesses needed is defined and initialized to zero
  int numberofguesses = 0;
  //here, the getMove() function is called, returning the validated player input
  int choice = getMove(minimum, maximum);

  do
        {
	  if (choice < answer)
            {
	      cout << "Your number was too small, try again: ";
	      choice = getMove(minimum, maximum);

	      while (choice < minimum || choice > maximum)
                {
		  cout << "Invalid input." << "\n" << "\n";
		  displayInstructions();
		  choice == getMove(minimum, maximum);
                }
	      numberofguesses++;
            }
	  else
	    if (choice > answer)
	      {
		cout << "Your number was too large, try again: ";
		choice = getMove(minimum, maximum);

		while (choice > maximum || choice < minimum)
		  {
		    cout << "Invalid input." << "\n" << "\n";
		    displayInstructions();
		    choice == getMove(minimum, maximum);
		  }
		numberofguesses++;
	      }
        } while (choice != answer);
      //here
      if (choice = answer)
	{
	  cout << "Congratulations, you guessed the number!" << "\n" << "\n";
	  cout << "It took you " << numberofguesses << " guesses." << "\n";
	  playAgain();

	  while (playAgain())
	    {
	      main();
	    }
	}
      return 0;
}
