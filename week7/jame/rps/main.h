/*
 * File: main.h
 * Author: Jame J. Kalafus
 * Date: 02018-11-12
 * Description: User interface to play games of rock-paper-scissors with the computer player.
 * 	For a more in depth specification, see file main.cpp
 */
#include <string>

#ifndef MAIN_H
#define MAIN_H

void displayInstructions();

char getMove();
char generateMove();

short int getWinner(char userMove, char computerMove);
// bool playAgain(); // see tool.cpp

void announceWinner(short int winner, char userMove, char computerMove);

// Supporting functions
const std::string rpsCharToWord(char ch);

#endif // MAIN_H
