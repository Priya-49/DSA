/*
Problem: Power Set (All Possible Subsequences of a String in lexographical order)

Given a string s of length n, generate all possible subsequences (non-empty) 
of the string in lexicographically sorted order.

Example:
Input: s = "abc"
Output: ["a","ab","abc","ac","b","bc","c"]

------------------------------------------------------------------
Approach:
- Use recursion to explore all subsequences.
- At index i:
    1. Include s[i] → recurse with r+s[i].
    2. Exclude s[i] → recurse without adding.
- Base case: if i == n → push current subsequence into result.
- Finally sort the result to get lexicographic order.
- Note: Problem usually expects non-empty subsequences, so we must remove "" if present.

------------------------------------------------------------------
Time Complexity:
- There are 2^n subsequences (including empty).
- Each subsequence construction takes O(n).
- Sorting subsequences: O(2^n * log(2^n)).
- Total: O(2^n * n + 2^n * log(2^n)).

Space Complexity:
- O(n) recursion depth.
- O(2^n) space for storing all subsequences.

------------------------------------------------------------------
*/


class Solution {
public:
    void func(int i, int n, string &s, string r, vector<string>& str) {
        if (i == n) {
            if (!r.empty())  // avoid empty subsequence
                str.push_back(r);
            return;
        }
        // include current character
        func(i + 1, n, s, r + s[i], str);
        // exclude current character
        func(i + 1, n, s, r, str);
    }

    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        vector<string> str;
        func(0, n, s, "", str);
        sort(str.begin(), str.end());
        return str;
    }
};
