#ifndef MAIN_H
#define MAIN_H

short unsigned int mainMenu();
short unsigned int mainMenuInput();

void flushInput();

void commissionCalculatorPrimer();
void commissionCalculatorQuitInstructions();
short unsigned int commissionCalculatorUI();
double commissionCalculatorInput();
double commissionCalculator(double total);

void reversePolishNotationCalculatorPrimer();
void reversePolishNotationCalculatorQuitInstructions();
short unsigned int reversePolishNotationCalculatorUI();
// long long reversePolishNotationCalculatorInput(long long input[]); // TODO pull out the input function; this will facilitate specialized handling for different types, including quitting on appearance of initial [Qq] characters.
long long reversePolishNotationCalculator(long long leftHandOperand, long long rightHandOperand, char operation);

#endif // MAIN_H
