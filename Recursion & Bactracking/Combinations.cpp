/*
Problem: Combinations (LeetCode 77)

Given two integers n and k, return all possible combinations of k numbers 
chosen from the range [1, n].

Example:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

------------------------------------------------------------------
Approach:
- Use recursion + backtracking.
- At each step, decide whether to include the current number `i` or skip it.
- Parameters:
    i = current number to consider
    n = remaining numbers to choose from
    k = target size of each combination
    a = current combination
    r = result list
- Base cases:
    1. If a.size() == k → valid combination → add to result.
    2. If a.size() + n < k → not enough numbers left → prune search.
- Otherwise:
    - Include i → recurse with i+1
    - Exclude i → recurse with i+1
- Backtracking ensures state is restored after each choice.

------------------------------------------------------------------
Time Complexity:
- O(C(n, k)) combinations are generated.
- Each combination takes O(k) to build.
- Overall complexity: O(C(n, k) * k).

Space Complexity:
- O(k) recursion depth.
- O(C(n, k) * k) space for storing results.

------------------------------------------------------------------
*/

class Solution {
public:
    void comb(int i, int n, int k, vector<int>& a, vector<vector<int>>& r) {
        if (a.size() == k) {
            r.push_back(a);
            return;
        }
        if (a.size() + n < k) return; // not enough numbers left

        // include current number
        a.push_back(i);
        comb(i + 1, n - 1, k, a, r);
        a.pop_back();

        // exclude current number
        comb(i + 1, n - 1, k, a, r);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> r;
        vector<int> a;
        comb(1, n, k, a, r);
        return r;
    }
};
