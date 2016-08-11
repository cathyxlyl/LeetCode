/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
*/


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int MAX_INT = 2147483647;
    
    int guessNumber(int n) {
        if (guess(MAX_INT) == 0)
        {
            return MAX_INT;
        }
        
        int low = 1;
        int high = n;
        int gn = guess(getMedium(low, high));
        while (gn != 0)
        {
            if (gn == 1)
            {
                low = getMedium(low, high) + 1;
            }
            else if (gn == -1)
            {
                high = getMedium(low, high) - 1;
            }
            gn = guess(getMedium(low, high));
        }
        return getMedium(low, high);
    }
    
    int getMedium(int low, int high)
    {
        if (MAX_INT - low >= high)
        {
            return (low + high) / 2;
        }
        else
        {
            high = high - MAX_INT / 2;
            low = low - MAX_INT / 2;
            return (low + high) / 2 + MAX_INT / 2;
        }
    }
};
