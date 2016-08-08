/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.push_back(2147483647);
        nums2.push_back(2147483647);
        int n1 = nums1.size();
        int n2 = nums2.size();
        if ((n1 == 1) && (n2 == 1))
        {
            return (double)0.0;
        }
        
        int s1 = (n1 + n2 - 1) / 2;
        int s2 = (n1 + n2) / 2;
        int i1 = 0;
        int i2 = 0;
        int res = 0;
        int cur = 0;
        
        while (i1 + i2 <= s2)
        {
            if (nums1[i1] <= nums2[i2])
            {
                cur = nums1[i1];
                i1++;
            }
            else
            {
                cur = nums2[i2];
                i2++;
            }
            
            if (i1 + i2 == s1)
            {
                res += cur;
            }
            if (i1 + i2 == s2)
            {
                res += cur;
            }
        }
        
        return (double)1.0 * res / 2;
    }
};
