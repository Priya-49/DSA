/*
Problem: Find Minimum in Rotated Sorted Array
LeetCode 153

Given a rotated sorted array nums of unique elements, return the minimum element.

Example:
Input: nums = [4,5,6,7,0,1,2]
Output: 0

Approach (Binary Search):
-------------------------
- Initialize l = 0, h = n - 1, res = INT_MAX
- While l <= h:
    1. Find mid m = l + (h-l)/2
    2. If left half is sorted (nums[l] <= nums[m]):
         - Minimum could be nums[l]
         - Move to right half: l = m + 1
    3. Else (left half unsorted):
         - Minimum is in left half: res = min(res, nums[m])
         - Move to left: h = m - 1
- Return res

Time Complexity: O(log n) - binary search
Space Complexity: O(1) - constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int m, res = INT_MAX;
        
        while (l <= h) {
            m = l + (h - l) / 2;
            if (nums[l] <= nums[m]) {
                res = min(res, nums[l]);
                l = m + 1;
            } else {
                res = min(res, nums[m]);
                h = m - 1;
            }
        }
        return res;
    }
};
