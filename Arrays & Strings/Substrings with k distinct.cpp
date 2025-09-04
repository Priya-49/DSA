/*
Problem Statement:
------------------
Given a string s consisting of lowercase letters and an integer k,
count all substrings of s that contain exactly k distinct characters.

Example:
s = "aba", k = 2
Output: 3
Substrings: ["ab", "ba", "aba"]

Approach:
---------
1. Use the sliding window technique with a frequency map to count 
   substrings with at most k distinct characters.
2. countExactlyK(s, k) = countAtMostK(s, k) - countAtMostK(s, k-1)
3. countAtMostK(s, k):
   - Expand the window with right pointer i.
   - Maintain a map of character frequencies in the window.
   - Shrink window from left if map size > k.
   - Add (i - st + 1) to result for substrings ending at i.

Time Complexity: O(n) - each character is added/removed at most once
Space Complexity: O(k) - map stores at most k distinct characters
*/

class Solution {
public:
    // Count substrings with at most k distinct characters
    int atMostK(string &s, int k) {
        unordered_map<char,int> m;
        int st = 0, n = s.length(), res = 0;
        for(int i = 0; i < n; i++) {
            m[s[i]]++;
            while(m.size() > k) {
                m[s[st]]--;
                if(m[s[st]] == 0) m.erase(s[st]);
                st++;
            }
            res += i - st + 1; // all substrings ending at i
        }
        return res;
    }

    // Count substrings with exactly k distinct characters
    int countSubstr(string &s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

