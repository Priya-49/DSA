/*
Problem: Find First and Last Position of Element in Sorted Array
LeetCode 34

Given an array of integers nums sorted in non-decreasing order, 
and a target value t, return the starting and ending position 
of t in nums. If t is not found, return [-1, -1].

Example:
Input: nums = [5,7,7,8,8,10], t = 8
Output: [3,4]

----------------------------------------------------------
Approach 1 (Binary Search - Optimal):
- Perform binary search twice:
  1. Once to find the first occurrence of target.
  2. Once to find the last occurrence of target.
- Modify binary search:
   * If nums[m] == target → store index.
     - For first occurrence → move left (e = m - 1).
     - For last occurrence → move right (s = m + 1).
   * If nums[m] < target → search right.
   * If nums[m] > target → search left.

Time Complexity: O(log n)   (binary search runs twice)
Space Complexity: O(1)      (only variables used)
----------------------------------------------------------
*/


class Solution {
public:
    // Modified Binary Search
    int bs(vector<int>& nums, int s, int e, int t, bool left) {
        int ans = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (t == nums[m]) {
                ans = m;
                if (left) 
                    e = m - 1; // go left
                else 
                    s = m + 1; // go right
            } 
            else if (nums[m] > t) {
                e = m - 1;
            } 
            else {
                s = m + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();
        int first = bs(nums, 0, n - 1, t, true);   // first occurrence
        int last  = bs(nums, 0, n - 1, t, false);  // last occurrence
        return {first, last};
    }
};
