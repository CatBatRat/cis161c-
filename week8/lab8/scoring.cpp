#include <iostream>
#include "scoring.h"

bool ifNum(int n,int on,int tw,int th,int fo,int fi,int si) {
    if(on==n or tw==n or th==n or fo==n or fi==n or si==n)
        return true;
    else
        return false;
}

int sumer(int on,int tw,int th,int fo,int fi,int si) {
    return
        1*on+2*tw+3*th+4*fo+5*fi+6*si;
}

int scoreOnes(int ones, int twos, int threes, int fours, int fives, int sixes) {
    return ones*1;
}

int scoreTwos(int ones, int twos, int threes, int fours, int fives, int sixes) {
    return twos*2;
}

int scoreThrees(int ones, int twos, int threes, int fours, int fives, int sixes) {
    return threes*3;
}

int scoreFours(int ones, int twos, int threes, int fours, int fives, int sixes) {
    return fours*4;
}

int scoreFives(int ones, int twos, int threes, int fours, int fives, int sixes) {
    return fives*5;
}

int scoreSixes(int ones, int twos, int threes, int fours, int fives, int sixes) {
    return sixes*6;
}

int scoreThreeOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes) {
    if(ifNum(3,ones,twos,threes,fours,fives,sixes))
        return sumer(ones,twos,threes,fours,fives,sixes);
    else
        return 0;
}

int scoreFourOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes) {
    if(ifNum(4,ones,twos,threes,fours,fives,sixes))
        return sumer(ones,twos,threes,fours,fives,sixes);
    else
        return 0;
}

int scoreFullHouse(int ones, int twos, int threes, int fours, int fives, int sixes) {
    if((ones==3 or twos==3 or threes==3 or fours==3 or fives==3 or sixes==3)
            and (ones==2 or twos==2 or threes==2 or fours==2 or fives==2 or sixes==2))
        return 25;
    else
        return 0;
}

int scoreSmallStraight(int ones, int twos, int threes, int fours, int fives, int sixes) {
    if( (ones and twos and threes and fours)
            or (twos and threes and fours and fives)
            or (threes and fours and fives and sixes))
        return 30;
    else
        return 0;
}

int scoreLargeStraight(int ones, int twos, int threes, int fours, int fives, int sixes) {
    if ((ones and twos and threes and fours and fives)
            or (twos and threes and fours and fives and sixes))
        return 40;
    else
        return 0;
}

int scoreYahtzee(int ones, int twos, int threes, int fours, int fives, int sixes) {
if(ones==5 or twos==5 or threes==5 or fours==5 or fives==5 or sixes==5)
    return 50;
else
    return 0;
}

int scoreChance(int ones, int twos, int threes, int fours, int fives, int sixes) {
    return sumer(ones,twos,threes,fours,fives,sixes);
}
