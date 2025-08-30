/*
Problem Statement:
------------------
Given an integer array nums and an integer k, return the number of non-empty 
subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:
----------
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [0], [0, -2, -3], [-2, -3], [-3, 1]

----------------------------------------------------------------------
Approach:
---------
1. Use a running sum (prefix sum) to keep track of the cumulative sum.
2. The key observation: If (prefixSum1 % k == prefixSum2 % k), then the subarray between them has a sum divisible by k.
3. Store frequency of each remainder in a hashmap.
4. For each prefix sum:
   - Compute remainder r = sum % k
   - Adjust negative remainder to keep it in range [0, k-1]
   - Add the frequency of remainder r to the count (because that many previous subarrays can form valid subarrays with current sum)
   - Increment the frequency of r in the map.

----------------------------------------------------------------------
Time Complexity: O(n)  
- We iterate through the array once and perform O(1) operations for each element.

Space Complexity: O(k)  
- At most k remainders are stored in the hashmap.

----------------------------------------------------------------------
Code:
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int i, s = 0, c = 0, n = nums.size(), r;
        unordered_map<int, int> m;
        m[s] = 1;  // Initial prefix sum = 0

        for (i = 0; i < n; i++) {
            s += nums[i];
            r = s % k;

            if (r < 0) r += k; // Handle negative remainder

            c += m[r];  // Count subarrays with same remainder
            m[r]++;     // Update frequency
        }
        return c;
    }
};
