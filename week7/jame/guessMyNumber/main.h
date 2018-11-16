/*
 * File: main.h
 * Author: Jame J Kalafus
 * Date: 02018-11-12
 * Description: Number Guessing Game
 * 	complete SPECIFICATION in main.cpp.
 */

#ifndef MAIN_H
#define MAIN_H

const int MIN = 1;
const int MAX = 99;

void displayInstructions();

int getNumber(int min = MIN, int max = MAX);
int getMove(int min = MIN, int max = MAX);

// bool playAgain(); // see tool.cpp

#endif // MAIN_H
