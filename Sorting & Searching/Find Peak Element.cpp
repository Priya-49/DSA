/*
Problem Statement:
------------------
A peak element is an element that is strictly greater than its neighbors.
Given an integer array `nums`, find a peak element and return its index.
If the array contains multiple peaks, return the index of any one of them.

Example:
--------
Input: nums = [1,2,3,1]
Output: 2  (nums[2] = 3 is a peak)

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5  (nums[1] = 2 or nums[5] = 6 are peaks)

Constraints:
------------
- nums[i] != nums[i+1] for all valid i
- 1 <= nums.length <= 10^5
- -2^31 <= nums[i] <= 2^31-1

Approach:
---------
- A peak can exist at the edges or somewhere in the middle.
- First, check edge cases:
    - If n == 1, return 0 (only one element).
    - If nums[0] > nums[1], then index 0 is a peak.
    - If nums[n-1] > nums[n-2], then index n-1 is a peak.
- Otherwise, apply Binary Search between indices [1 ... n-2]:
    - If nums[m] > nums[m-1] && nums[m] > nums[m+1], return m (peak found).
    - If nums[m+1] > nums[m-1], then a peak lies on the right half → l = m+1.
    - Otherwise, a peak lies on the left half → h = m-1.
- If no peak is found (shouldn’t happen), return -1.

Time Complexity:
----------------
- O(log n), since we use binary search.

Space Complexity:
-----------------
- O(1), constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 1 || nums[0] > nums[1]) 
            return 0;
        if (nums[n-1] > nums[n-2]) 
            return n-1;
        
        int l = 1, h = n - 2, m;
        while (l <= h) {
            m = l + (h - l) / 2;
            
            if (nums[m] > nums[m-1] && nums[m] > nums[m+1])
                return m;
            
            if (nums[m+1] > nums[m-1])
                l = m + 1;
            else
                h = m - 1;   
        }
        return -1; // fallback, though problem guarantees a peak exists
    }
};
