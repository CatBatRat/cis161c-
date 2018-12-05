#ifndef SCORING_H
#define SCORING_H
#include <iostream>

using namespace std;

//constants are used for giving the set points for each different part of the game
//that is not adding how many you got of one kind
const int SCORE_FULL_HOUSE = 25;
const int SCORE_SMALL_STRAIGHT = 30;
const int SCORE_LARGE_STRAIGHT = 40;
const int SCORE_YAHTZEE = 50;

//these are for all the declarations of each part of the yahtzee game
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

//these helpers are used to help calculate the total sum of dice and
//all of the 3/4/Yahtzees that might show up in the game
int helperSumDice(int ones, int twos, int threes, int fours, int fives, int sixes);

bool helperOfAKind(short int threshold, int ones = 0, int twos = 0, int threes = 0, int fours = 0, int fives = 0, int sixes = 0);


#endif // SCORING_H
