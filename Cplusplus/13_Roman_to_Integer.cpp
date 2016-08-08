/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int res = 0;
        map<char, int> mt;
        mt.insert(pair<char, int> ('I', 1));
        mt.insert(pair<char, int> ('V', 5));
        mt.insert(pair<char, int> ('X', 10));
        mt.insert(pair<char, int> ('L', 50));
        mt.insert(pair<char, int> ('C', 100));
        mt.insert(pair<char, int> ('D', 500));
        mt.insert(pair<char, int> ('M', 1000));
        int cur = 1;
        
        for (int i = n - 1; i >= 0; i--)
        {
            int t = mt[s[i]];
            if (t == cur)
            {
                res += t;
            }
            if (t > cur)
            {
                res += t;
                cur = t;
            }
            if (t < cur)
            {
                res -= t;
            }
        }
        return res;
    }
};
