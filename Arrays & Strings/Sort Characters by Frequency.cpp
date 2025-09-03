/*
LeetCode: Sort Characters By Frequency
-------------------------------------
Problem Statement:
Given a string s, sort it in decreasing order based on the frequency of characters.
Return the sorted string.

Approach 1: HashMap + Sorting (Optimal)
---------------------------------------
- Count the frequency of each character using an unordered_map.
- Store the frequencies as pairs (frequency, character) in a vector.
- Sort the vector in descending order of frequency.
- Build the result string by repeating each character frequency times.

Time Complexity: O(n log n) (sorting)
Space Complexity: O(n)

*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(char ch:s){
            m[ch]++;
        }
        vector<pair<int,char>>v;
        for(auto i:m){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string r="";
        for(auto &[freq,ch]:v){
           r+=string(freq,ch);
        }
        return r;

    }
};