/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/


class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> sta;
        map<char, char> mc;
        mc.insert(pair<char, char> (')', '('));
        mc.insert(pair<char, char> (']', '['));
        mc.insert(pair<char, char> ('}', '{'));
         
        for (int i = 0; i < n; i++)
        {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            {
                sta.push(s[i]);
            }
            else if (sta.empty())
            {
                return false;
            }
            else if (sta.top() == mc[s[i]])
            {
                sta.pop();
            }
            else
            {
                return false;
            }
        }
        
        if (!sta.empty())
        {
            return false;
        }
        return true;
    }
};
