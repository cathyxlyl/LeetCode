/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/


class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        if (n == 0)
            return 0;
        
        int res = 0;    
        int i = 0;
        int sgn = 1;
        bool begin = false;
        while (i < n)
        {
            if (!begin)
            {
                if (str[i] == ' ')
                {
                    i++;
                    continue;
                }
                if (str[i] == '+')
                {
                    sgn = 1;
                    begin = true;
                    i++;
                    continue;
                }
                if (str[i] == '-')
                {
                    sgn = -1;
                    begin = true;
                    i++;
                    continue;
                }
                if (isdigit(str[i]))
                {
                    begin = true;
                }
                else
                {
                    return 0;
                }
            }
            
            if (!isdigit(str[i]))
            {
                return sgn * res;
            }
            int nd = int(str[i] - '0');
            if ((sgn == 1) && ((res >= 214748365) || ((res >= 214748364) && (nd >= 8))))
            {
                return 2147483647;
            }
            if ((sgn == -1) && ((res >= 214748365) || ((res >= 214748364) && (nd >= 9))))
            {
                return -2147483648;
            }
            res = (res * 10) + int(str[i] - '0');
            i++;
        }
        return sgn * res;
    }
};
