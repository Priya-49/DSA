/*
Problem Statement:
Given an array of integers nums and an integer k, 
return the total number of subarrays whose sum equals k.

Example:
Input: nums = [1,2,3], k = 3
Output: 2
Explanation: The subarrays are [1,2] and [3].

Approach:
- Use a HashMap (unordered_map) to store the prefix sum and its frequency.
- Traverse the array while maintaining the cumulative sum `s`.
- For each element, check if `(s - k)` exists in the map.
  -> If it does, it means there is a subarray ending at the current index with sum k.
- Increase the count by the frequency of `(s - k)`.
- Store/update the current prefix sum `s` in the map.

Time Complexity: O(n)   (single pass over the array)
Space Complexity: O(n)  (for the hashmap storing prefix sums)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i, s = 0, n = nums.size(), c = 0;
        unordered_map<int, int> m;
        m[s] = 1;  // prefix sum 0 initially present once

        for(i = 0; i < n; i++) {
            s += nums[i];
            if(m.find(s - k) != m.end()) 
                c += m[s - k]; // subarrays found
            
            m[s]++;  // update prefix sum count
        }
        return c;
    }
};
