/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1)
        {
            return n;
        }
        
        int res = 1;
        int begin = 0;
        int end = 1;
        
        while (end < n)
        {
            bool dup = false;
            int k = begin;
            for ( ; k < end; k++)
            {
                if (s[k] == s[end])
                {
                    dup = true;
                    break;
                }
            }
            
            if (dup)
            {
                if (end - begin > res)
                {
                    res = end - begin;
                }
                begin = k + 1;
            }
            end++;
        }
        
        if (end - begin > res)
        {
            res = end - begin;
        }
        return res;
    }
};
