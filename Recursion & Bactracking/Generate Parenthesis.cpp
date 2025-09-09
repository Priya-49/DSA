/*
Problem: Generate Parentheses (LeetCode 22)

Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

Example:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

------------------------------------------------------------------
Approach:
- Use recursion + backtracking.
- Keep track of:
    - open = number of '(' left to place
    - close = number of ')' left to place
- Rules:
    - You can place '(' if open > 0
    - You can place ')' if close > open (ensures validity)
- Base case:
    - If open == 0 and close == 0 → valid string formed → add to result.
- This ensures only valid parentheses strings are generated.

------------------------------------------------------------------
Time Complexity:
- The number of valid strings of n pairs = n-th Catalan number ≈ O(4^n / (n * sqrt(n))).
- Each string has length 2n, so total work = O(Cn * 2n), where Cn = Catalan number.

Space Complexity:
- O(2n) recursion depth (stack space).
- O(Cn * 2n) space to store all results.

------------------------------------------------------------------
*/


class Solution {
public:
    void parenthesis(int open, int close, string s, vector<string>& res) {
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        if (open > 0) parenthesis(open - 1, close, s + '(', res);     // place '('
        if (close > open) parenthesis(open, close - 1, s + ')', res); // place ')'
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        parenthesis(n, n, "", res);
        return res;
    }
};
