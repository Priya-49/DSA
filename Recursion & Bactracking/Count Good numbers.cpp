/*
Leetcode - 1922. Count Good Numbers
---------------------------------

Problem Statement:
A digit string is called "good" if the digits at even indices are even 
and the digits at odd indices are prime (indices are 0-based).

- Even indices (0, 2, 4, ...): can only take digits {0, 2, 4, 6, 8} → 5 options.
- Odd indices (1, 3, 5, ...): can only take digits {2, 3, 5, 7} → 4 options.

Given a positive integer n, return the total number of good digit strings 
of length n. Since the answer may be large, return it modulo 1e9+7.

------------------------------------------------
Example:
Input: n = 1
Output: 5
Explanation: The only index 0 is even, so it can be one of 5 even digits.

Input: n = 4
Output: 400
Explanation: 
- Even indices → 2 positions → 5^2 = 25
- Odd indices → 2 positions → 4^2 = 16
- Total = 25 * 16 = 400

------------------------------------------------
Approach:
- For n digits:
  - Count even indices: (n + 1) / 2
  - Count odd indices: n / 2
- Total good strings = (5^(even_count) * 4^(odd_count)) % MOD
- Since n can be very large (up to 10^15), 
  we need fast exponentiation (binary exponentiation).

------------------------------------------------
Time Complexity:
- O(log n) → for modular exponentiation

Space Complexity:
- O(1) → only a few variables

------------------------------------------------
*/


class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation
    ll modPow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        ll even = (n + 1) / 2;  // count of even indices
        ll odd = n / 2;         // count of odd indices

        ll part1 = modPow(5, even);  // choices for even positions
        ll part2 = modPow(4, odd);   // choices for odd positions

        return (int)((part1 * part2) % MOD);
    }
};

