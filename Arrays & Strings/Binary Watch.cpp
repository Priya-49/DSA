/*
Problem: 401. Binary Watch

A binary watch has 4 LEDs for hours (0-11) and 6 LEDs for minutes (0-59). 
Each LED represents a binary digit (1 = on, 0 = off). 

Given an integer turnedOn representing the number of LEDs currently on, 
return all possible times the watch could represent.

Output format:
- "H:MM" (hours without leading zeros, minutes always 2 digits)

Example:
Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32",
         "1:00","2:00","4:00","8:00"]

Approach:
1. Iterate through all possible hours (0-11) and minutes (0-59).
2. Count the number of 1 bits using __builtin_popcount.
3. If the total equals turnedOn, add formatted time string to result.

Time Complexity: O(12*60) = O(720) ≈ O(1)
Space Complexity: O(1) extra (apart from result vector)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> r;
        for (int h = 0; h < 12; h++) {        // hours 0-11
            for (int m = 0; m < 60; m++) {    // minutes 0-59
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    // Format time string: hours without leading zero, minutes always 2 digits
                    string s = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
                    r.push_back(s);
                }
            }
        }
        return r;
    }
};

