/*
Problem Statement:
------------------
Given two strings `p` (pattern) and `t` (text), count the number of substrings 
in `t` that are anagrams of `p`.

Example:
Input: p = "ab", t = "abxaba"
Output: 3
Explanation: The substrings are "ab", "ba", "ab".

Approach:
---------
1. Use a sliding window of size equal to pattern length `k`.
2. Use an unordered_map to store the frequency of characters in pattern `p`.
3. Initialize a count `c` as the number of distinct characters in the map.
4. Move the window over `t`:
   - If the current character is in the map, decrease its frequency. If it becomes 0, decrement `c`.
   - When the window size equals `k`, check if `c == 0`, which means the substring is an anagram.
   - Before sliding the window, restore the frequency of the character going out and adjust `c` if needed.
5. Continue until the end of `t`.

Time Complexity: O(n + k)
------------------------
- Building the map takes O(k), and each character in `t` is processed at most twice.
- So overall time is linear.

Space Complexity: O(1)
----------------------
- The unordered_map contains at most 26 characters (assuming lowercase letters), so constant space.

*/


class Solution {
public:
    int search(string &p, string &t) {
        int n = t.length(), k = p.length(), i = 0, j = 0, c = 0, r = 0;
        unordered_map<char, int> m;
        
        // Build frequency map of pattern
        for (i = 0; i < k; i++) {
            m[p[i]]++;
        }
        c = m.size(); // number of distinct characters to match
        i = 0;
        
        // Sliding window over text
        while (j < n) {
            if (m.find(t[j]) != m.end()) {
                m[t[j]]--;
                if (m[t[j]] == 0)
                    c--;
            }
            
            if (j - i + 1 == k) { // window size reached
                if (c == 0)
                    r++; // found an anagram
                
                // Remove the character going out of window
                if (m.find(t[i]) != m.end()) {
                    if (m[t[i]] == 0)
                        c++;
                    m[t[i]]++;
                }
                i++;
            }
            j++;
        }
        return r;
    }
};

