#ifndef SCORING_H_INCLUDED
#define SCORING_H_INCLUDED

const int yahtzeePoints = 50;
const int largeStraightPoints = 40;
const int smallStraightPoints = 30;
const int fullHousePoints = 25;


/* scoreOnes through scoreSixes are functions that return the value
* of the scoring categories.
*/

int sumOfDice(int ones, int twos, int threes, int fours, int fives, int sixes)
{
  return ones * 1 + twos * 2 + threes * 3 + fours * 4 + fives * 5 + sixes * 6;
}

int scoreOnes(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return ones * 1;

}

int scoreTwos(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return twos * 2;
}

int scoreThrees(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return threes * 3;
}

int scoreFours(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return fours * 4;
}

int scoreFives(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return fives * 5 ;
}

int scoreSixes(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return sixes * 6;
}

int scoreThreeOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes){
    if (ones >= 3 || twos >= 3 || threes >= 3 || fours >= 3 || fives >= 3 || sixes >= 3)

        return sumOfDice(ones, twos, threes, fours, fives, sixes);
    else
        return 0;
        return -1;
}

int scoreFourOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes)
{
  if (ones >= 4 || twos >= 4 || threes >= 4 || fours >= 4 || fives >= 4 || sixes >= 4)
        return sumOfDice(ones, twos, threes, fours, fives, sixes);
  else
        return 0;
        return -1;
}



int scoreFullHouse(int ones, int twos, int threes, int fours, int fives, int sixes)
{
  if (((ones == 3 || twos == 3 || threes == 3 || fours == 3 || fives == 3 || sixes == 3) && (ones == 2 || twos == 2 || threes == 2 || fours == 2 || fives == 2 || sixes == 2)) || ones == 5 || twos == 5 || threes == 5 || fours == 5 || fives == 5 || sixes == 5)
    return fullHousePoints;
  else
    return 0;
  return -1;
}


int scoreSmallStraight(int ones, int twos, int threes, int fours, int fives, int sixes)
{
  if ((ones == 1 && twos == 1 && threes == 1 && fours == 1) || (twos == 1 && threes == 1 && fours == 1 && fives == 1) || (threes == 1 && fours == 1 && fives == 1 && sixes == 1))
    return smallStraightPoints;
  else
    return 0;
  return -1;
}


int scoreLargeStraight(int ones, int twos, int threes, int fours, int fives, int sixes)
{
  if ((ones == 1 && twos == 1 && threes == 1 && fours == 1 && fives == 1) || (twos == 1 && threes == 1 && fours == 1 && fives == 1 && sixes == 1))
    return largeStraightPoints;
  else
    return 0;
  return -1;
}

int scoreYahtzee(int ones, int twos, int threes, int fours, int fives, int sixes)
{
  if (ones == 5 || twos == 5 || threes == 5 || fours == 5 || fives == 5 || sixes == 5)
    return yahtzeePoints;
  else
    return 0;
  return -1;
}

int scoreChance(int ones, int twos, int threes, int fours, int fives, int sixes)
{
  return sumOfDice(ones, twos, threes, fours, fives, sixes);
}


#endif // SCORING_H_INCLUDED
