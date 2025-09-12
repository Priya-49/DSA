/*
Leetcode 139 
You are given a string s and a dictionary of words wordDict.
Return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Example:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: "applepenapple" can be segmented as "apple pen apple".

------------------------------------------------------------------
Approach 1: Recursion (Backtracking)
- Start from index 0, try all possible substrings.
- If substring is in dictionary, recursively check for the remaining string.
- If we reach the end of string successfully, return true.
- Otherwise, try next possibility.
- Base case: if current index == length of string, return true.

Time Complexity: O(2^n) 
(Every index can branch into including/excluding dictionary word, leads to exponential growth)

Space Complexity: O(n) 
(Recursion stack in worst case is depth of string length)

output:TLE
------------------------------------------------------------------
*/

class Solution {
public:
    bool check(string &s, unordered_set<string>&dict, int st){
        if(st==s.length()) return true;
        for(int end=st;end<s.length();end++){
            string w=s.substr(st,end-st+1);
            if(dict.find(w)!=dict.end()){
                if(check(s,dict,end+1))
                    return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        return check(s,dict,0);
    }
};
