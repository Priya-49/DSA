/*
Problem: Combination Sum (LeetCode 39)

Given an array of distinct integers "candidates" and a target integer "target", 
return a list of all unique combinations of candidates where the chosen numbers sum to "target". 
You may use each number in candidates an unlimited number of times. 
The combinations may be returned in any order.

Example:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

------------------------------------------------------------------
Approach:
- We use recursion + backtracking.
- At each index "i", we have two choices:
    1. Take candidates[i] (stay on same index since reuse allowed).
    2. Skip candidates[i] (move to next index).
- Base cases:
    - If target == 0 → valid combination found → add to result.
    - If target < 0 or index == n → stop exploring.
- This ensures all unique combinations are explored without duplicates.
- Backtracking is used: we push a number, recurse, and then pop it to restore state.

------------------------------------------------------------------
Time Complexity:
- In the worst case, each number can be chosen multiple times up to target/ min(candidates[i]).
- Roughly O(2^(T/min)) where T is target and min is smallest candidate.
- But pruning (when sum exceeds target) reduces practical complexity.

Space Complexity:
- O(T/min) recursion depth (stack space).
- O(T/min) for temporary combination vector.
- Result storage depends on number of valid combinations.

------------------------------------------------------------------
*/

class Solution {
public:
    void dfs(vector<int>& a, int i, int t, vector<int>& r, vector<vector<int>>& ans) {
        // base case: found valid combination
        if (t == 0) {
            ans.push_back(r);
            return;
        }
        // base case: out of bounds or exceeded target
        if (i == a.size() || t < 0) return;

        // choice 1: take current element
        r.push_back(a[i]);
        dfs(a, i, t - a[i], r, ans);   // stay at i since reuse allowed
        r.pop_back();

        // choice 2: skip current element
        dfs(a, i + 1, t, r, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> r;
        dfs(candidates, 0, target, r, ans);
        return ans;
    }
};
