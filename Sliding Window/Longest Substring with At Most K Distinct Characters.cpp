/*
Problem Statement: (Code360 by codingninjas)
------------------
Given a string 's' and an integer 'k', find the length of the longest substring
that contains at most 'k' distinct characters.

Example:
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

Approach:
---------
This problem can be solved using the sliding window technique:

1. Use two pointers 'i' (start of window) and 'j' (end of window) to maintain a window.
2. Use an unordered_map to count characters in the current window.
3. When adding a new character causes the number of distinct characters to exceed 'k',
   shrink the window from the left until the window contains at most 'k' distinct characters.
4. Update the maximum length of the valid window at each step.

Time Complexity:
----------------
O(n) - Each character is processed at most twice (once when added, once when removed).

Space Complexity:
-----------------
O(k) - The unordered_map stores at most 'k' distinct characters.

*/


int kDistinctChars(int k, std::string &s)
{
    std::unordered_map<char,int> m;
    int i = 0, ml = 0; // max length initialized to 0

    for (int j = 0; j < s.length(); j++) {
        if (!m.count(s[j])) {
            k--;
        }
        m[s[j]]++;

        // Shrink window if distinct chars > k
        while (k < 0) {
            m[s[i]]--;
            if (m[s[i]] == 0) {
                m.erase(s[i]);
                k++;
            }
            i++;
        }

        ml = std::max(ml, j - i + 1);
    }

    return ml;
}
