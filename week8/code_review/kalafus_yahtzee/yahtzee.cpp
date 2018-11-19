#include "yahtzee.h"

/*
 *	File:	yahtzee.h
 *	Author:	Jame Kalafus
 *	Date:	02018-11-17
 *	About:	Defines scoring functions for Yahtzee.
 */

// Scoring Functions


int scoreOnes(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * Score of Ones is the sum of all Ones face values showing.
	 */
	return ones * 1;
}

int scoreTwos(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * Score of Twos is the sum of all Twos face values showing.
	 */
	return twos * 2;
}

int scoreThrees(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * Score of Threes is the sum of all Threes face values showing.
	 */
	return threes * 3;
}

int scoreFours(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * Score of Fours is the sum of all Fours face values showing.
	 */
	return fours * 4;
}

int scoreFives(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * Score of Fives is the sum of all Fives face values showing.
	 */
	return fives * 5;
}

int scoreSixes(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * Score of Sixes is the sum of all Sixes face values showing.
	 */
	return sixes * 6;
}

int scoreThreeOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * score of Three of a Kind is the sum of all die face values.
	 */
	if ( helperOfAKind(3, ones, twos, threes, fours, fives, sixes) )
	{
		return helperSumDice(ones, twos, threes, fours, fives, sixes);
	}
	return 0;

}

int scoreFourOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * score of Four of a Kind is the sum of all die face values.
	 */
	if ( helperOfAKind(4, ones, twos, threes, fours, fives, sixes) )
	{
		return helperSumDice(ones, twos, threes, fours, fives, sixes);
	}
	return 0;
}

int scoreFullHouse(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * score of Full House (3 of a kind and a separate 2 of a kind) is 25.
	 */
	if ( ((helperOfAKind(3, ones = ones)) and (helperOfAKind(2, ones - 3, twos, threes, fours, fives, sixes)))
	  or ((helperOfAKind(3, twos = twos)) and (helperOfAKind(2, ones, twos - 3, threes, fours, fives, sixes)))
	  or ((helperOfAKind(3, threes = threes)) and (helperOfAKind(2, ones, twos, threes - 3, fours, fives, sixes)))
	  or ((helperOfAKind(3, fours = fours)) and (helperOfAKind(2, ones, twos, threes, fours - 3, fives, sixes)))
	  or ((helperOfAKind(3, fives = fives)) and (helperOfAKind(2, ones, twos, threes, fours, fives - 3, sixes)))
	  or ((helperOfAKind(3, sixes = sixes)) and (helperOfAKind(2, ones, twos, threes, fours, fives, sixes - 3))) )
	{
		return SCORE_FULL_HOUSE;
	}
	return 0;
}

int scoreSmallStraight(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * score of Small Straight (4 sequential numbers rolled) is 30.
	 */
	if ( ((ones >= 1) and (twos >= 1) and (threes >= 1) and (fours >= 1))
	  or ((twos >= 1) and (threes >= 1) and (fours >= 1) and (fives >= 1))
	  or ((threes >= 1) and (fours >= 1) and (fives >= 1) and (sixes >= 1)) )
	{
		return SCORE_SMALL_STRAIGHT;
	}
	return 0;
}

int scoreLargeStraight(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * score of Large Straight (5 sequential numbers rolled) is 40.
	 */
	if ( ((ones >= 1) and (twos >= 1) and (threes >= 1) and (fours >= 1) and (fives >= 1))
	  or ((twos >= 1) and (threes >= 1) and (fours >= 1) and (fives >= 1) and (sixes >= 1)) )
	{
		return SCORE_LARGE_STRAIGHT;
	}
	return 0;
}

int scoreYahtzee(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * score of Yahtzee (5 of a kind) is 50.
	 */
	if ( helperOfAKind(5, ones, twos, threes, fours, fives, sixes) )
	{
		return SCORE_YAHTZEE;
	}
	return 0;
}

int scoreChance(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * score of Chance in yahtzee is the sum of all die face values showing, so return that sum.
	 */
	return helperSumDice(ones, twos, threes, fours, fives, sixes);
}

// Helper Functions

bool helperOfAKind(short int threshold, int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * determines whether there are at least 'threshold' quantity of any of the counts of d6 dice rolls;
	 * returns boolean accordingly.
	 */
	if ( (sixes >= threshold)
	  or (fives >= threshold)
	  or (fours >= threshold)
	  or (threes >= threshold)
	  or (twos >= threshold)
	  or (ones >= threshold) )
	{
		return true;
	}
	return false;
}

int helperSumDice(int ones, int twos, int threes, int fours, int fives, int sixes)
{
	/*
	 * Sums the face values from counts of d6 dice rolls.
	 */
	return (1 * ones)
		 + (2 * twos)
		 + (3 * threes)
		 + (4 * fours)
		 + (5 * fives)
		 + (6 * sixes);
}
