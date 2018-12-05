// Dylan
int scoreFullHouse(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    if ( ((helperOfAKind(3, ones = ones))
                and (helperOfAKind(2, ones - 3, twos, threes, fours, fives, sixes)))
        or ((helperOfAKind(3, twos = twos))
            and (helperOfAKind(2, ones, twos - 3, threes, fours, fives, sixes)))
        or ((helperOfAKind(3, threes = threes))
            and (helperOfAKind(2, ones, twos, threes - 3, fours, fives, sixes)))
        or ((helperOfAKind(3, fours = fours))
            and (helperOfAKind(2, ones, twos, threes, fours - 3, fives, sixes)))
        or ((helperOfAKind(3, fives = fives))
            and (helperOfAKind(2, ones, twos, threes, fours, fives - 3, sixes)))
        or ((helperOfAKind(3, sixes = sixes))
            and (helperOfAKind(2, ones, twos, threes, fours, fives, sixes - 3))) )
    {
        return SCORE_FULL_HOUSE;
    }
    return 0;
}

