
/*
 *	File:	yahtzee.h
 *	Author:	Jame Kalafus
 *	Date:	02018-11-17
 *	About:	Defines scoring functions for Yahtzee.
 */

#ifndef YAHTZEE_H
#define YAHTZEE_H

// Magic Numbers
const int SCORE_FULL_HOUSE = 25;
const int SCORE_SMALL_STRAIGHT = 30;
const int SCORE_LARGE_STRAIGHT = 40;
const int SCORE_YAHTZEE = 50;

// Scoring functions
int scoreOnes(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreTwos(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreThrees(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreFours(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreFives(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreSixes(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreThreeOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreFourOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreFullHouse(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreSmallStraight(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreLargeStraight(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreYahtzee(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreChance(int ones, int twos, int threes, int fours, int fives, int sixes);

// Helper Functions
int helperSumDice(int ones, int twos, int threes, int fours, int fives, int sixes);
bool helperOfAKind(short int threshold, int ones = 0, int twos = 0, int threes = 0, int fours = 0, int fives = 0, int sixes = 0);

#endif // YAHTZEE_H
