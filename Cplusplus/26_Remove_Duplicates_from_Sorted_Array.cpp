/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/


//Solution 1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        vector<int>::iterator it = nums.begin();
        int m = *it;
        int count = 1;
        it++;
        
        vector<int>::iterator cur = it;
        while (it != nums.end())
        {
            if (*it != m)
            {
                m = *it;
                *cur = m;
                cur++;
                count++;
            }
            it++;
        }
        return count;
    }
};


//Solution 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        vector<int>::iterator it = nums.begin();
        int m = *it;
        int count = 1;
        it++;
        
        while (it != nums.end())
        {
            if (*it != m)
            {
                count++;
                m = *it;
                it++;
            }
            else
            {
                nums.erase(it);
            }
        }
        return count;
    }
};


