/*
Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mci;
        for (int i = 0; i < magazine.size(); i++)
        {
            if (mci.find(magazine[i]) == mci.end())
            {
                mci.insert(pair<char, int> (magazine[i], 1));
            }
            else
            {
                mci[magazine[i]]++;
            }
        }
        
        for (int i = 0; i < ransomNote.size(); i++)
        {
            if ((mci.find(ransomNote[i]) == mci.end()) || (mci[ransomNote[i]] == 0))
            {
                return false;
            }
            else
            {
                mci[ransomNote[i]]--;
            }
        }
        return true;
    }
};
