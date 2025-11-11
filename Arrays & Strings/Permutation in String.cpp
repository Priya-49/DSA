/*
Problem: Leetcode 567
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Approach: Sliding Window + Frequency Array
------------------------------------------------
1. Build a frequency array 'freq' of size 26 for all characters in s1.
2. Use a sliding window of size k = s1.length() on s2.
3. For each character entering the window:
   - If freq[char] > 0, decrement the count of characters left to match 'c'.
   - Decrement freq[char] in the array.
4. When window size reaches k:
   - If c == 0, all characters matched → return true.
   - Otherwise, remove the character leaving the window:
       - If freq[char] >= 0, increment c.
       - Increment freq[char] back in the array.
5. Slide the window forward.
6. If no permutation is found, return false.

Note: Since strings contain only lowercase letters, we are using a fixed array of size 26 
      instead of a map for efficiency (faster and less memory usage).
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length(), k = s1.length();
        if (k > n) return false;

        int freq[26] = {0}; // frequency of characters in s1
        for (int i = 0; i < k; i++) {
            freq[s1[i] - 'a']++;
        }

        int c = k;  // number of characters left to match
        int i = 0;  // window start

        for (int j = 0; j < n; j++) {
            // character entering the window
            if (freq[s2[j] - 'a'] > 0) c--;
            freq[s2[j] - 'a']--;

            // when window size reaches k
            if (j - i + 1 == k) {
                if (c == 0) return true; // permutation found

                // character leaving the window
                if (freq[s2[i] - 'a'] >= 0) c++;
                freq[s2[i] - 'a']++;
                i++; // slide window forward
            }
        }

        return false; // no permutation found
    }
};
