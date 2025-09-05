/*
    Problem: Check if s2 contains a permutation of s1
    Approach: Sliding Window + Frequency Map
    ------------------------------------------------
    1. Build a frequency map 'm' for all characters in s1.
    2. Use a sliding window of size k = s1.length() on s2.
    3. For each character entering the window:
       - Decrement its count in 'm' if it exists.
       - If its count reaches zero, decrement 'c' (number of unique chars left to match).
    4. When window size hits k:
       - If c == 0, all characters matched → return true.
       - Otherwise, remove the char leaving the window from the map:
           - If count was zero, increment c.
           - Increment its count in the map.
    5. Slide the window forward.
    6. If no permutation is found, return false.

    Time Complexity: O(n) 
    Space Complexity: O(k) for the map
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m;  // frequency map of s1
        for(auto ch : s1){
            m[ch]++;
        }

        int i = 0;                   // window start
        int j, n = s2.length();      // window end iterator & length of s2
        int k = s1.length();         // window size = length of s1
        int c = m.size();             // number of unique characters to match

        for(j = 0; j < n; j++){
            char ch = s2[j];          // character entering the window

            // if the entering char is in the map, decrement its count
            if(m.count(ch)){
                m[ch]--;
                if(m[ch] == 0) c--;   // one unique char fully matched
            }

            // When window size reaches k
            if(j - i + 1 == k){        
                if(c == 0) return true; // all chars matched → permutation exists

                char ch = s2[i];        // character leaving the window
                if(m.count(ch)){
                    if(m[ch] == 0) c++; // previously fully matched → now unmatched
                    m[ch]++;             // increment count back
                }
                i++;                     // slide the window forward
            }
        }

        return false;  // no permutation found
    }
};

