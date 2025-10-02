/*
Problem Statement:
------------------
Given a rotated sorted array that may contain duplicates, find the minimum element in the array.

A rotated sorted array is originally sorted in ascending order, but then rotated at some pivot point.
For example: [2,2,2,0,1] is a rotated version of [0,1,2,2,2].

You need to return the minimum element present in the array.

Approach:
---------
- We use a modified Binary Search to efficiently find the minimum element.
- Initialize two pointers: l = 0, h = n-1 and a variable res = INT_MAX to store the minimum.
- While l <= h:
    1. Find the middle index m = l + (h-l)/2.
    2. If nums[l], nums[m], and nums[h] are all equal, shrink the search space by moving l++ and h-- 
       (to handle duplicates).
    3. If left half [l...m] is sorted, the minimum lies in nums[l], update res, and move search to right half.
    4. Otherwise, the right half is sorted, so update res with nums[m] and move search to left half.
- Continue until search space is exhausted.
- Return res.

Time Complexity:
----------------
- O(log n) in the average case (binary search).
- O(n) in the worst case when many duplicates are present (because of linear shrinking of the window).

Space Complexity:
-----------------
- O(1), since only constant extra space is used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, h = n - 1, m, res = INT_MAX;
        while (l <= h) {
            m = l + (h - l) / 2;
            
            // Handle duplicates
            if (nums[l] == nums[m] && nums[m] == nums[h]) {
                while (l < h && nums[l] == nums[m] && nums[m] == nums[h]) {
                    l++;
                    h--;
                }
            }

            // Left half is sorted
            if (nums[l] <= nums[m]) {
                res = min(res, nums[l]);
                l = m + 1;
            } 
            // Right half is sorted
            else {
                res = min(res, nums[m]);
                h = m - 1;
            }
        }
        return res;
    }
};
