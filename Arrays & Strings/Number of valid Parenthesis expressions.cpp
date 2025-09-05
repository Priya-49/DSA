/*
LeetCode / Competitive Programming Problem:
-------------------------------------------
Count the number of valid parentheses expressions of given length n.

Problem Statement:
------------------
Given a number n, find the number of valid parentheses expressions of length n.
A valid parentheses expression is one where every opening bracket '(' has a 
corresponding closing bracket ')', and they are correctly nested.

Note:
- If n is odd, no valid parentheses expressions exist.

Example:
---------
Input: n = 4
Output: 2
Explanation: The valid expressions are ()(), (())

------------------------------------------------------------
Approach: Catalan Number
------------------------
- Number of valid parentheses expressions of length n is the Catalan number C_(n/2)
- Formula for Catalan number:
    C_k = (1 / (k + 1)) * nCr(2k, k)
  where k = n/2

- nCr formula (binomial coefficient):
    nCr = n! / (r! * (n-r)!)
  Iteratively, to avoid overflow:
    nCr = Π (n-i)/(i+1) for i = 0 to r-1

Time Complexity: O(n)  (for nCr calculation)
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute nCr (binomial coefficient)
    // Formula: nCr = n! / (r! * (n-r)!)
    // Iterative approach to avoid large factorials:
    // nCr = (n/1) * ((n-1)/2) * ((n-2)/3) * ... * ((n-r+1)/r)
    long long nCr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);    // multiply numerator
            res /= (i + 1);    // divide denominator
        }
        return res;
    }

    // Function to calculate number of valid parentheses expressions
    long long numValidParentheses(int n) {
        if (n % 2 != 0) return 0;  // Odd length can't form valid expression
        int k = n / 2;
        return nCr(n, k) / (k + 1);  // Catalan number C_k
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.numValidParentheses(n) << endl;
    return 0;
}
