#include "scoring.h"

/* Checks for a die to have a given number and returns true if there is a match
 * for any. For use in the scoreThreeOfAKind(), scoreFourOfAKind(),
 * scoreFullHouse(), and scoreYahtzee() functions. */
bool ifNum( int n, int on, int tw, int th, int fo, int fi, int si ) {
    if( on>=n or tw>=n or th>=n or fo>=n or fi>=n or si>=n )
        return true;
    else
        return false;
}

/* Return the sum of all input numbers. For use in scoreThreeOfAKind(),
 * scoreFourOfAKind, and scoreChance() functions. */
int sumDie( int on, int tw, int th, int fo, int fi, int si ) {
    return
        1*on+2*tw+3*th+4*fo+5*fi+6*si;
}

/* Score the number of ones * 1 */
int scoreOnes( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    return ones*1;
}

/* Score the number of twos * 2 */
int scoreTwos( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    return twos*2;
}

/* Score the number of threes * 3 */
int scoreThrees( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    return threes*3;
}

/* Score the number of fours * 4 */
int scoreFours( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    return fours*4;
}

/* Score the number of fives * 5 */
int scoreFives( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    return fives*5;
}

/* Score the number of sixes * 6 */
int scoreSixes( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    return sixes*6;
}

/* If there are 3 or more of any given number, return the sum of the number of
 * all die. */
int scoreThreeOfAKind( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    if( ifNum( 3, ones, twos, threes, fours, fives, sixes ) )
        return sumDie( ones, twos, threes, fours, fives, sixes );
    else
        return 0;
}

/* If there are 4 or more of any given number, return the sum of the number of
 * all die. */
int scoreFourOfAKind( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    if( ifNum( 4, ones, twos, threes, fours, fives, sixes ) )
        return sumDie( ones, twos, threes, fours, fives, sixes );
    else
        return 0;
}

/* Checks if there are exactly 3 of a kind and 2 of a kind. Return true */
int scoreFullHouse( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    if(( ones==3 or twos==3 or threes==3 or fours==3 or fives==3 or sixes==3 )
            and (ones==2 or twos==2 or threes==2 or fours==2 or fives==2 or sixes==2 ))
        return SCOREFULLHOUSE;
    else
        return 0;
}

/* All inputs are zero unless there is a number present, so you only need to
 * check for a non zero value. This tests for the three possible combinations
 * available when there are only five die to work with. They can be in any
 * order. Return 30 if true, 0 if false. */
int scoreSmallStraight( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    if(( ones and twos and threes and fours )
            or ( twos and threes and fours and fives )
            or ( threes and fours and fives and sixes ))
        return SCORESMALLSTRAIGHT;
    else
        return 0;
}

/* This tests for the three possible combinations available when there are only
 * five die to work with. They can be in any order. Return 40 if true, 0 if
 * false. */
int scoreLargeStraight( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    if (( ones and twos and threes and fours and fives )
            or ( twos and threes and fours and fives and sixes ))
        return SCORELARGESTRAIGHT;
    else
        return 0;
}

/* Simply check for any number to == 5 and return 50. Else return 0. */
int scoreYahtzee( int ones, int twos, int threes, int fours, int fives, int sixes ) {
if(ifNum( 5, ones, twos, threes, fours, fives, sixes ))
    return SCOREYAHTZEE;
else
    return 0;
}

/* Take the sum of all dice and return the number. */
int scoreChance( int ones, int twos, int threes, int fours, int fives, int sixes ) {
    return sumDie( ones,twos,threes,fours,fives,sixes );
}
