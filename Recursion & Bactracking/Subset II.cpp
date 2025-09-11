/*
90. Subsets II
---------------------------------

Problem Statement:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

------------------------------------------------
Example:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

------------------------------------------------
Approach:
- Sort the array to bring duplicates together.
- Use backtracking:
  - At each index, we have 2 choices:
    1) Include nums[i] in the current subset
    2) Skip nums[i] and all its duplicates (to avoid duplicate subsets)
- Recursively build subsets and store results.

------------------------------------------------
Time Complexity:
- O(2^n) → each element can be included/excluded
- Sorting adds O(n log n)
- Overall: O(n log n + 2^n)

Space Complexity:
- O(n) → recursion stack and temporary subset storage

------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getUniqueSubsets(vector<int>& nums, vector<int>& current, vector<vector<int>>& res, int i) {
        int n = nums.size();
        if (i == n) {
            res.push_back(current);
            return;
        }

        // Include nums[i]
        current.push_back(nums[i]);
        getUniqueSubsets(nums, current, res, i + 1);
        current.pop_back();

        // Skip duplicates
        int idx = i + 1;
        while (idx < n && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        getUniqueSubsets(nums, current, res, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to group duplicates
        vector<vector<int>> res;
        vector<int> current;
        getUniqueSubsets(nums, current, res, 0);
        return res;
    }
};
