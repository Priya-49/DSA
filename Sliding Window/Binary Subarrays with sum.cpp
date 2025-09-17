/*
Problem Statement:
------------------
Given a binary array nums and an integer g, return the number of non-empty subarrays 
that have a sum equal to g.

Example:
Input: nums = [1,0,1,0,1], g = 2
Output: 4
Explanation: The subarrays with sum 2 are: [1,0,1], [1,0,1], [0,1,0,1], [1,0,1]

Approach:
---------
1. Use a prefix sum approach with a hash map to store counts of prefix sums.
2. Initialize sum s = 0, count c = 0, and unordered_map m with m[0] = 1.
3. Traverse the array:
   a. Add current element to s (prefix sum).
   b. If (s - g) exists in the map, increment count by m[s-g].
   c. Increment m[s] to record current prefix sum frequency.
4. Return count.

Time Complexity: O(n)
- We traverse the array once and map operations are O(1) on average.

Space Complexity: O(n)
- In worst case, the unordered_map stores n different prefix sums.
*/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int g) {
        int s = 0, c = 0; // prefix sum and count of subarrays
        unordered_map<int,int> m;
        m[0] = 1; // base case: sum 0 occurs once
        
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i]; // update prefix sum
            if(m.count(s - g)) {
                c += m[s - g]; // add subarrays ending at i with sum g
            }
            m[s]++; // increment prefix sum frequency
        }
        
        return c;
    }
};

