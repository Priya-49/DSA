/*
Problem Statement: (Leetcode 3)
------------------
Given a string s, find the length of the longest substring 
without repeating characters.

Examples:
---------
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with length = 3.

Input: s = "abba"
Output: 2
Explanation: The longest substrings without repeating characters are "ab" and "ba".

----------------------------------------------------
Approach 1: Index Map (Optimal Sliding Window)
----------------------------------------------
1. Use an unordered_map (or array) to store the last seen index of each character.
2. Traverse with pointer j (end of window).
3. If s[j] was seen before and its last index >= i (start of window),
   move i to that last index + 1 (jump left pointer directly).
4. Update max length as (j - i + 1).

Time Complexity: O(n)
Space Complexity: O(min(n, charset)) 

----------------------------------------------------
Approach 2: Frequency Map (Shrink Window)
-----------------------------------------
1. Use an unordered_map to store the frequency of characters in the window.
2. Expand window with j (right pointer).
3. If all characters are unique (map size == window length),
   update max length.
4. Otherwise, shrink the window from left (i++) until unique again.

Time Complexity: O(n)
Space Complexity: O(min(n, charset))

Note:
- Approach 1 is slightly faster in practice since it jumps i directly,
  while Approach 2 shrinks step by step.
*/


class Solution {
public:
    // Approach 1: Index Map
    int lengthOfLongestSubstring_IndexMap(string s) {
        unordered_map<char,int> m; 
        int i = 0, ml = 0;
        for(int j = 0; j < s.size(); j++) {
            if(m.count(s[j]) && m[s[j]] >= i) {
                // duplicate found inside window → jump i
                i = m[s[j]] + 1;
            }
            m[s[j]] = j; // update last seen index
            ml = max(ml, j - i + 1);
        }
        return ml;
    }

    // Approach 2: Frequency Map
    int lengthOfLongestSubstring_FreqMap(string s) {
        unordered_map<char,int> m;
        int i = 0, ml = 0;
        for(int j = 0; j < s.size(); j++) {
            m[s[j]]++; // expand window
            if(m.size() == j - i + 1) {
                // window is unique
                ml = max(ml, j - i + 1);
            } else {
                // duplicate exists → shrink window
                while(m.size() < j - i + 1) {
                    m[s[i]]--;
                    if(m[s[i]] == 0) m.erase(s[i]);
                    i++;
                }
            }
        }
        return ml;
    }
};

