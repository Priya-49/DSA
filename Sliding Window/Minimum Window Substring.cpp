/*
Problem: Minimum Window Substring
--------------------------------
Given two strings s and t, return the minimum window substring of s such that 
every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

Example:
---------
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Approach:
---------
1. Count the frequency of each character in t using a hash map.
2. Use two pointers (i and j) to represent a sliding window in s.
3. Expand the right pointer (j) and decrease the counts of characters in the map.
   - If a character's count reaches 0, it means that character requirement is satisfied.
4. When all distinct characters are satisfied (c == 0):
   - Try to shrink the window from the left (i).
   - Update the minimum length substring whenever a smaller valid window is found.
   - If shrinking breaks a requirement, increment c again and stop shrinking.
5. Continue this until the end of s.
6. Return the smallest window found.

Time Complexity:
----------------
O(n + m), where n = length of s, m = length of t
- We traverse s once, and map operations are O(1) on average.

Space Complexity:
-----------------
O(k), where k = number of unique characters in t
- The hash map stores frequency counts for t’s characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Step 1: Build frequency map for characters in t
        unordered_map<char,int> m;
        for(char ch : t) {
            m[ch]++;
        }

        int c = m.size();   // number of distinct characters still unmet
        int i = 0;          // left pointer of the sliding window
        int r = INT_MAX;    // length of the smallest window found
        int st = 0;         // starting index of the smallest window

        // Step 2: Expand the window with right pointer j
        for(int j = 0; j < s.length(); j++) {
            // Decrease count of current char in map
            m[s[j]]--;

            // If requirement for this char is satisfied, decrease c
            if(m[s[j]] == 0) c--;

            // Step 3: When all requirements met (c == 0), try shrinking
            if(c == 0) {
                while(c == 0) {
                    // Update minimum window if smaller one found
                    if(j - i + 1 < r) {
                        st = i;
                        r = j - i + 1;
                    }

                    // Try to remove s[i] from the window
                    if(m.find(s[i]) != m.end()) {
                        if(m[s[i]] == 0) c++;  // requirement breaks
                        m[s[i]]++;             // restore count
                    }
                    i++;  // move left pointer forward
                }
            }
        }

        // Step 4: Return the result
        return r == INT_MAX ? "" : s.substr(st, r);
    }
};

