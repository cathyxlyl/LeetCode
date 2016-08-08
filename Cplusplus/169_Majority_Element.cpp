/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        hash_map<int, int> sta;
        vector<int>::iterator it;
        int n = 0;
        int res = nums[0];
        
        for (it = nums.begin(); it != nums.end(); it++)
        {
            if (sta.find(*it) == sta.end())
            {
                sta.insert(hash_map<int, int>::value_type(*it, 1));
            }
            else
            {
                sta[*it]++;
            }
            
            n++;
            if (sta[*it] > n / 2)
            {
                res = *it;
            }
        }
        return res;
    }
};
