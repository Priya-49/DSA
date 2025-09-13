/*
Problem Statement:(Leetcode 1423)
------------------
You are given an integer array 'c' and an integer 'k'. 
You can choose k cards from the beginning or the end of the array. 
Your task is to maximize the sum of the chosen cards.

Example 1:
----------
Input: c = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: Choose 1 card from the end (1) and 2 cards from the beginning (5,6).
Total = 6 + 5 + 1 = 12

Example 2:
----------
Input: c = [2,2,2], k = 2
Output: 4
Explanation: Pick the first two cards.

----------------------------------------------------
Approach (Sliding Window):
--------------------------
1. Compute the sum of the first k cards (initial window).
2. Iteratively, remove one card from the left side of this window 
   and add one card from the right end of the array.
3. Keep track of the maximum sum obtained during this process.

Time Complexity: O(k)
Space Complexity: O(1)
*/


class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();
        // initial sum: first k elements
        int s = accumulate(c.begin(), c.begin() + k, 0);
        int ms = s;  // max sum

        // slide window: remove from front, add from back
        for (int i = 0; i < k; i++) {
            s -= c[k - i - 1];   // remove from left part
            s += c[n - i - 1];   // add from right part
            ms = max(ms, s);
        }
        return ms;
    }
};

