/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

Hint:

Try two pointers.
*/


//Solution 1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
        {
            return 0;
        }
        
        vector<int>::iterator it = nums.begin();
        vector<int>::iterator cur = it;
        int count = 0;
        while (it != nums.end())
        {
            if (*it != val)
            {
                *cur = *it;
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
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
        {
            return 0;
        }
        
        vector<int>::iterator it = nums.begin();
        int count = 0;
        while (it != nums.end())
        {
            if (*it == val)
            {
                nums.erase(it);
            }
            else
            {
                count++;
                it++;
            }
        }
        return count;
    }
};
