/*
Problem Statement:
------------------
Given a binary array nums and an integer g, return the number of non-empty subarrays 
that have a sum equal to g.

Example:
Input: nums = [1,0,1,0,1], g = 2
Output: 4
Explanation: The subarrays with sum 2 are: [1,0,1], [1,0,1], [0,1,0,1], [1,0,1]

Approach 1:
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


Approach 2:
---------
1. The problem is to count subarrays with sum exactly equal to g.
2. We use the sliding window technique but only works for non-negative numbers.
3. Idea: 
   - countSubarray(nums, x) → returns number of subarrays with sum <= x.
   - Then, subarrays with sum == g = countSubarray(nums, g) - countSubarray(nums, g - 1).
4. countSubarray uses a two-pointer sliding window:
   - Expand j (right pointer), keep track of sum.
   - If sum > g, move i (left pointer) until sum <= g.
   - Add (j - i + 1) subarrays ending at j.

Time Complexity:
----------------
- O(N), where N = size of nums.
- Each element is added once and removed once in the sliding window.

Space Complexity:
-----------------
- O(1), only variables are used apart from input.
*/

//Approach 1 code
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

//Approach 2 code
class Solution {
public:
    // Helper function: count number of subarrays with sum <= g
    int countSubarray(vector<int>& nums, int g) {
        int c = 0, i = 0, j, s = 0;
        for (j = 0; j < nums.size(); j++) {
            s += nums[j];
            // Shrink window if sum exceeds g
            while (s > g && i <= j) {
                s -= nums[i++];
            }
            // All subarrays ending at j with sum <= g
            c += (j - i + 1);
        }
        return c;
    }

    // Function: count number of subarrays with sum == g
    int numSubarraysWithSum(vector<int>& nums, int g) {
        if (g == 0) return countSubarray(nums, 0);
        // Subarrays with sum == g = (sum <= g) - (sum <= g-1)
        return countSubarray(nums, g) - countSubarray(nums, g - 1);
    }
};

