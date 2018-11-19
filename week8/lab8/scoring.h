#ifndef __SCORING__
#define __SCORING__

const int SCOREFULLHOUSE = 25;
const int SCORESMALLSTRAIGHT = 30;
const int SCORELARGESTRAIGHT = 40;
const int SCOREYAHTZEE = 50;
/* Each one or the functions the will return the score for a given combination
 * of die in the game of Yahtzee. */
int scoreOnes(int, int, int, int, int, int);

int scoreTwos(int, int, int, int, int, int);

int scoreThrees(int, int, int, int, int, int);

int scoreFours(int, int, int, int, int, int);

int scoreFives(int, int, int, int, int, int);

int scoreSixes(int, int, int, int, int, int);

int scoreThreeOfAKind(int, int, int, int, int, int);

int scoreFourOfAKind(int, int, int, int, int, int);

int scoreFullHouse(int, int, int, int, int, int);

int scoreSmallStraight(int, int, int, int, int, int);

int scoreLargeStraight(int, int, int, int, int, int);

int scoreYahtzee(int, int, int, int, int, int);

int scoreChance(int, int, int, int, int, int);

#endif
