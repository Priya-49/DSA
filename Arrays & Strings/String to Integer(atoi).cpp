/*
Problem Statement:
------------------
Implement a function `myAtoi` that converts a string to a 32-bit signed integer (similar to C/C++'s atoi function). 
The function should follow these rules:
1. Read in and ignore any leading whitespace.
2. Check for an optional '+' or '-' sign.
3. Read in the digits until a non-digit character is encountered or the end of the string is reached.
4. Return the integer value. If the value is out of the 32-bit signed integer range, clamp it to INT_MAX (2^31 - 1) or INT_MIN (-2^31).

Example:
Input: "   -42"
Output: -42

Input: "4193 with words"
Output: 4193
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long i = 0, res = 0, n = s.length();
        int sign = 1;

        // 1. Skip leading whitespaces
        while(i < n && s[i] == ' ') i++;

        // 2. Check for sign
        if(i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Process numeric digits
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Check for overflow/underflow
            if(res > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        // 5. Apply sign and return result
        return res * sign;
    }
};

/*
Time Complexity: O(n) 
- We traverse the string once, where n is the length of the input string.

Space Complexity: O(1)
- Only a constant amount of extra space is used (variables i, res, sign, digit).
*/
