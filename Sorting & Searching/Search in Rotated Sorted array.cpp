/*
Problem Statement:
------------------
You are given a rotated sorted array of unique integers `nums` and a target integer `t`.
The array was originally sorted in ascending order, but then rotated at some unknown pivot index.
Return the index of `t` if it is present in `nums`; otherwise, return -1.

Example:
--------
Input: nums = [4,5,6,7,0,1,2], t = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], t = 3
Output: -1

Approach:
---------
- We use a modified binary search approach to locate the target in O(log n) time.
- Initialize two pointers: l = 0, h = n-1.
- While l <= h:
    1. Find the mid index m = l + (h-l)/2.
    2. If nums[m] == t, return m.
    3. If the left half [l...m] is sorted:
         - If t lies in [nums[l], nums[m]), move h = m - 1.
         - Otherwise, move l = m + 1.
    4. Otherwise, the right half [m...h] is sorted:
         - If t lies in (nums[m], nums[h]], move l = m + 1.
         - Otherwise, move h = m - 1.
- If the loop ends, return -1.

Time Complexity:
----------------
- O(log n), since we use binary search.

Space Complexity:
-----------------
- O(1), as no extra space is used apart from variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0, n = nums.size(), h = n - 1, m;
        while (l <= h) {
            m = l + (h - l) / 2;
            
            if (nums[m] == t)
                return m;
            
            // Left half is sorted
            if (nums[l] <= nums[m]) {
                if (nums[l] <= t && t < nums[m])
                    h = m - 1;
                else
                    l = m + 1;
            }
            // Right half is sorted
            else {
                if (nums[m] < t && t <= nums[h])
                    l = m + 1;
                else
                    h = m - 1;
            }
        }
        return -1;
    }
};
