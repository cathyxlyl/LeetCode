/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/


class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        int n = 0;
        
        if (x < 0)
        {
            return false;
        }
        
        while (y > 0)
        {
            n++;
            y = y / 10;
        }
        
        for (int i = 1; i <= n / 2; i++)
        {
            if (getNum(x, i) != getNum(x, n - i + 1))
            {
                return false;
            }
        }
        return true;
    }
    
    int getNum(int x, int k)
    {
        if (k == 1)
        {
            return x % 10;
        }
        
        int t = 1;
        for (int i = 1; i < k; i++)
        {
            t = t * 10;
        }
        return (x / t) % 10;
    }
};
