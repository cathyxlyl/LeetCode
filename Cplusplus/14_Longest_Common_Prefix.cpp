/*
Write a function to find the longest common prefix string amongst an array of strings.
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        if (n == 0)
        {
            return res;
        }
        if (n == 1)
        {
            return strs[0];
        }
        
        bool finish = false;
        for (int i = 0; i < strs[0].size(); i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j].size() < i + 1)
                {
                    finish = true;
                    break;
                }
                if (strs[j][i] != c)
                {
                    finish = true;
                    break;
                }
            }
            
            if (finish)
            {
                break;
            }
            res += c;
        }
        return res;
    }
};
