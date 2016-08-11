/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
        {
            return 0;
        }
        if (haystack == "")
        {
            return -1;
        }
        
        int res = -1;
        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        
        while (i <= n - m)
        {
            if (needle[0] == haystack[i])
            {
                res = i;
                int j = 0;
                while ((j < m) && (needle[j] == haystack[j + i]))
                {
                    j++;
                }
                if (j == m)
                {
                    return res;
                }
                res = -1;
            }
            i++;
        }
        return res;
    }
};
